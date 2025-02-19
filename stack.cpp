#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include "head.cpp"

// Define color constants
#define GREEN "\033[32m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

// Function to input expiry date
using namespace std;

string inputExpiryDate() {
    string expiryDate;
    cout << "Enter Expiry Date (MM/YYYY): ";
    cin >> expiryDate;
    return expiryDate;
}

struct MedicineS
{
    int id;
    string name;
    double price;
    int quantity;
    string expiryDate;
    MedicineS *next;

    MedicineS(int id, string name, double price, int quantity, string expiryDate)
        : id(id), name(name), price(price), quantity(quantity), expiryDate(expiryDate), next(nullptr) {}
};

MedicineS *top = nullptr;
int count = 0;

void deleteAllMedicinesS()
{
    MedicineS *current = top;
    while (current != nullptr) 
    {
        MedicineS *next = current->next;
        delete current;
        current = next;
    }
    top = nullptr;
    count = 0;
}

bool isIdUniqueS(int id)
{
    MedicineS *current = top;
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
    MedicineS *newMedicine = new MedicineS(id, name, price, quantity, expiryDate);
    newMedicine->next = top;
    top = newMedicine;
    count++;

    cout << GREEN << "Medicine added successfully!" << RESET << endl;
}

void searchByNameS(const string &name)
{
    MedicineS *current = top;
    bool found = false;

    cout << "\n"
         << CYAN << "Search Results:" << RESET << endl;
    printHeaderS();

    while (current != nullptr)
    {
        if (current->name == name)
        {
            printMedicineS(current);
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
    MedicineS *current = top;
    bool found = false;

    cout << "\n"
         << CYAN << "Search Results:" << RESET << endl;
    printHeaderS();

    while (current != nullptr)
    {
        if (current->id == id)
        {
            printMedicineS(current);
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
    MedicineS *current = top;
    bool found = false;

    cout << "\n"
         << CYAN << "Search Results:" << RESET << endl;
    printHeaderS();

    while (current != nullptr)
    {
        if (current->expiryDate == expiryDate)
        {
            printMedicineS(current);
            found = true;
        }
        current = current->next;
    }

    if (!found)
    {
        cout << RED << "No medicines expiring in " << expiryDate << " found." << RESET << endl;
    }
}

MedicineS *getLastNodeS(MedicineS *node)
{
    while (node && node->next)
    {
        node = node->next;
    }
    return node;
}

MedicineS *partitionByNameS(MedicineS *start, MedicineS *end)
{
    string pivot = end->name;
    MedicineS *i = start;

    for (MedicineS *j = start; j != end; j = j->next)
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

void quickSortByNameS(MedicineS *start, MedicineS *end)
{
    if (start != nullptr && end != nullptr && start != end && start != end->next)
    {
        MedicineS *pivot = partitionByNameS(start, end);
        MedicineS *temp = start;
        while (temp->next != pivot)
            temp = temp->next;
        quickSortByNameS(start, temp);
        quickSortByNameS(pivot->next, end);
    }
}

void sortByNameS()
{
    if (top == nullptr || top->next == nullptr)
        return;
    quickSortByNameS(top, getLastNodeS(top));
}

MedicineS *partitionByIdS(MedicineS *start, MedicineS *end)
{
    int pivot = end->id;
    MedicineS *i = start;

    for (MedicineS *j = start; j != end; j = j->next)
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

void quickSortByIdS(MedicineS *start, MedicineS *end)
{
    if (start != nullptr && end != nullptr && start != end && start != end->next)
    {
        MedicineS *pivot = partitionByIdS(start, end);
        MedicineS *temp = start;
        while (temp->next != pivot)
            temp = temp->next;
        quickSortByIdS(start, temp);
        quickSortByIdS(pivot->next, end);
    }
}

void sortByIdS()
{
    if (top == nullptr || top->next == nullptr)
        return;
    quickSortByIdS(top, getLastNodeS(top));
}

MedicineS *partitionByExpiryDateS(MedicineS *start, MedicineS *end)
{
    string pivot = end->expiryDate;
    MedicineS *i = start;

    for (MedicineS *j = start; j != end; j = j->next)
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

void quickSortByExpiryDateS(MedicineS *start, MedicineS *end)
{
    if (start != nullptr && end != nullptr && start != end && start != end->next)
    {
        MedicineS *pivot = partitionByExpiryDateS(start, end);
        MedicineS *temp = start;
        while (temp->next != pivot)
            temp = temp->next;
        quickSortByExpiryDateS(start, temp);
        quickSortByExpiryDateS(pivot->next, end);
    }
}

void sortByExpiryDateS()
{
    if (top == nullptr || top->next == nullptr)
        return;
    quickSortByExpiryDateS(top, getLastNodeS(top));
}

bool updateMedicineS(int id)
{
    MedicineS *current = top;

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
    MedicineS *newTop = nullptr;
    MedicineS *current = top;
    bool foundExpired = false;

    while (current != nullptr)
    {
        string monthStr = current->expiryDate.substr(0, 2);
        string yearStr = current->expiryDate.substr(3, 4);
        int expiryMonth = stoi(monthStr);
        int expiryYear = stoi(yearStr);

        MedicineS *next = current->next;

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

    printHeaderS();

    MedicineS *current = top;
    while (current != nullptr)
    {
        printMedicineS(current);
        current = current->next;
    }
}

void printHeaderS()
{
    cout << setw(5) << "ID" << setw(20) << "Name"
         << setw(10) << "Price" << setw(10) << "Quantity"
         << setw(15) << "Expiry Date" << endl;
    cout << string(60, '-') << endl;
}

void printMedicineS(MedicineS *med)
{
    cout << setw(5) << med->id
         << setw(20) << med->name
         << setw(10) << fixed << setprecision(2) << med->price
         << setw(10) << med->quantity
         << setw(15) << med->expiryDate << endl;
}

int getCountS()
{
    return count;
}
