#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <stdexcept>

using namespace std;

// Structure to represent a medicine with all relevant details
struct Medicine {
    string name;           // Name of the medicine
    double price;          // Price of the medicine
    int quantity;          // Available quantity
    string expiryDate;     // Expiration date
    string manufacturingDate; // Manufacturing date
    string description;    // Optional description
    Medicine* next;        // Pointer to next medicine in queue
};

class MedicineQueueManager {
private:
    Medicine* front;  // Front of the queue
    Medicine* rear;   // Rear of the queue
    vector<Medicine*> medicineVector;  // Vector for sorting operations

    // Convert date string to timestamp for easy comparison
    time_t dateToTimestamp(const string& dateStr) {
        struct tm tm = {0};
        // Parse date string into year, month, day
        sscanf(dateStr.c_str(), "%d-%d-%d", &tm.tm_year, &tm.tm_mon, &tm.tm_mday);
        tm.tm_year -= 1900;  // Adjust year (tm uses years since 1900)
        tm.tm_mon -= 1;      // Adjust month (tm uses 0-11)
        return mktime(&tm);  // Convert to timestamp
    }

    // Rebuild vector for sorting operations
    void rebuildVector() {
        medicineVector.clear();
        Medicine* current = front;
        while (current) {
            medicineVector.push_back(current);
            current = current->next;
        }
    }

public:
    // Constructor: Initialize empty queue
    MedicineQueueManager() : front(nullptr), rear(nullptr) {}

    // Destructor: Free all allocated memory
    ~MedicineQueueManager() {
        while (front) {
            Medicine* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Add a new medicine to the queue
    void addMedicine(const string& name, double price, int quantity, 
                     const string& expiryDate, const string& manufacturingDate, 
                     const string& description = "") {
        // Create new medicine node
        Medicine* newMedicine = new Medicine{
            name, price, quantity, expiryDate, manufacturingDate, description, nullptr
        };

        // Add to queue
        if (!front) {
            front = rear = newMedicine;
        } else {
            rear->next = newMedicine;
            rear = newMedicine;
        }
        // Rebuild vector for potential sorting
        rebuildVector();
    }

    // Delete a medicine by name
    void deleteMedicine(const string& name) {
        if (!front) return;

        Medicine* current = front;
        Medicine* prev = nullptr;

        // Find medicine to delete
        while (current && current->name != name) {
            prev = current;
            current = current->next;
        }

        if (!current) return;

        // Remove medicine from queue
        if (prev) {
            prev->next = current->next;
        } else {
            front = current->next;
        }

        // Update rear if needed
        if (current == rear) {
            rear = prev;
        }

        delete current;
        rebuildVector();
    }

    // View all medicines in the queue
    void viewMedicines() {
        Medicine* current = front;
        while (current) {
            // Display detailed medicine information
            cout << "Name: " << current->name 
                 << ", Price: $" << fixed << setprecision(2) << current->price
                 << ", Quantity: " << current->quantity 
                 << ", Expiry: " << current->expiryDate 
                 << ", Manufactured: " << current->manufacturingDate << endl;
            current = current->next;
        }
    }

    // Search for medicine by name
    void searchByName(const string& name) {
        Medicine* current = front;
        while (current) {
            if (current->name == name) {
                // Display found medicine details
                cout << "Found Medicine:\n";
                cout << "Name: " << current->name 
                     << ", Price: $" << fixed << setprecision(2) << current->price
                     << ", Quantity: " << current->quantity 
                     << ", Expiry: " << current->expiryDate << endl;
                return;
            }
            current = current->next;
        }
        cout << "Medicine not found." << endl;
    }

    // Search for medicines by price
    void searchByPrice(double price) {
        Medicine* current = front;
        bool found = false;
        while (current) {
            if (current->price == price) {
                // Display all medicines matching the price
                cout << "Found Medicine:\n";
                cout << "Name: " << current->name 
                     << ", Price: $" << fixed << setprecision(2) << current->price << endl;
                found = true;
            }
            current = current->next;
        }
        if (!found) cout << "No medicines found with this price." << endl;
    }

    // Search for medicines by quantity
    void searchByQuantity(int quantity) {
        Medicine* current = front;
        bool found = false;
        while (current) {
            if (current->quantity == quantity) {
                // Display medicines with matching quantity
                cout << "Found Medicine:\n";
                cout << "Name: " << current->name 
                     << ", Quantity: " << current->quantity << endl;
                found = true;
            }
            current = current->next;
        }
        if (!found) cout << "No medicines found with this quantity." << endl;
    }

    // Search for medicines by expiry date
    void searchByExpiryDate(const string& expiryDate) {
        Medicine* current = front;
        bool found = false;
        while (current) {
            if (current->expiryDate == expiryDate) {
                // Display medicines expiring on specific date
                cout << "Found Medicine:\n";
                cout << "Name: " << current->name 
                     << ", Expiry Date: " << current->expiryDate << endl;
                found = true;
            }
            current = current->next;
        }
        if (!found) cout << "No medicines found with this expiry date." << endl;
    }

    // Search for medicines by manufacturing date
    void searchByManufacturingDate(const string& manufacturingDate) {
        Medicine* current = front;
        bool found = false;
        while (current) {
            if (current->manufacturingDate == manufacturingDate) {
                // Display medicines manufactured on specific date
                cout << "Found Medicine:\n";
                cout << "Name: " << current->name 
                     << ", Manufacturing Date: " << current->manufacturingDate << endl;
                found = true;
            }
            current = current->next;
        }
        if (!found) cout << "No medicines found with this manufacturing date." << endl;
    }

    // View medicines with low stock (default threshold: 10)
    void viewLowStockMedicines(int threshold = 10) {
        Medicine* current = front;
        bool found = false;
        while (current) {
            if (current->quantity <= threshold) {
                // Display medicines below stock threshold
                cout << "Low Stock Medicine:\n";
                cout << "Name: " << current->name 
                     << ", Quantity: " << current->quantity << endl;
                found = true;
            }
            current = current->next;
        }
        if (!found) cout << "No low stock medicines found." << endl;
    }

    // View out-of-stock medicines (zero quantity)
    void viewOutOfStockMedicines() {
        viewLowStockMedicines(0);
    }

    // Sort medicines by name
    void sortByName() {
        rebuildVector();
        sort(medicineVector.begin(), medicineVector.end(), 
             [](const Medicine* a, const Medicine* b) { 
                 return a->name < b->name; 
             });

        cout << "Medicines sorted by name:\n";
        for (auto med : medicineVector) {
            cout << "Name: " << med->name << endl;
        }
    }

    // Sort medicines by price
    void sortByPrice() {
        rebuildVector();
        sort(medicineVector.begin(), medicineVector.end(), 
             [](const Medicine* a, const Medicine* b) { 
                 return a->price < b->price; 
             });

        cout << "Medicines sorted by price:\n";
        for (auto med : medicineVector) {
            cout << "Name: " << med->name 
                 << ", Price: $" << fixed << setprecision(2) << med->price << endl;
        }
    }

    // Sort medicines by quantity
    void sortByQuantity() {
        rebuildVector();
        sort(medicineVector.begin(), medicineVector.end(), 
             [](const Medicine* a, const Medicine* b) { 
                 return a->quantity < b->quantity; 
             });

        cout << "Medicines sorted by quantity:\n";
        for (auto med : medicineVector) {
            cout << "Name: " << med->name 
                 << ", Quantity: " << med->quantity << endl;
        }
    }

    // Sort medicines by expiry date
    void sortByExpiryDate() {
        rebuildVector();
        sort(medicineVector.begin(), medicineVector.end(), 
             [this](const Medicine* a, const Medicine* b) { 
                 return dateToTimestamp(a->expiryDate) < dateToTimestamp(b->expiryDate); 
             });

        cout << "Medicines sorted by expiry date:\n";
        for (auto med : medicineVector) {
            cout << "Name: " << med->name 
                 << ", Expiry Date: " << med->expiryDate << endl;
        }
    }

    // Sort medicines by manufacturing date
    void sortByManufacturingDate() {
        rebuildVector();
        sort(medicineVector.begin(), medicineVector.end(), 
             [this](const Medicine* a, const Medicine* b) { 
                 return dateToTimestamp(a->manufacturingDate) < dateToTimestamp(b->manufacturingDate); 
             });

        cout << "Medicines sorted by manufacturing date:\n";
        for (auto med : medicineVector) {
            cout << "Name: " << med->name 
                 << ", Manufacturing Date: " << med->manufacturingDate << endl;
        }
    }

    // View medicines expiring within next 30 days
    void viewExpiringMedicines() {
        time_t now = time(0);
        time_t thirtyDaysLater = now + (30 * 24 * 60 * 60);

        Medicine* current = front;
        bool found = false;
        while (current) {
            time_t expiryTime = dateToTimestamp(current->expiryDate);
            if (expiryTime <= thirtyDaysLater && expiryTime > now) {
                // Display medicines expiring soon
                cout << "Expiring Medicine:\n";
                cout << "Name: " << current->name 
                     << ", Expiry Date: " << current->expiryDate << endl;
                found = true;
            }
            current = current->next;
        }
        if (!found) cout << "No medicines expiring soon." << endl;
    }

    // View already expired medicines
    void viewExpiredMedicines() {
        time_t now = time(0);

        Medicine* current = front;
        bool found = false;
        while (current) {
            time_t expiryTime = dateToTimestamp(current->expiryDate);
            if (expiryTime < now) {
                // Display expired medicines
                cout << "Expired Medicine:\n";
                cout << "Name: " << current->name 
                     << ", Expiry Date: " << current->expiryDate << endl;
                found = true;
            }
            current = current->next;
        }
        if (!found) cout << "No expired medicines found." << endl;
    }
};


