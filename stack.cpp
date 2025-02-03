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

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if the stack is full
    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    // Add a medicine to the stack
    void push(Medicine medicine) {
        if (isFull()) {
            cout << "Stack is full. Cannot add more medicines." << endl;
            return;
        }
        medicines[++top] = medicine;
        cout << "Medicine added successfully!" << endl;
    }

    // Remove a medicine from the stack
    Medicine pop() {
        if (isEmpty()) {
            cout << "Stack is empty. No medicine to remove." << endl;
            return Medicine();
        }
        return medicines[top--];
    }

    // View the top medicine in the stack
    Medicine peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return Medicine();
        }
        return medicines[top];
    }

    // Display all medicines in the stack
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

    // View medicines close to expiry
    void viewExpiringMedicines() {
        Date currentDate = getCurrentDate();
        bool found = false;

        cout << "\n--- Medicines Close to Expiry (Within 30 Days) ---" << endl;
        for (int i = 0; i <= top; i++) {
            Date expiryDate = stringToDate(medicines[i].expiryDate);
            if (isCloseToExpiry(expiryDate)) {
                found = true;
                cout << "Name: " << medicines[i].name << ", Expiry Date: " << medicines[i].expiryDate << endl;
            }
        }

        if (!found) {
            cout << "No medicines are close to expiry." << endl;
        }
    }

    // View expired medicines
    void viewExpiredMedicines() {
        Date currentDate = getCurrentDate();
        bool found = false;

        cout << "\n--- Expired Medicines ---" << endl;
        for (int i = 0; i <= top; i++) {
            Date expiryDate = stringToDate(medicines[i].expiryDate);

            // Calculate total days from a reference date (e.g., day 0)
            int totalDaysCurrent = currentDate.year * 365 + currentDate.month * 30 + currentDate.day;
            int totalDaysExpiry = expiryDate.year * 365 + expiryDate.month * 30 + expiryDate.day;

            // Simple check if the medicine has expired
            if (totalDaysExpiry < totalDaysCurrent) {
                found = true;
                cout << "Name: " << medicines[i].name << ", Expiry Date: " << medicines[i].expiryDate << endl;
            }
        }

        if (!found) {
            cout << "No expired medicines found." << endl;
        }
    }

    // Search for a medicine by name
    void searchByName(string name) {
        bool found = false;
        for (int i = 0; i <= top; i++) {
            if (medicines[i].name == name) {
                found = true;
                cout << "Medicine found: " << endl;
                cout << "Name: " << medicines[i].name << ", Price: " << medicines[i].price
                     << ", Quantity: " << medicines[i].quantity << ", Expiry Date: " << medicines[i].expiryDate
                     << ", Manufacturing Date: " << medicines[i].manufacturingDate << endl;
            }
        }
        if (!found) {
            cout << "Medicine not found." << endl;
        }
    }
};

// Global stack object to manage medicines
Stack medicineStack;

// Function prototypes
void manageMedicinesMenu();
void expiryAlertsMenu();
void viewMedicines();
void addMedicine();
void deleteMedicine();
void searchMedicinesMenu();
void searchByName();
void removeExpiredMedicines();
void viewExpiringMedicines();
void viewExpiredMedicines();

// Main function
int main() {
    manageMedicinesMenu();
    return 0;
}

// Manage Medicines Menu
void manageMedicinesMenu() {
    int choice;
    do {
        cout << "\n--- Manage Medicines Menu ---" << endl;
        cout << "1. View Medicines\n";
        cout << "2. Add Medicine\n";
        cout << "3. Delete Medicine\n";
        cout << "4. Search Medicines\n";
        cout << "5. Expiry Alerts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: viewMedicines(); break;
            case 2: addMedicine(); break;
            case 3: deleteMedicine(); break;
            case 4: searchMedicinesMenu(); break;
            case 5: expiryAlertsMenu(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}

// Expiry Alerts Menu
void expiryAlertsMenu() {
    int choice;
    do {
        cout << "\n--- Expiry Alerts Menu ---" << endl;
        cout << "1. View Medicines Close to Expiry\n";
        cout << "2. View Expired Medicines\n";
        cout << "3. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: viewExpiringMedicines(); break;
            case 2: viewExpiredMedicines(); break;
            case 3: cout << "Returning to main menu...\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);
}

// View all medicines
void viewMedicines() {
    medicineStack.display();
}

// Add a new medicine
void addMedicine() {
    Medicine medicine;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, medicine.name);
    cout << "Enter price: ";
    cin >> medicine.price;
    cout << "Enter quantity: ";
    cin >> medicine.quantity;
    cout << "Enter expiry date (YYYY-MM-DD): ";
    cin >> medicine.expiryDate;
    cout << "Enter manufacturing date (YYYY-MM-DD): ";
    cin >> medicine.manufacturingDate;
    medicineStack.push(medicine);
}

// Delete a medicine by name
void deleteMedicine() {
    string name;
    cout << "Enter the name of the medicine to delete: ";
    cin.ignore();
    getline(cin, name);

    bool found = false;

    // Create a temporary stack to store medicines while searching
    Stack tempStack;

    // Search for the medicine and copy others to a temporary stack
    while (!medicineStack.isEmpty()) {
        Medicine topMedicine = medicineStack.pop();

        if (topMedicine.name == name) {
            found = true;  // Medicine found, so do not push it to the tempStack
            cout << "Medicine '" << name << "' deleted successfully.\n";
        } else {
            // If the medicine is not the one we are deleting, push it to tempStack
            tempStack.push(topMedicine);
        }
    }

    // Now, push all medicines back to the original stack
    while (!tempStack.isEmpty()) {
        medicineStack.push(tempStack.pop());
    }

    if (!found) {
        cout << "Medicine with name '" << name << "' not found in stock.\n";
    }
}

// Search Medicines Menu
void searchMedicinesMenu() {
    int choice;
    do {
        cout << "\n--- Search Medicines Menu ---" << endl;
        cout << "1. Search by Name\n";
        cout << "2. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: searchByName(); break;
            case 2: cout << "Returning to main menu...\n"; break;
            default: cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 2);
}

// Search for a medicine by name
void searchByName() {
    string name;
    cout << "Enter the name of the medicine to search: ";
    cin.ignore();
    getline(cin, name);
    medicineStack.searchByName(name);
}

// View medicines close to expiry
void viewExpiringMedicines() {
    medicineStack.viewExpiringMedicines();
}

// View expired medicines
void viewExpiredMedicines() {
    medicineStack.viewExpiredMedicines();
}

