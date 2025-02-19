#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "head.h"

using namespace std;

struct MedicineL {
    int id;
    string name;
    double price;
    int quantity;
    string expiryDate;
    MedicineL *next;
    MedicineL *prev;

    MedicineL(int id, string name, double price, int quantity, string expiryDate)
        : id(id), name(name), price(price), quantity(quantity), expiryDate(expiryDate), next(nullptr), prev(nullptr) {}
};

MedicineL* head = nullptr;
MedicineL* tail = nullptr;
int medicineCount = 0;

void deleteAllMedicines() {
    MedicineL *current = head;
    while (current != nullptr) {
        MedicineL *next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    medicineCount = 0;
}

bool isIdUniqueLink(int id) {
    MedicineL *current = head;
    while (current != nullptr) {
        if (current->id == id)
            return false;
        current = current->next;
    }
    return true;
}

void addMedicineLink(int id, string name, double price, int quantity, string expiryDate) {
    MedicineL *newMedicine = new MedicineL(id, name, price, quantity, expiryDate);

    if (head == nullptr) {
        head = tail = newMedicine;
    } else {
        tail->next = newMedicine;
        newMedicine->prev = tail;
        tail = newMedicine;
    }
    medicineCount++;

    cout << "Medicine added successfully!" << endl;
}

void searchByNameLink(const string &name) {
    MedicineL *current = head;
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
    MedicineL *current = head;
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
    MedicineL *current = head;
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

MedicineL *getLastNode(MedicineL *node) {
    while (node && node->next) {
        node = node->next;
    }
    return node;
}

MedicineL *partitionByName(MedicineL *low, MedicineL *high) {
    string pivot = high->name;
    MedicineL *i = low->prev;

    for (MedicineL *j = low; j != high; j = j->next) {
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

void quickSortByNameLink(MedicineL *low, MedicineL *high) {
    if (low && high && low != high && low != high->next) {
        MedicineL *pivot = partitionByName(low, high);
        quickSortByNameLink(low, pivot->prev);
        quickSortByNameLink(pivot->next, high);
    }
}

void sortByNameLink() {
    if (head == nullptr || head->next == nullptr)
        return;
    quickSortByNameLink(head, getLastNode(head));
}

MedicineL *partitionById(MedicineL *low, MedicineL *high) {
    int pivot = high->id;
    MedicineL *i = low->prev;

    for (MedicineL *j = low; j != high; j = j->next) {
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

void quickSortByIdLink(MedicineL *low, MedicineL *high) {
    if (low && high && low != high && low != high->next) {
        MedicineL *pivot = partitionById(low, high);
        quickSortByIdLink(low, pivot->prev);
        quickSortByIdLink(pivot->next, high);
    }
}
void sortById() {
    if (head == nullptr || head->next == nullptr)
        return;
    quickSortByIdLink(head, getLastNode(head));
}

MedicineL *partitionByExpiryDate(MedicineL *low, MedicineL *high) {
    string pivot = high->expiryDate;
    MedicineL *i = low->prev;

    for (MedicineL *j = low; j != high; j = j->next) {
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

void quickSortByExpiryDateLink(MedicineL *low, MedicineL *high) {
    if (low && high && low != high && low != high->next) {
        MedicineL *pivot = partitionByExpiryDate(low, high);
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
    MedicineL *current = head;

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
    MedicineL *current = head;
    bool foundExpired = false;

    while (current != nullptr) {
        string monthStr = current->expiryDate.substr(0, 2);
        string yearStr = current->expiryDate.substr(3, 4);
        int expiryMonth = stoi(monthStr);
        int expiryYear = stoi(yearStr);

        MedicineL *toDelete = current;
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

    MedicineL *current = head;
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

void printMedicineLink(MedicineL *med) {
    cout << setw(5) << med->id
         << setw(20) << med->name
         << setw(10) << fixed << setprecision(2) << med->price
         << setw(10) << med->quantity
         << setw(15) << med->expiryDate << endl;
}

void swapNodesLink(MedicineL *a, MedicineL *b) {
    if (a == b)
        return;

    MedicineL *aPrev = a->prev;
    MedicineL *bNext = b->next;

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

void removeNodeLink(MedicineL *node) {
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
    medicineCount--;
}

int getCountLink() {
    return medicineCount;
}
