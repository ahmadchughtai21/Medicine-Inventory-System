#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "head.cpp"

using namespace std;

/**
 * Main class for medicine management
 * Implements a stack-based linked list for storing and managing medicine data
 */
class MedicineListStack
{
private:
    Medicine *top;
    int count;

public:
    MedicineListStack() : top(nullptr), count(0) {}

    ~MedicineListStack()
    {
        Medicine *current = top;
        while (current != nullptr)
        {
            Medicine *next = current->next;
            delete current;
            current = next;
        }
    }

    bool isIdUnique(int id)
    {
        Medicine *current = top;
        while (current != nullptr)
        {
            if (current->id == id)
                return false;
            current = current->next;
        }
        return true;
    }

    void addMedicineS(int id, string name, double price, int quantity, string expiryDate)
    {
        Medicine *newMedicine = new Medicine(id, name, price, quantity, expiryDate);
        newMedicine->next = top;
        top = newMedicine;
        count++;

        cout << GREEN << "Medicine added successfully!" << RESET << endl;
    }

    void searchByNameS(const string &name)
    {
        Medicine *current = top;
        bool found = false;

        cout << "\n"
             << CYAN << "Search Results:" << RESET << endl;
        printHeader();

        while (current != nullptr)
        {
            if (current->name == name)
            {
                printMedicine(current);
                found = true;
            }
            current = current->next;
        }

        if (!found)
        {
            cout << RED << "Medicine with name '" << name << "' not found." << RESET << endl;
        }
    }

    void searchByIdS(int id)
    {
        Medicine *current = top;
        bool found = false;

        cout << "\n"
             << CYAN << "Search Results:" << RESET << endl;
        printHeader();

        while (current != nullptr)
        {
            if (current->id == id)
            {
                printMedicine(current);
                found = true;
                break;
            }
            current = current->next;
        }

        if (!found)
        {
            cout << RED << "Medicine with ID " << id << " not found." << RESET << endl;
        }
    }

    void searchByExpiryDateS(const string &expiryDate)
    {
        Medicine *current = top;
        bool found = false;

        cout << "\n"
             << CYAN << "Search Results:" << RESET << endl;
        printHeader();

        while (current != nullptr)
        {
            if (current->expiryDate == expiryDate)
            {
                printMedicine(current);
                found = true;
            }
            current = current->next;
        }

        if (!found)
        {
            cout << RED << "No medicines expiring in " << expiryDate << " found." << RESET << endl;
        }
    }

    Medicine *getLastNode(Medicine *node)
    {
        while (node && node->next)
        {
            node = node->next;
        }
        return node;
    }

    Medicine *partitionByName(Medicine *start, Medicine *end)
    {
        string pivot = end->name;
        Medicine *i = start;

        for (Medicine *j = start; j != end; j = j->next)
        {
            if (j->name < pivot)
            {
                swap(i->name, j->name);
                swap(i->id, j->id);
                swap(i->price, j->price);
                swap(i->quantity, j->quantity);
                swap(i->expiryDate, j->expiryDate);
                i = i->next;
            }
        }
        swap(i->name, end->name);
        swap(i->id, end->id);
        swap(i->price, end->price);
        swap(i->quantity, end->quantity);
        swap(i->expiryDate, end->expiryDate);
        return i;
    }

    void quickSortByNameS(Medicine *start, Medicine *end)
    {
        if (start != nullptr && end != nullptr && start != end && start != end->next)
        {
            Medicine *pivot = partitionByName(start, end);
            Medicine *temp = start;
            while (temp->next != pivot)
                temp = temp->next;
            quickSortByNameS(start, temp);
            quickSortByNameS(pivot->next, end);
        }
    }

    void sortByName()
    {
        if (top == nullptr || top->next == nullptr)
            return;
        quickSortByNameS(top, getLastNode(top));
    }

    Medicine *partitionById(Medicine *start, Medicine *end)
    {
        int pivot = end->id;
        Medicine *i = start;

        for (Medicine *j = start; j != end; j = j->next)
        {
            if (j->id < pivot)
            {
                swap(i->id, j->id);
                swap(i->name, j->name);
                swap(i->price, j->price);
                swap(i->quantity, j->quantity);
                swap(i->expiryDate, j->expiryDate);
                i = i->next;
            }
        }
        swap(i->id, end->id);
        swap(i->name, end->name);
        swap(i->price, end->price);
        swap(i->quantity, end->quantity);
        swap(i->expiryDate, end->expiryDate);
        return i;
    }

    void quickSortByIdS(Medicine *start, Medicine *end)
    {
        if (start != nullptr && end != nullptr && start != end && start != end->next)
        {
            Medicine *pivot = partitionById(start, end);
            Medicine *temp = start;
            while (temp->next != pivot)
                temp = temp->next;
            quickSortByIdS(start, temp);
            quickSortByIdS(pivot->next, end);
        }
    }

    void sortById()
    {
        if (top == nullptr || top->next == nullptr)
            return;
        quickSortByIdS(top, getLastNode(top));
    }

    Medicine *partitionByExpiryDate(Medicine *start, Medicine *end)
    {
        string pivot = end->expiryDate;
        Medicine *i = start;

        for (Medicine *j = start; j != end; j = j->next)
        {
            if (j->expiryDate < pivot)
            {
                swap(i->id, j->id);
                swap(i->name, j->name);
                swap(i->price, j->price);
                swap(i->quantity, j->quantity);
                swap(i->expiryDate, j->expiryDate);
                i = i->next;
            }
        }
        swap(i->id, end->id);
        swap(i->name, end->name);
        swap(i->price, end->price);
        swap(i->quantity, end->quantity);
        swap(i->expiryDate, end->expiryDate);
        return i;
    }

    void quickSortByExpiryDateS(Medicine *start, Medicine *end)
    {
        if (start != nullptr && end != nullptr && start != end && start != end->next)
        {
            Medicine *pivot = partitionByExpiryDate(start, end);
            Medicine *temp = start;
            while (temp->next != pivot)
                temp = temp->next;
            quickSortByExpiryDateS(start, temp);
            quickSortByExpiryDateS(pivot->next, end);
        }
    }

    void sortByExpiryDate()
    {
        if (top == nullptr || top->next == nullptr)
            return;
        quickSortByExpiryDateS(top, getLastNode(top));
    }

    bool updateMedicineS(int id)
    {
        Medicine *current = top;

        while (current != nullptr)
        {
            if (current->id == id)
            {
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

    void autoDeleteExpiredS(int currentMonth, int currentYear)
    {
        Medicine *newTop = nullptr;
        Medicine *current = top;
        bool foundExpired = false;

        while (current != nullptr)
        {
            string monthStr = current->expiryDate.substr(0, 2);
            string yearStr = current->expiryDate.substr(3, 4);
            int expiryMonth = stoi(monthStr);
            int expiryYear = stoi(yearStr);

            Medicine *next = current->next;

            if (expiryYear < currentYear || (expiryYear == currentYear && expiryMonth < currentMonth))
            {
                cout << RED << "Auto-deleted expired medicine: " << current->name
                     << " (ID: " << current->id
                     << ", Expiry: " << current->expiryDate << ")" << RESET << endl;
                delete current;
                count--;
                foundExpired = true;
            }
            else
            {
                current->next = newTop;
                newTop = current;
            }
            current = next;
        }

        top = newTop;

        if (!foundExpired)
        {
            cout << GREEN << "No expired medicines found." << RESET << endl;
        }
    }

    void displayAllS()
    {
        if (top == nullptr)
        {
            cout << RED << "No medicines available to display." << RESET << endl;
            return;
        }

        cout << "\n----------------------" << endl;
        cout << GREEN << "   All Medicines:   " << RESET << endl;
        cout << "----------------------\n"
             << endl;

        printHeader();

        Medicine *current = top;
        while (current != nullptr)
        {
            printMedicine(current);
            current = current->next;
        }
    }

private:
    void printHeader()
    {
        cout << setw(5) << "ID" << setw(20) << "Name"
             << setw(10) << "Price" << setw(10) << "Quantity"
             << setw(15) << "Expiry Date" << endl;
        cout << string(60, '-') << endl;
    }

    void printMedicine(Medicine *med)
    {
        cout << setw(5) << med->id
             << setw(20) << med->name
             << setw(10) << fixed << setprecision(2) << med->price
             << setw(10) << med->quantity
             << setw(15) << med->expiryDate << endl;
    }

public:
    int getCount() const { return count; }
};