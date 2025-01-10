#include "linkedlist.cpp"
#include "stack.cpp"
#include "queue.cpp"
#include "compare.cpp"

#include <iostream>

using namespace std;

void manageMedicinesMenu();
void searchMedicinesMenu();

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
        // stockManagementMenu();
        break;
    case 4:
        // sortMedicinesMenu();
        break;
    case 5:
        // expiryAlertsMenu();
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
    cout << "4. Update Medicines" << endl;
    cout << "5. Back" << endl;

    cout << "Enter option: ";

    int option;
    cin >> option;

    switch (option)
    {
    case 1:
        // addMedicine();
        break;
    case 2:
        // updateMedicine();
        break;
    case 3:
        // deleteMedicine();
        break;
    case 4:
        // viewMedicines();
        break;
    case 5:
        main();
        break;
    default:
        cout << "Invalid option! Try Again" << endl;
        manageMedicinesMenu();
    }
}

void searchMedicinesMenu()
{
    cout << "Search Medicines" << endl;
    cout << "Please select an option" << endl;

    cout << "1. Search by Name" << endl;
    cout << "2. Search by ID" << endl;
    cout << "3. Back" << endl;

    cout << "Enter option: ";
    int option;
    cin >> option;

    switch (option)
    {
    case 1:
        // searchByName();
        break;
    case 2:
        // searchByID();
        break;
    case 3:
        main();
        break;
    default:
        cout << "Invalid option! Try Again" << endl;
        searchMedicinesMenu();
    }
}