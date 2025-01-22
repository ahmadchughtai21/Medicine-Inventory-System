#include "linkedlist.cpp"
#include "stack.cpp"
#include "queue.cpp"
#include "compare.cpp"

#include <iostream>

using namespace std;

void manageMedicinesMenu();
void viewMedicines();
void addMedicine();
void deleteMedicine();
void updateMedicine();
void searchMedicinesMenu();
void searchByName();
void searchByPrice();
void searchByQuantity();
void searchByExpiryDate();
void searchByManufacturingDate();
void stockManagementMenu();
void viewLowStockMedicines();
void viewOutOfStockMedicines();
void sortMedicinesMenu();
void sortByName();
void sortByPrice();
void sortByQuantity();
void sortByExpiryDate();
void sortByManufacturingDate();
void expiryAlertsMenu();
void viewExpiringMedicines();
void viewExpiredMedicines();

int main()
{
    cout << "Welcome to Medicines Inventory System" << endl;
    cout << "Please select an option" << endl;

    cout << "1. Manage Medicines" << endl;
    cout << "2. Search Medicines" << endl;
    cout << "3. Stock Management" << endl;
    cout << "4. Sort Medicines" << endl;
    cout << "5. Expiry Alerts" << endl;
    cout << "6. Generate Reports" << endl;
    cout << "7. Exit" << endl;

    cout << "Enter option: ";
    int option;
    cin >> option;

    switch (option)
    {
    case 1:
        manageMedicinesMenu();
        break;
    case 2:
        searchMedicinesMenu();
        break;
    case 3:
        stockManagementMenu();
        break;
    case 4:
        sortMedicinesMenu();
        break;
    case 5:
        expiryAlertsMenu();
        break;
    case 6:
        // generateReportsMenu();
        break;
    case 7:
        cout << "Exiting..." << endl;
        break;
    default:
        cout << "Invalid option! Try Again" << endl;
        main();
    }

    return 0;
}

void manageMedicinesMenu()
{
    cout << "Manage Medicines" << endl;
    cout << "Please select an option" << endl;

    cout << "1. View Medicines" << endl;
    cout << "2. Add Medicine" << endl;
    cout << "3. Delete Medicine" << endl;
    cout << "4. Update Medicine" << endl;
    cout << "5. Back" << endl;

    cout << "Enter option: ";

    int option;
    cin >> option;

    switch (option)
    {
    case 1:
        viewMedicines();
        break;
    case 2:
        addMedicine();
        break;
    case 3:
        deleteMedicine();
        break;
    case 4:
        updateMedicine();
        break;
    case 5:
        main();
        break;
    default:
        cout << "Invalid option! Try Again" << endl;
        manageMedicinesMenu();
    }
}

void viewMedicines()
{
    compareViewMedicines();
}

void addMedicine()
{
    cout << "Add Medicine" << endl;
    cout << "Please enter the following details" << endl;

    cout << "Name: ";
    string name;
    cin >> name;

    cout << "Price: ";
    double price;
    cin >> price;

    cout << "Quantity: ";
    int quantity;
    cin >> quantity;

    cout << "Expiry Date: ";
    string expiryDate;
    cin >> expiryDate;

    cout << "Manufacturing Date: ";
    string manufacturingDate;
    cin >> manufacturingDate;

    cout << "Description: ";
    string description;
    cin >> description;

    compareAddMedicine(name, price, quantity, expiryDate, manufacturingDate, description);
}

void deleteMedicine()
{
    cout << "Delete Medicine" << endl;
    cout << "Please enter the name of the medicine you want to delete" << endl;

    string name;
    cin >> name;

    compareDeleteMedicine(name);
}

void updateMedicine()
{
    cout << "Update Medicine" << endl;
    cout << "Please enter the name of the medicine you want to update" << endl;

    string name;
    cin >> name;

    compareDeleteMedicine(name);
    addMedicine();
}

void searchMedicinesMenu()
{
    cout << "Search Medicines" << endl;
    cout << "Please select an option" << endl;

    cout << "1. Search by Name" << endl;
    cout << "2. Search by Price" << endl;
    cout << "3. Search by Quantity" << endl;
    cout << "4. Search by Expiry Date" << endl;
    cout << "5. Search by Manufacturing Date" << endl;
    cout << "6. Back" << endl;

    cout << "Enter option: ";

    int option;
    cin >> option;

    switch (option)
    {
    case 1:
        searchByName();
        break;
    case 2:
        searchByPrice();
        break;
    case 3:
        searchByQuantity();
        break;
    case 4:
        searchByExpiryDate();
        break;
    case 5:
        searchByManufacturingDate();
        break;
    case 6:
        main();
        break;
    default:
        cout << "Invalid option! Try Again" << endl;
        searchMedicinesMenu();
    }
}

void searchByName()
{
    cout << "Search by Name" << endl;
    cout << "Please enter the name of the medicine you want to search" << endl;

    string name;
    cin >> name;

    compareSearchByName(name);
}

void searchByPrice()
{
    cout << "Search by Price" << endl;
    cout << "Please enter the price of the medicine you want to search" << endl;

    double price;
    cin >> price;

    compareSearchByPrice(price);
}

void searchByQuantity()
{
    cout << "Search by Quantity" << endl;
    cout << "Please enter the quantity of the medicine you want to search" << endl;

    int quantity;
    cin >> quantity;

    compareSearchByQuantity(quantity);
}

void searchByExpiryDate()
{
    cout << "Search by Expiry Date" << endl;
    cout << "Please enter the expiry date of the medicine you want to search" << endl;

    string expiryDate;
    cin >> expiryDate;

    compareSearchByExpiryDate(expiryDate);
}

void searchByManufacturingDate()
{
    cout << "Search by Manufacturing Date" << endl;
    cout << "Please enter the manufacturing date of the medicine you want to search" << endl;

    string manufacturingDate;
    cin >> manufacturingDate;

    compareSearchByManufacturingDate(manufacturingDate);
}

void stockManagementMenu()
{
    cout << "Stock Management" << endl;
    cout << "Please select an option" << endl;

    cout << "1. View Low Stock Medicines" << endl;
    cout << "2. View Out-of-Stock Medicines" << endl;
    cout << "3. Back" << endl;

    cout << "Enter option: ";

    int option;
    cin >> option;

    switch (option)
    {
    case 1:
        viewLowStockMedicines();
        break;
    case 2:
        viewOutOfStockMedicines();
        break;
    case 3:
        main();
        break;
    default:
        cout << "Invalid option! Try Again" << endl;
        stockManagementMenu();
    }
}

void viewLowStockMedicines()
{
    cout << "View Low Stock Medicines" << endl;
    compareViewLowStockMedicines();
}

void viewOutOfStockMedicines()
{
    cout << "View Out-of-Stock Medicines" << endl;
    compareViewOutOfStockMedicines();
}

void sortMedicinesMenu()
{
    cout << "Sort Medicines" << endl;
    cout << "Please select an option" << endl;

    cout << "1. Sort by Name" << endl;
    cout << "2. Sort by Price" << endl;
    cout << "3. Sort by Quantity" << endl;
    cout << "4. Sort by Expiry Date" << endl;
    cout << "5. Sort by Manufacturing Date" << endl;
    cout << "6. Back" << endl;

    cout << "Enter option: ";

    int option;
    cin >> option;

    switch (option)
    {
    case 1:
        sortByName();
        break;
    case 2:
        sortByPrice();
        break;
    case 3:
        sortByQuantity();
        break;
    case 4:
        sortByExpiryDate();
        break;
    case 5:
        sortByManufacturingDate();
        break;
    case 6:
        main();
        break;
    default:
        cout << "Invalid option! Try Again" << endl;
        sortMedicinesMenu();
    }
}

void sortByName()
{
    cout << "Sort by Name" << endl;
    compareSortByName();
}

void sortByPrice()
{
    cout << "Sort by Price" << endl;
    compareSortByPrice();
}

void sortByQuantity()
{
    cout << "Sort by Quantity" << endl;
    compareSortByQuantity();
}

void sortByExpiryDate()
{
    cout << "Sort by Expiry Date" << endl;
    compareSortByExpiryDate();
}

void sortByManufacturingDate()
{
    cout << "Sort by Manufacturing Date" << endl;
    compareSortByManufacturingDate();
}

void expiryAlertsMenu()
{
    cout << "Expiry Alerts" << endl;
    cout << "Please select an option" << endl;

    cout << "1. View Expiring Medicines" << endl;
    cout << "2. View Expired Medicines" << endl;
    cout << "3. Back" << endl;

    cout << "Enter option: ";

    int option;
    cin >> option;

    switch (option)
    {
    case 1:
        viewExpiringMedicines();
        break;
    case 2:
        viewExpiredMedicines();
        break;
    case 3:
        main();
        break;
    default:
        cout << "Invalid option! Try Again" << endl;
        expiryAlertsMenu();
    }
}

void viewExpiringMedicines()
{
    cout << "View Expiring Medicines" << endl;
    compareViewExpiringMedicines();
}

void viewExpiredMedicines()
{
    cout << "View Expired Medicines" << endl;
    compareViewExpiredMedicines();
}
