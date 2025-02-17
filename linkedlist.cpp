#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

// Terminal color codes for better user interface feedback
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"

/**
 * Medicine node structure for doubly linked list implementation
 * Each node contains medicine details and pointers to adjacent nodes
 */
struct Medicine
{
    int id;
    string name;
    double price;
    int quantity;
    string expiryDate;
    Medicine *next;
    Medicine *prev;

    Medicine(int i, string n, double p, int q, string exp) : id(i), name(n), price(p), quantity(q), expiryDate(exp), next(nullptr), prev(nullptr) {}
};

/**
 * Input validation helper functions
 */
bool isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

bool isValidMonth(int month)
{
    return month >= 1 && month <= 12;
}

bool isValidYear(int year)
{
    return year >= 2000 && year <= 9999;
}

/**
 * Validates expiry date format (MM/YYYY)
 * Returns true if format is valid and month is between 1-12
 */
bool isValidExpiryFormat(const string &expiryDate)
{
    if (expiryDate.length() != 7 || expiryDate[2] != '/')
        return false;

    string monthStr = expiryDate.substr(0, 2);
    string yearStr = expiryDate.substr(3, 4);

    for (char c : monthStr)
        if (!isDigit(c))
            return false;
    for (char c : yearStr)
        if (!isDigit(c))
            return false;

    int month = stoi(monthStr);
    return (month >= 1 && month <= 12);
}

/**
 * Gets current date from user with validation
 * Returns false if input is invalid
 */
bool getCurrentDate(int &month, int &year)
{
    cout << "Enter current month (1-12): ";
    cin >> month;
    if (!isValidMonth(month))
    {
        cout << RED << "Invalid month! Please enter a number between 1 and 12." << RESET << endl;
        return false;
    }

    cout << "Enter current year (YYYY): ";
    cin >> year;
    if (!isValidYear(year))
    {
        cout << RED << "Invalid year! Please enter a valid year (2000-9999)." << RESET << endl;
        return false;
    }
    return true;
}

/**
 * Handles expiry date input with validation
 * Keeps prompting until valid format is entered
 */
string inputExpiryDate()
{
    string expiryDate;
    do
    {
        cout << "Enter expiry date (MM/YYYY): ";
        cin >> expiryDate;
        if (!isValidExpiryFormat(expiryDate))
        {
            cout << RED << "Invalid format! Please enter in MM/YYYY format." << RESET << endl;
        }
    } while (!isValidExpiryFormat(expiryDate));
    return expiryDate;
}

/**
 * Main class for medicine management
 * Implements a doubly linked list for storing and managing medicine data
 */
class MedicineList
{
private:
    Medicine *head;
    Medicine *tail;
    int count;

public:
    MedicineList() : head(nullptr), tail(nullptr), count(0) {}

    // Destructor to clean up allocated memory
    ~MedicineList()
    {
        Medicine *current = head;
        while (current != nullptr)
        {
            Medicine *next = current->next;
            delete current;
            current = next;
        }
    }

    // Verifies that medicine ID is unique in the list
    bool isIdUnique(int id)
    {
        Medicine *current = head;
        while (current != nullptr)
        {
            if (current->id == id)
                return false;
            current = current->next;
        }
        return true;
    }

    /**
     * Adds new medicine to the doubly linked list
     * Maintains the list structure with proper linking
     */
    void addMedicine(int id, string name, double price, int quantity, string expiryDate)
    {
        Medicine *newMedicine = new Medicine(id, name, price, quantity, expiryDate);

        if (head == nullptr)
        {
            head = tail = newMedicine;
        }
        else
        {
            tail->next = newMedicine;
            newMedicine->prev = tail;
            tail = newMedicine;
        }
        count++;

        cout << GREEN << "Medicine added successfully!" << RESET << endl;
    }

    // Search functions with formatted output
    void searchByName(const string &name)
    {
        Medicine *current = head;
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

    void searchById(int id)
    {
        Medicine *current = head;
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

    void searchByExpiryDate(const string &expiryDate)
    {
        Medicine *current = head;
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

    // Utility function to get the last node of the list
    Medicine *getLastNode(Medicine *node)
    {
        while (node && node->next)
        {
            node = node->next;
        }
        return node;
    }

    // Partition function for QuickSort (Sorting by Name)
    Medicine *partitionByName(Medicine *low, Medicine *high)
    {
        string pivot = high->name;
        Medicine *i = low->prev;

        for (Medicine *j = low; j != high; j = j->next)
        {
            if (j->name < pivot)
            {
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

    void quickSortByName(Medicine *low, Medicine *high)
    {
        if (low && high && low != high && low != high->next)
        {
            Medicine *pivot = partitionByName(low, high);
            quickSortByName(low, pivot->prev);
            quickSortByName(pivot->next, high);
        }
    }

    void sortByName()
    {
        if (head == nullptr || head->next == nullptr)
            return;
        quickSortByName(head, getLastNode(head));
    }

    // Partition function for QuickSort (Sorting by ID)
    Medicine *partitionById(Medicine *low, Medicine *high)
    {
        int pivot = high->id;
        Medicine *i = low->prev;

        for (Medicine *j = low; j != high; j = j->next)
        {
            if (j->id < pivot)
            {
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

    void quickSortById(Medicine *low, Medicine *high)
    {
        if (low && high && low != high && low != high->next)
        {
            Medicine *pivot = partitionById(low, high);
            quickSortById(low, pivot->prev);
            quickSortById(pivot->next, high);
        }
    }

    void sortById()
    {
        if (head == nullptr || head->next == nullptr)
            return;
        quickSortById(head, getLastNode(head));
    }

    // Partition function for QuickSort (Sorting by Expiry Date)
    Medicine *partitionByExpiryDate(Medicine *low, Medicine *high)
    {
        string pivot = high->expiryDate;
        Medicine *i = low->prev;

        for (Medicine *j = low; j != high; j = j->next)
        {
            if (j->expiryDate < pivot)
            {
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

    void quickSortByExpiryDate(Medicine *low, Medicine *high)
    {
        if (low && high && low != high && low != high->next)
        {
            Medicine *pivot = partitionByExpiryDate(low, high);
            quickSortByExpiryDate(low, pivot->prev);
            quickSortByExpiryDate(pivot->next, high);
        }
    }

    void sortByExpiryDate()
    {
        if (head == nullptr || head->next == nullptr)
            return;
        quickSortByExpiryDate(head, getLastNode(head));
    }

    /**
     * Updates medicine details in the doubly linked list
     * Returns true if medicine was found and updated
     */
    bool updateMedicine(int id)
    {
        Medicine *current = head;

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

    /**
     * Automatically removes expired medicines based on current date
     * Updates the doubly linked list structure
     */
    void autoDeleteExpired(int currentMonth, int currentYear)
    {
        Medicine *current = head;
        bool foundExpired = false;

        while (current != nullptr)
        {
            string monthStr = current->expiryDate.substr(0, 2);
            string yearStr = current->expiryDate.substr(3, 4);
            int expiryMonth = stoi(monthStr);
            int expiryYear = stoi(yearStr);

            Medicine *toDelete = current;
            current = current->next;

            if (expiryYear < currentYear || (expiryYear == currentYear && expiryMonth < currentMonth))
            {
                removeNode(toDelete);
                foundExpired = true;
            }
        }

        if (!foundExpired)
        {
            cout << GREEN << "No expired medicines found." << RESET << endl;
        }
    }

    void displayAll()
    {
        if (head == nullptr)
        {
            cout << RED << "No medicines available to display." << RESET << endl;
            return;
        }

        cout << "\n----------------------" << endl;
        cout << GREEN << "   All Medicines:   " << RESET << endl;
        cout << "----------------------\n"
             << endl;

        printHeader();

        Medicine *current = head;
        while (current != nullptr)
        {
            printMedicine(current);
            current = current->next;
        }
    }

private:
    // Helper functions for displaying medicine information
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

    /**
     * Swaps two adjacent nodes in the doubly linked list
     * Updates head/tail pointers if necessary
     */
    void swapNodes(Medicine *a, Medicine *b)
    {
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

    /**
     * Removes a node from the linked list and deletes it
     * Updates count and displays deletion message
     */
    void removeNode(Medicine *node)
    {
        if (node->prev)
            node->prev->next = node->next;
        else
            head = node->next;

        if (node->next)
            node->next->prev = node->prev;
        else
            tail = node->prev;

        cout << RED << "Auto-deleted expired medicine: " << node->name
             << " (ID: " << node->id
             << ", Expiry: " << node->expiryDate << ")" << RESET << endl;

        delete node;
        count--;
    }

public:
    int getCount() const { return count; }
};
