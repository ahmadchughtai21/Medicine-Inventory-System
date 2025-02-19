#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "head.cpp"

using namespace std;

struct Medicine {
    int id;
    string name;
    double price;
    int quantity;
    string expiryDate;
    Medicine *next;
    Medicine *prev;

    Medicine(int id, string name, double price, int quantity, string expiryDate)
        : id(id), name(name), price(price), quantity(quantity), expiryDate(expiryDate), next(nullptr), prev(nullptr) {}
};

Medicine* head = nullptr;
Medicine* tail = nullptr;
int count = 0;

void deleteAllMedicines() {
    Medicine *current = head;
    while (current != nullptr) {
        Medicine *next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    count = 0;
}

bool isIdUniqueLink(int id) {
    Medicine *current = head;
    while (current != nullptr) {
        if (current->id == id)
            return false;
        current = current->next;
    }
    return true;
}

void addMedicineLink(int id, string name, double price, int quantity, string expiryDate) {
    Medicine *newMedicine = new Medicine(id, name, price, quantity, expiryDate);

    if (head == nullptr) {
        head = tail = newMedicine;
    } else {
        tail->next = newMedicine;
        newMedicine->prev = tail;
        tail = newMedicine;
    }
    count++;

    cout << "Medicine added successfully!" << endl;
}

void searchByNameLink(const string &name) {
    Medicine *current = head;
    bool found = false;

    cout << "\nSearch Results:" << endl;
    printHeaderLink();

    while (current != nullptr) {
        if (current->name == name) {
            printMedicineLink(current);
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        cout << "Medicine with name '" << name << "' not found." << endl;
    }
}

void searchByIdLink(int id) {
    Medicine *current = head;
    bool found = false;

    cout << "\nSearch Results:" << endl;
    printHeaderLink();

    while (current != nullptr) {
        if (current->id == id) {
            printMedicineLink(current);
            found = true;
            break;
        }
        current = current->next;
    }

    if (!found) {
        cout << "Medicine with ID " << id << " not found." << endl;
    }
}

void searchByExpiryDateLink(const string &expiryDate) {
    Medicine *current = head;
    bool found = false;

    cout << "\nSearch Results:" << endl;
    printHeaderLink();

    while (current != nullptr) {
        if (current->expiryDate == expiryDate) {
            printMedicineLink(current);
            found = true;
        }
        current = current->next;
    }

    if (!found) {
        cout << "No medicines expiring in " << expiryDate << " found." << endl;
    }
}

Medicine *getLastNode(Medicine *node) {
    while (node && node->next) {
        node = node->next;
    }
    return node;
}

Medicine *partitionByName(Medicine *low, Medicine *high) {
    string pivot = high->name;
    Medicine *i = low->prev;

    for (Medicine *j = low; j != high; j = j->next) {
        if (j->name < pivot) {
            i = (i == nullptr) ? low : i->next;
            swap(i->name, j->name);
            swap(i->id, j->id);
            swap(i->expiryDate, j->expiryDate);
        }
    }
    i = (i == nullptr) ? low : i->next;
    swap(i->name, high->name);
    swap(i->id, high->id);
    swap(i->expiryDate, high->expiryDate);
    return i;
}

void quickSortByNameLink(Medicine *low, Medicine *high) {
    if (low && high && low != high && low != high->next) {
        Medicine *pivot = partitionByName(low, high);
        quickSortByNameLink(low, pivot->prev);
        quickSortByNameLink(pivot->next, high);
    }
}

void sortByNameLink() {
    if (head == nullptr || head->next == nullptr)
        return;
    quickSortByNameLink(head, getLastNode(head));
}

Medicine *partitionById(Medicine *low, Medicine *high) {
    int pivot = high->id;
    Medicine *i = low->prev;

    for (Medicine *j = low; j != high; j = j->next) {
        if (j->id < pivot) {
            i = (i == nullptr) ? low : i->next;
            swap(i->name, j->name);
            swap(i->id, j->id);
            swap(i->expiryDate, j->expiryDate);
        }
    }
    i = (i == nullptr) ? low : i->next;
    swap(i->name, high->name);
    swap(i->id, high->id);
    swap(i->expiryDate, high->expiryDate);
    return i;
}

void quickSortByIdLink(Medicine *low, Medicine *high) {
    if (low && high && low != high && low != high->next) {
        Medicine *pivot = partitionById(low, high);
        quickSortByIdLink(low, pivot->prev);
        quickSortByIdLink(pivot->next, high);
    }
}

void sortById() {
    if (head == nullptr || head->next == nullptr)
        return;
    quickSortByIdLink(head, getLastNode(head));
}

Medicine *partitionByExpiryDate(Medicine *low, Medicine *high) {
    string pivot = high->expiryDate;
    Medicine *i = low->prev;

    for (Medicine *j = low; j != high; j = j->next) {
        if (j->expiryDate < pivot) {
            i = (i == nullptr) ? low : i->next;
            swap(i->name, j->name);
            swap(i->id, j->id);
            swap(i->expiryDate, j->expiryDate);
        }
    }
    i = (i == nullptr) ? low : i->next;
    swap(i->name, high->name);
    swap(i->id, high->id);
    swap(i->expiryDate, high->expiryDate);
    return i;
}

void quickSortByExpiryDateLink(Medicine *low, Medicine *high) {
    if (low && high && low != high && low != high->next) {
        Medicine *pivot = partitionByExpiryDate(low, high);
        quickSortByExpiryDateLink(low, pivot->prev);
        quickSortByExpiryDateLink(pivot->next, high);
    }
}

void sortByExpiryDateLink() {
    if (head == nullptr || head->next == nullptr)
        return;
    quickSortByExpiryDateLink(head, getLastNode(head));
}

bool updateMedicineLink(int id) {
    Medicine *current = head;

    while (current != nullptr) {
        if (current->id == id) {
            cout << "Enter new details for Medicine ID " << id << ":\n";

            cout << "Enter Medicine Name: ";
            cin.ignore();
            getline(cin, current->name);

            cout << "Enter Price: ";
            cin >> current->price;

            cout << "Enter Quantity: ";
            cin >> current->quantity;

            current->expiryDate = inputExpiryDate();

            return true;
        }
        current = current->next;
    }
    return false;
}

void autoDeleteExpiredLink(int currentMonth, int currentYear) {
    Medicine *current = head;
    bool foundExpired = false;

    while (current != nullptr) {
        string monthStr = current->expiryDate.substr(0, 2);
        string yearStr = current->expiryDate.substr(3, 4);
        int expiryMonth = stoi(monthStr);
        int expiryYear = stoi(yearStr);

        Medicine *toDelete = current;
        current = current->next;

        if (expiryYear < currentYear || (expiryYear == currentYear && expiryMonth < currentMonth)) {
            removeNodeLink(toDelete);
            foundExpired = true;
        }
    }

    if (!foundExpired) {
        cout << "No expired medicines found." << endl;
    }
}

void displayAllLink() {
    if (head == nullptr) {
        cout << "No medicines available to display." << endl;
        return;
    }

    cout << "\n----------------------" << endl;
    cout << "   All Medicines:   " << endl;
    cout << "----------------------\n" << endl;

    printHeaderLink();

    Medicine *current = head;
    while (current != nullptr) {
        printMedicineLink(current);
        current = current->next;
    }
}

void printHeaderLink() {
    cout << setw(5) << "ID" << setw(20) << "Name"
         << setw(10) << "Price" << setw(10) << "Quantity"
         << setw(15) << "Expiry Date" << endl;
    cout << string(60, '-') << endl;
}

void printMedicineLink(Medicine *med) {
    cout << setw(5) << med->id
         << setw(20) << med->name
         << setw(10) << fixed << setprecision(2) << med->price
         << setw(10) << med->quantity
         << setw(15) << med->expiryDate << endl;
}

void swapNodesLink(Medicine *a, Medicine *b) {
    if (a == b)
        return;

    Medicine *aPrev = a->prev;
    Medicine *bNext = b->next;

    if (aPrev)
        aPrev->next = b;
    else
        head = b;

    if (bNext)
        bNext->prev = a;
    else
        tail = a;

    a->next = bNext;
    a->prev = b;
    b->next = a;
    b->prev = aPrev;
}

void removeNodeLink(Medicine *node) {
    if (node->prev)
        node->prev->next = node->next;
    else
        head = node->next;

    if (node->next)
        node->next->prev = node->prev;
    else
        tail = node->prev;

    cout << "Auto-deleted expired medicine: " << node->name
         << " (ID: " << node->id
         << ", Expiry: " << node->expiryDate << ")" << endl;

    delete node;
    count--;
}

int getCount() {
    return count;
}
