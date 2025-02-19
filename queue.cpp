#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "head.cpp"
using namespace std;

/**
 * Main class for medicine management
 * Implements a queue linked list for storing and managing medicine data
 */
class MedicineListQueue
{
private:
    Medicine *front;
    Medicine *rear;
    int count;

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
    MedicineListQueue() : front(nullptr), rear(nullptr), count(0) {}

    ~MedicineListQueue()
    {
        Medicine *current = front;
        while (current != nullptr)
        {
            Medicine *next = current->next;
            delete current;
            current = next;
        }
    }

    bool isIdUniqueq(int id)
    {
        Medicine *current = front;
        while (current != nullptr)
        {
            if (current->id == id)
                return false;
            current = current->next;
        }
        return true;
    }

    void addMedicineq(int id, string name, double price, int quantity, string expiryDate)
    {
        Medicine *newMedicine = new Medicine(id, name, price, quantity, expiryDate);

        if (rear == nullptr)
        {
            front = rear = newMedicine;
        }
        else
        {
            rear->next = newMedicine;
            rear = newMedicine;
        }
        count++;

        cout << GREEN << "Medicine added successfully!" << RESET << endl;
    }

    void searchByNameq(const string &name)
    {
        Medicine *current = front;
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

    void searchByIdq(int id)
    {
        Medicine *current = front;
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

    void searchByExpiryDateq(const string &expiryDate)
    {
        Medicine *current = front;
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

    void sortByNameq()
    {
        if (front == nullptr || front->next == nullptr)
            return;

        bool swapped;
        Medicine *ptr1;
        Medicine *lptr = nullptr;

        do
        {
            swapped = false;
            ptr1 = front;

            while (ptr1->next != lptr)
            {
                if (ptr1->name > ptr1->next->name)
                {
                    swap(ptr1->name, ptr1->next->name);
                    swap(ptr1->id, ptr1->next->id);
                    swap(ptr1->price, ptr1->next->price);
                    swap(ptr1->quantity, ptr1->next->quantity);
                    swap(ptr1->expiryDate, ptr1->next->expiryDate);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    void sortByIdq()
    {
        if (front == nullptr || front->next == nullptr)
            return;

        bool swapped;
        Medicine *ptr1;
        Medicine *lptr = nullptr;

        do
        {
            swapped = false;
            ptr1 = front;

            while (ptr1->next != lptr)
            {
                if (ptr1->id > ptr1->next->id)
                {
                    swap(ptr1->name, ptr1->next->name);
                    swap(ptr1->id, ptr1->next->id);
                    swap(ptr1->price, ptr1->next->price);
                    swap(ptr1->quantity, ptr1->next->quantity);
                    swap(ptr1->expiryDate, ptr1->next->expiryDate);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    void sortByExpiryDateq()
    {
        if (front == nullptr || front->next == nullptr)
            return;

        bool swapped;
        Medicine *ptr1;
        Medicine *lptr = nullptr;

        do
        {
            swapped = false;
            ptr1 = front;

            while (ptr1->next != lptr)
            {
                if (ptr1->expiryDate > ptr1->next->expiryDate)
                {
                    swap(ptr1->name, ptr1->next->name);
                    swap(ptr1->id, ptr1->next->id);
                    swap(ptr1->price, ptr1->next->price);
                    swap(ptr1->quantity, ptr1->next->quantity);
                    swap(ptr1->expiryDate, ptr1->next->expiryDate);
                    swapped = true;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (swapped);
    }

    bool updateMedicineq(int id)
    {
        Medicine *current = front;

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

    void autoDeleteExpiredq(int currentMonth, int currentYear)
    {
        Medicine *current = front;
        Medicine *prev = nullptr;
        bool foundExpired = false;

        while (current != nullptr)
        {
            string monthStr = current->expiryDate.substr(0, 2);
            string yearStr = current->expiryDate.substr(3, 4);
            int expiryMonth = stoi(monthStr);
            int expiryYear = stoi(yearStr);

            if (expiryYear < currentYear || (expiryYear == currentYear && expiryMonth < currentMonth))
            {
                cout << RED << "Auto-deleted expired medicine: " << current->name
                     << " (ID: " << current->id
                     << ", Expiry: " << current->expiryDate << ")" << RESET << endl;

                if (prev == nullptr)
                {
                    front = current->next;
                    if (front == nullptr)
                        rear = nullptr;
                }
                else
                {
                    prev->next = current->next;
                    if (prev->next == nullptr)
                        rear = prev;
                }

                Medicine *temp = current;
                current = current->next;
                delete temp;
                count--;
                foundExpired = true;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }

        if (!foundExpired)
        {
            cout << GREEN << "No expired medicines found." << RESET << endl;
        }
    }

    void displayAllq()
    {
        if (front == nullptr)
        {
            cout << RED << "No medicines available to display." << RESET << endl;
            return;
        }

        cout << "\n----------------------" << endl;
        cout << GREEN << "   All Medicines:   " << RESET << endl;
        cout << "----------------------\n"
             << endl;

        printHeader();

        Medicine *current = front;
        while (current != nullptr)
        {
            printMedicine(current);
            current = current->next;
        }
    }

    int getCount() const { return count; }
};
