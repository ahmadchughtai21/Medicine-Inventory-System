#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "head.cpp"
using namespace std;

struct MedicineQ
{
    int id;
    string name;
    double price;
    int quantity;
    string expiryDate;
    MedicineQ *next;

    MedicineQ(int id, string name, double price, int quantity, string expiryDate)
        : id(id), name(name), price(price), quantity(quantity), expiryDate(expiryDate), next(nullptr) {}
};

MedicineQ *front = nullptr;
MedicineQ *rear = nullptr;
int ::count = 0;

void printHeaderQ()
{
    cout << setw(5) << "ID" << setw(20) << "Name"
         << setw(10) << "Price" << setw(10) << "Quantity"
         << setw(15) << "Expiry Date" << endl;
    cout << string(60, '-') << endl;
    
}

void printNotFoundMessage(const string &name)
{
    cout << "Medicine with name " << name << " not found." << endl;
}

void printMedicineQ(MedicineQ *med)
{
    cout << setw(5) << med->id
         << setw(20) << med->name
         << setw(10) << fixed << setprecision(2) << med->price
         << setw(10) << med->quantity
         << setw(15) << med->expiryDate << endl;
}

bool isIdUniqueQ(int id)
{
    MedicineQ *current = front;
    while (current != nullptr)
    {
        if (current->id == id)
            return false;
        current = current->next;
    }
    return true;
}


void addMedicineQ(int id, string name, double price, int quantity, string expiryDate)
{
    MedicineQ *newMedicine = new MedicineQ(id, name, price, quantity, expiryDate);

    if (rear == nullptr)
    {
        front = rear = newMedicine;
    }
    else
    {
        rear->next = newMedicine;
        rear = newMedicine;
    }
    ::count++;

    cout << "Medicine added successfully!" << endl;
}

void searchByNameQ(const string &name)
{
    MedicineQ *current = front;
    bool found = false;

    cout << "\nSearch Results:" << endl;
    printHeaderQ();

    while (current != nullptr)
    {
        if (current->name == name)
        {
            printMedicineQ(current);
            found = true;
        }
        current = current->next;
    }

    if (!found)
    {
        printNotFoundMessage(name);
    }
}

void searchByIdQ(int id)
{
    MedicineQ *current = front;
    bool found = false;

    cout << "\nSearch Results:" << endl;
    printHeaderQ();

    while (current != nullptr)
    {
        if (current->id == id)
        {
            printMedicineQ(current);
            found = true;
            break;
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "Medicine with ID " << id << " not found." << endl;
    }
}

void searchByExpiryDateQ(const string &expiryDate)
{
    MedicineQ *current = front;
    bool found = false;

    cout << "\nSearch Results:" << endl;
    printHeaderQ();

    while (current != nullptr)
    {
        if (current->expiryDate == expiryDate)
        {
            printMedicineQ(current);
            found = true;
        }
        current = current->next;
    }

    if (!found)
    {
        cout << "No medicines expiring in " << expiryDate << " found." << endl;
    }
}

    void sortByNameQ()
    {
        if (front == nullptr || front->next == nullptr)
            return;

        bool swapped;
        MedicineQ *ptr1;
        MedicineQ *lptr = nullptr;

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

    void sortByIdQ()
    {
        if (front == nullptr || front->next == nullptr)
            return;

        bool swapped;
        MedicineQ *ptr1;
        MedicineQ *lptr = nullptr;

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

    void sortByExpiryDateQ()
    {
        if (front == nullptr || front->next == nullptr)
            return;

        bool swapped;
        MedicineQ *ptr1;
        MedicineQ *lptr = nullptr;

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

    bool updateMedicineQ(int id)
    {
        MedicineQ *current = front;

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
                cout << "Enter Expiry Date (MM/YYYY): ";
                cin >> current->expiryDate;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void autoDeleteExpiredQ(int currentMonth, int currentYear)
{
    MedicineQ *current = front;
    MedicineQ *prev = nullptr;
    bool foundExpired = false;

    while (current != nullptr)
    {
        string monthStr = current->expiryDate.substr(0, 2);
        string yearStr = current->expiryDate.substr(3, 4);
        int expiryMonth = stoi(monthStr);
        int expiryYear = stoi(yearStr);

        if (expiryYear < currentYear || (expiryYear == currentYear && expiryMonth < currentMonth))
        {
            cout << "Auto-deleted expired medicine: " << current->name
                 << " (ID: " << current->id
                 << ", Expiry: " << current->expiryDate << ")" << endl;

            MedicineQ *temp = current;
            
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
            
            current = current->next;
            delete temp;
            ::count--;
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
        cout << "No expired medicines found." << endl;
    }
}

    void displayAllQ()
    {
        if (front == nullptr)
        {
            cout << "No medicines available to display." << endl;
            return;
        }

        cout << "\n----------------------" << endl;
        cout << "   All Medicines:   " << endl;
        cout << "----------------------\n"
             << endl;

        printHeaderQ();

        MedicineQ *current = front;
        while (current != nullptr)
        {
            printMedicineQ(current);
            current = current->next;
        }
    }

    int getCountQ()
    {
        return ::count;
    }
