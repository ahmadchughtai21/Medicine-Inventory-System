#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct Medicine {
    string name;
    double price;
    int quantity;
    string expiryDate;
    string manufacturingDate;
    Medicine* next;
};

class MedicineQueue {
private:
    Medicine* front;
    Medicine* rear;

public:
    MedicineQueue() {
        front = rear = nullptr;
    }

    void addMedicine(string name, double price, int quantity, string expiryDate, string manufacturingDate) {
        Medicine* newMedicine = new Medicine{name, price, quantity, expiryDate, manufacturingDate, nullptr};
        if (!rear) {
            front = rear = newMedicine;
        } else {
            rear->next = newMedicine;
            rear = newMedicine;
        }
        cout << "Medicine added successfully!\n";
    }

    void deleteMedicine(string name) {
        if (!front) {
            cout << "No medicines available to delete!\n";
            return;
        }
        Medicine* temp = front;
        Medicine* prev = nullptr;

        while (temp && temp->name != name) {
            prev = temp;
            temp = temp->next;
        }

        if (!temp) {
            cout << "Medicine not found!\n";
            return;
        }

        if (temp == front)
            front = front->next;
        else
            prev->next = temp->next;

        if (temp == rear)
            rear = prev;

        delete temp;
        cout << "Medicine deleted successfully!\n";
    }

    void viewMedicines() {
        if (!front) {
            cout << "No medicines available!\n";
            return;
        }
        Medicine* temp = front;
        while (temp) {
            cout << "Name: " << temp->name << ", Price: " << temp->price << ", Quantity: " << temp->quantity
                 << ", Expiry Date: " << temp->expiryDate << ", Manufacturing Date: " << temp->manufacturingDate << endl;
            temp = temp->next;
        }
    }

    void searchByName(string name) {
        Medicine* temp = front;
        while (temp) {
            if (temp->name == name) {
                cout << "Medicine found: " << temp->name << " - " << temp->price << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Medicine not found!\n";
    }

    void viewExpiringMedicines() {
        time_t now = time(0);
        tm* today = localtime(&now);
        char buffer[11];
        strftime(buffer, 11, "%Y-%m-%d", today);
        string currentDate(buffer);

        Medicine* temp = front;
        while (temp) {
            if (temp->expiryDate <= currentDate) {
                cout << "Expiring Medicine: " << temp->name << " - " << temp->expiryDate << endl;
            }
            temp = temp->next;
        }
    }

    void viewExpiredMedicines() {
        time_t now = time(0);
        tm* today = localtime(&now);
        char buffer[11];
        strftime(buffer, 11, "%Y-%m-%d", today);
        string currentDate(buffer);

        Medicine* temp = front;
        while (temp) {
            if (temp->expiryDate < currentDate) {
                cout << "Expired Medicine: " << temp->name << " - " << temp->expiryDate << endl;
            }
            temp = temp->next;
        }
    }

    void manageMedicinesMenu() {
        cout << "Managing medicines...\n";
        viewMedicines();
    }

    void searchMedicinesMenu() {
        cout << "Search menu selected. Please enter the medicine name: ";
        string name;
        cin >> name;
        searchByName(name);
    }

    void searchByPrice() {
    }

    void searchByQuantity() {
    }

    void searchByExpiryDate() {
    }

    void searchByManufacturingDate() {
    }

    void stockManagementMenu() {
    }

    void viewLowStockMedicines() {
    }

    void viewOutOfStockMedicines() {
    }

    void sortMedicinesMenu() {
    }

    void sortByName() {
    }

    void sortByPrice() {
    }

    void sortByQuantity() {
    }

    void sortByExpiryDate() {
    }

    void sortByManufacturingDate() {
    }

    void expiryAlertsMenu() {
        cout << "Expiry alerts menu selected.\n";
        viewExpiringMedicines();
        viewExpiredMedicines();
    }
};
