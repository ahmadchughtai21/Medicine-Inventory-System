#include <iostream>
#include <string>
#include <ctime>
using namespace std;
// Structure to store date components
struct Date {
    int year;
    int month;
    int day;
};

// Function to convert string date to Date structure
Date stringToDate(string dateStr) {
    Date date;
    sscanf(dateStr.c_str(), "%d-%d-%d", &date.year, &date.month, &date.day);
    return date;
}

// Function to compare dates
bool isDate1BeforeDate2(Date date1, Date date2) {
    if (date1.year < date2.year) return true;
    if (date1.year > date2.year) return false;
    if (date1.month < date2.month) return true;
    if (date1.month > date2.month) return false;
    return date1.day < date2.day;
}

// Get current date
Date getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    Date currentDate;
    currentDate.year = 1900 + ltm->tm_year;
    currentDate.month = 1 + ltm->tm_mon;
    currentDate.day = ltm->tm_mday;
    return currentDate;
}

// Function to check if a date is close to expiry (within 30 days)
bool isCloseToExpiry(Date expiryDate) {
    Date currentDate = getCurrentDate();
    int diffDays = (expiryDate.year - currentDate.year) * 365 +
                   (expiryDate.month - currentDate.month) * 30 +
                   (expiryDate.day - currentDate.day);
    return (diffDays > 0 && diffDays <= 30);
}

// Structure to represent a medicine
struct Medicine {
    string name;
    double price;
    int quantity;
    string expiryDate;
    string manufacturingDate;
};

// Stack class to manage medicines
class Stack {
private:
    static const int MAX_SIZE = 100; // Maximum stack size
    Medicine medicines[MAX_SIZE];    // Array to store medicines
    int top;                         // Index of the top element

public:
    Stack() : top(-1) {} // Constructor to initialize the stack

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX_SIZE - 1; }

    void push(Medicine medicine) {
        if (isFull()) {
            cout << "Stack is full. Cannot add more medicines." << endl;
            return;
        }
        medicines[++top] = medicine;
        cout << "Medicine added successfully!" << endl;
    }

    Medicine pop() {
        if (isEmpty()) {
            cout << "Stack is empty. No medicine to remove." << endl;
            return Medicine();
        }
        return medicines[top--];
    }

    void display() {
        if (isEmpty()) {
            cout << "No medicines to display." << endl;
            return;
        }
        cout << "\n--- Medicines in Stock ---" << endl;
        for (int i = 0; i <= top; i++) {
            cout << "Name: " << medicines[i].name << ", Price: " << medicines[i].price
                 << ", Quantity: " << medicines[i].quantity << ", Expiry Date: " << medicines[i].expiryDate
                 << ", Manufacturing Date: " << medicines[i].manufacturingDate << endl;
        }
    }

    void searchByName(string name) {
        bool found = false;
        for (int i = 0; i <= top; i++) {
            if (medicines[i].name == name) {
                found = true;
                cout << "Medicine found: " << medicines[i].name << ", Price: " << medicines[i].price
                     << ", Quantity: " << medicines[i].quantity << ", Expiry Date: " << medicines[i].expiryDate
                     << ", Manufacturing Date: " << medicines[i].manufacturingDate << endl;
            }
        }
        if (!found) {
            cout << "Medicine not found." << endl;
        }
    }

    void searchByPrice(double price) {
        bool found = false;
        for (int i = 0; i <= top; i++) {
            if (medicines[i].price == price) {
                found = true;
                cout << "Medicine found: " << medicines[i].name << ", Price: " << medicines[i].price
                     << ", Quantity: " << medicines[i].quantity << ", Expiry Date: " << medicines[i].expiryDate
                     << ", Manufacturing Date: " << medicines[i].manufacturingDate << endl;
            }
        }
        if (!found) {
            cout << "No medicines found with price " << price << "." << endl;
        }
    }

    void searchByQuantity(int quantity) {
        bool found = false;
        for (int i = 0; i <= top; i++) {
            if (medicines[i].quantity == quantity) {
                found = true;
                cout << "Medicine found: " << medicines[i].name << ", Price: " << medicines[i].price
                     << ", Quantity: " << medicines[i].quantity << ", Expiry Date: " << medicines[i].expiryDate
                     << ", Manufacturing Date: " << medicines[i].manufacturingDate << endl;
            }
        }
        if (!found) {
            cout << "No medicines found with quantity " << quantity << "." << endl;
        }
    }

    void searchByExpiryDate(string expiryDate) {
        bool found = false;
        for (int i = 0; i <= top; i++) {
            if (medicines[i].expiryDate == expiryDate) {
                found = true;
                cout << "Medicine found: " << medicines[i].name << ", Price: " << medicines[i].price
                     << ", Quantity: " << medicines[i].quantity << ", Expiry Date: " << medicines[i].expiryDate
                     << ", Manufacturing Date: " << medicines[i].manufacturingDate << endl;
            }
        }
        if (!found) {
            cout << "No medicines found with expiry date " << expiryDate << "." << endl;
        }
    }

    void searchByManufacturingDate(string manufacturingDate) {
        bool found = false;
        for (int i = 0; i <= top; i++) {
            if (medicines[i].manufacturingDate == manufacturingDate) {
                found = true;
                cout << "Medicine found: " << medicines[i].name << ", Price: " << medicines[i].price
                     << ", Quantity: " << medicines[i].quantity << ", Expiry Date: " << medicines[i].expiryDate
                     << ", Manufacturing Date: " << medicines[i].manufacturingDate << endl;
            }
        }
        if (!found) {
            cout << "No medicines found with manufacturing date " << manufacturingDate << "." << endl;
        }
    }

    void sortByName() {
        sort(medicines, medicines + top + 1, [](Medicine a, Medicine b) { return a.name < b.name; });
        cout << "Medicines sorted by name." << endl;
    }

    void sortByPrice() {
        sort(medicines, medicines + top + 1, [](Medicine a, Medicine b) { return a.price < b.price; });
        cout << "Medicines sorted by price." << endl;
    }

    void sortByQuantity() {
        sort(medicines, medicines + top + 1, [](Medicine a, Medicine b) { return a.quantity < b.quantity; });
        cout << "Medicines sorted by quantity." << endl;
    }

    void sortByExpiryDate() {
        sort(medicines, medicines + top + 1, [](Medicine a, Medicine b) { return a.expiryDate < b.expiryDate; });
        cout << "Medicines sorted by expiry date." << endl;
    }

    void sortByManufacturingDate() {
        sort(medicines, medicines + top + 1, [](Medicine a, Medicine b) { return a.manufacturingDate < b.manufacturingDate; });
        cout << "Medicines sorted by manufacturing date." << endl;
    }

    void viewLowStockMedicines() {
        cout << "\n--- Medicines with Low Stock (less than 5) ---" << endl;
        bool found = false;
        for (int i = 0; i <= top; i++) {
            if (medicines[i].quantity < 5) {
                found = true;
                cout << "Name: " << medicines[i].name << ", Quantity: " << medicines[i].quantity << endl;
            }
        }
        if (!found) {
            cout << "No medicines with low stock." << endl;
        }
    }

    void viewOutOfStockMedicines() {
        cout << "\n--- Medicines Out of Stock ---" << endl;
        bool found = false;
        for (int i = 0; i <= top; i++) {
            if (medicines[i].quantity == 0) {
                found = true;
                cout << "Name: " << medicines[i].name << ", Quantity: " << medicines[i].quantity << endl;
            }
        }
        if (!found) {
            cout << "No medicines are out of stock." << endl;
        }
    }

};

// Function prototypes
void manageMedicinesMenu();
void searchMedicinesMenu();
void stockManagementMenu();
void viewMedicines();
void addMedicine();
void deleteMedicine();
void sortMedicinesMenu();

// Manage Medicines Menu
void manageMedicinesMenu() {
    int choice;
    do {
        cout << "\n--- Manage Medicines Menu ---" << endl;
        cout << "1. View Medicines\n";
        cout << "2. Add Medicine\n";
        cout << "3. Delete Medicine\n";
        cout << "4. Search Medicines\n";
        cout << "5. Sort Medicines\n";
        cout << "6. Stock Management\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: viewMedicines(); break;
            case 2: addMedicine(); break;
            case 3: deleteMedicine(); break;
            case 4: searchMedicinesMenu(); break;
            case 5: sortMedicinesMenu(); break;
            case 6: stockManagementMenu(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
}

// Search Medicines Menu
void searchMedicinesMenu() {
    int choice;
    do {
        cout << "\n--- Search Medicines Menu ---" << endl;
        cout << "1. Search by Name\n";
        cout << "2. Search by Price\n";
        cout << "3. Search by Quantity\n";
        cout << "4. Search by Expiry Date\n";
        cout << "5. Search by Manufacturing Date\n";
        cout << "6. Go Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string input;
        double price;
        int quantity;
        switch (choice) {
            case 1: {
                cout << "Enter Medicine Name: ";
                cin.ignore();
                getline(cin, input);
                medicineStack.searchByName(input);
                break;
            }
            case 2: {
                cout << "Enter Price: ";
                cin >> price;
                medicineStack.searchByPrice(price);
                break;
            }
            case 3: {
                cout << "Enter Quantity: ";
                cin >> quantity;
                medicineStack.searchByQuantity(quantity);
                break;
            }
            case 4: {
                cout << "Enter Expiry Date (YYYY-MM-DD): ";
                cin >> input;
                medicineStack.searchByExpiryDate(input);
                break;
            }
            case 5: {
                cout << "Enter Manufacturing Date (YYYY-MM-DD): ";
                cin >> input;
                medicineStack.searchByManufacturingDate(input);
                break;
            }
            case 6: return;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }
    } while (true);
}

// View all medicines
void viewMedicines() {
    medicineStack.display();
}

// Add a new medicine
void addMedicine() {
    Medicine med;
    cout << "Enter Medicine Name: ";
    cin.ignore();
    getline(cin, med.name);
    cout << "Enter Price: ";
    cin >> med.price;
    cout << "Enter Quantity: ";
    cin >> med.quantity;
    cout << "Enter Expiry Date (YYYY-MM-DD): ";
    cin >> med.expiryDate;
    cout << "Enter Manufacturing Date (YYYY-MM-DD): ";
    cin >> med.manufacturingDate;

    medicineStack.push(med);
}

// Delete the top medicine
void deleteMedicine() {
    Medicine med = medicineStack.pop();
    if (!med.name.empty()) {
        cout << "Removed Medicine: " << med.name << endl;
    }
}

// Stock Management Menu
void stockManagementMenu() {
    int choice;
    do {
        cout << "\n--- Stock Management Menu ---" << endl;
        cout << "1. View Low Stock Medicines\n";
        cout << "2. View Out of Stock Medicines\n";
        cout << "3. Go Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: medicineStack.viewLowStockMedicines(); break;
            case 2: medicineStack.viewOutOfStockMedicines(); break;
            case 3: return;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }
    } while (true);
}

// Sort Medicines Menu
void sortMedicinesMenu() {
    int choice;
    do {
        cout << "\n--- Sort Medicines Menu ---" << endl;
        cout << "1. Sort by Name\n";
        cout << "2. Sort by Price\n";
        cout << "3. Sort by Quantity\n";
        cout << "4. Sort by Expiry Date\n";
        cout << "5. Sort by Manufacturing Date\n";
        cout << "6. Go Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: medicineStack.sortByName(); break;
            case 2: medicineStack.sortByPrice(); break;
            case 3: medicineStack.sortByQuantity(); break;
            case 4: medicineStack.sortByExpiryDate(); break;
            case 5: medicineStack.sortByManufacturingDate(); break;
            case 6: return;
            default: cout << "Invalid choice. Please try again.\n"; break;
        }
    } while (true);
}
