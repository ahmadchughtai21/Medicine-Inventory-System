#include "linkedlist.cpp"
#include "stack.cpp"
#include "queue.cpp"
#include "compare.cpp"

#include <iostream>

using namespace std;

// Main program with menu-driven interface
int main()
{
main:
    cout << "1. Linked List" << endl;
    cout << "2. Stack" << endl;
    cout << "3. Queue" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        MedicineListLinkedList medicineList;
        int choice;

        cout << "\n"
             << "=============================================" << endl;
        cout << GREEN << "    Welcome To Medicine Management System" << RESET << endl;
        cout << "=============================================" << endl;

        do
        {
            // Display menu options
            cout << "\n-----------------------------------" << endl;
            cout << CYAN << "    Medicine Management System" << RESET << endl;
            cout << "-----------------------------------\n"
                 << endl;
            cout << "1. Add Medicine\n";
            cout << "2. Search by Name\n";
            cout << "3. Search by ID\n";
            cout << "4. Search by Expiry Date\n";
            cout << "5. Sort by Name\n";
            cout << "6. Sort by ID\n";
            cout << "7. Sort by Expiry Date\n";
            cout << "8. Display All Medicines\n";
            cout << "9. Update Medicine\n";
            cout << "10. Auto-Delete Expired\n";
            cout << "0. Back\n";
            cout << "Enter your choice: ";

            // Input validation for menu choice
            if (!(cin >> choice))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << RED << "Invalid input! Please enter a number." << RESET << endl;
                continue;
            }

            // Process user choice
            switch (choice)
            {
            case 1:
            { // Add Medicine
                int newId;
                cout << "Enter medicine ID: ";
                if (!(cin >> newId))
                {
                    cout << RED << "Invalid ID! Please enter a number." << RESET << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                if (!medicineList.isIdUnique(newId))
                {
                    cout << RED << "ID already exists! Please use a unique ID." << RESET << endl;
                    continue;
                }

                string name;
                cout << "Enter medicine name: ";
                cin.ignore();
                getline(cin, name);

                double price;
                cout << "Enter medicine price: ";
                cin >> price;

                int quantity;
                cout << "Enter medicine quantity: ";
                cin >> quantity;

                string expiryDate = inputExpiryDate();

                medicineList.addMedicine(newId, name, price, quantity, expiryDate);
                break;
            }

            case 2:
            { // Search by Name
                string searchName;
                cout << "Enter medicine name to search: ";
                cin.ignore();
                getline(cin, searchName);
                medicineList.searchByName(searchName);
                break;
            }
            case 3:
            { // Search by ID
                int searchId;
                cout << "Enter medicine ID to search: ";
                cin >> searchId;
                medicineList.searchById(searchId);
                break;
            }

            case 4:
            { // Search by Expiry Date
                string searchExpiry = inputExpiryDate();
                medicineList.searchByExpiryDate(searchExpiry);
                break;
            }

            case 5:
            { // Sort by Name
                medicineList.sortByName();
                cout << GREEN << "Medicines sorted by name successfully!" << RESET << endl;
                medicineList.displayAll(); // Show sorted results
                break;
            }

            case 6:
            { // Sort by ID
                medicineList.sortById();
                cout << GREEN << "Medicines sorted by ID successfully!" << RESET << endl;
                medicineList.displayAll(); // Show sorted results
                break;
            }

            case 7:
            { // Sort by Expiry Date
                medicineList.sortByExpiryDate();
                cout << GREEN << "Medicines sorted by expiry date successfully!" << RESET << endl;
                medicineList.displayAll(); // Show sorted results
                break;
            }

            case 8:
            { // Display All Medicines
                medicineList.displayAll();
                break;
            }

            case 9:
            { // Update Medicine
                // Check if there are any medicines to update
                if (medicineList.getCount() == 0)
                {
                    cout << RED << "No medicines available to update." << RESET << endl;
                    break;
                }

                // Get and validate medicine ID
                int updateId;
                cout << "Enter Medicine ID to update: ";
                if (!(cin >> updateId))
                {
                    cout << RED << "Invalid ID format!" << RESET << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                // Attempt to update medicine
                if (medicineList.updateMedicine(updateId))
                {
                    cout << GREEN << "Medicine updated successfully!" << RESET << endl;
                }
                else
                {
                    cout << RED << "Medicine with ID " << updateId << " not found." << RESET << endl;
                }
                break;
            }

            case 10:
            { // Auto-Delete Expired Medicines
                // Check if there are any medicines to check
                if (medicineList.getCount() == 0)
                {
                    cout << RED << "No medicines in the system." << RESET << endl;
                    break;
                }

                // Get and validate current date
                int currentMonth, currentYear;
                if (!getCurrentDate(currentMonth, currentYear))
                {
                    break;
                }

                // Process deletion of expired medicines
                cout << YELLOW << "\nChecking for expired medicines..." << RESET << endl;
                medicineList.autoDeleteExpired(currentMonth, currentYear);
                break;
            }

            case 0:
            { // Exit Program
                goto main;
            }

            default:
            { // Invalid Choice
                cout << RED << "Invalid choice! Please enter a number between 0 and 10." << RESET << endl;
                break;
            }
            }
        } while (choice != 0);
    }
    case 2:
    {
        MedicineListStack medicineList;
        int choice;

        cout << "\n"
             << "=============================================" << endl;
        cout << GREEN << "    Welcome To Medicine Management System" << RESET << endl;
        cout << "=============================================" << endl;

        do
        {
            // Display menu options
            cout << "\n-----------------------------------" << endl;
            cout << CYAN << "    Medicine Management System" << RESET << endl;
            cout << "-----------------------------------\n"
                 << endl;
            cout << "1. Add Medicine\n";
            cout << "2. Search by Name\n";
            cout << "3. Search by ID\n";
            cout << "4. Search by Expiry Date\n";
            cout << "5. Sort by Name\n";
            cout << "6. Sort by ID\n";
            cout << "7. Sort by Expiry Date\n";
            cout << "8. Display All Medicines\n";
            cout << "9. Update Medicine\n";
            cout << "10. Auto-Delete Expired\n";
            cout << "0. Back\n";
            cout << "Enter your choice: ";

            // Input validation for menu choice
            if (!(cin >> choice))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << RED << "Invalid input! Please enter a number." << RESET << endl;
                continue;
            }

            // Process user choice
            switch (choice)
            {
            case 1:
            { // Add Medicine
                int newId;
                cout << "Enter medicine ID: ";
                if (!(cin >> newId))
                {
                    cout << RED << "Invalid ID! Please enter a number." << RESET << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                if (!medicineList.isIdUnique(newId))
                {
                    cout << RED << "ID already exists! Please use a unique ID." << RESET << endl;
                    continue;
                }

                string name;
                cout << "Enter medicine name: ";
                cin.ignore();
                getline(cin, name);

                double price;
                cout << "Enter medicine price: ";
                cin >> price;

                int quantity;
                cout << "Enter medicine quantity: ";
                cin >> quantity;

                string expiryDate = inputExpiryDate();

                medicineList.addMedicine(newId, name, price, quantity, expiryDate);
                break;
            }

            case 2:
            { // Search by Name
                string searchName;
                cout << "Enter medicine name to search: ";
                cin.ignore();
                getline(cin, searchName);
                medicineList.searchByName(searchName);
                break;
            }
            case 3:
            { // Search by ID
                int searchId;
                cout << "Enter medicine ID to search: ";
                cin >> searchId;
                medicineList.searchById(searchId);
                break;
            }

            case 4:
            { // Search by Expiry Date
                string searchExpiry = inputExpiryDate();
                medicineList.searchByExpiryDate(searchExpiry);
                break;
            }

            case 5:
            { // Sort by Name
                medicineList.sortByName();
                cout << GREEN << "Medicines sorted by name successfully!" << RESET << endl;
                medicineList.displayAll(); // Show sorted results
                break;
            }

            case 6:
            { // Sort by ID
                medicineList.sortById();
                cout << GREEN << "Medicines sorted by ID successfully!" << RESET << endl;
                medicineList.displayAll(); // Show sorted results
                break;
            }

            case 7:
            { // Sort by Expiry Date
                medicineList.sortByExpiryDate();
                cout << GREEN << "Medicines sorted by expiry date successfully!" << RESET << endl;
                medicineList.displayAll(); // Show sorted results
                break;
            }

            case 8:
            { // Display All Medicines
                medicineList.displayAll();
                break;
            }

            case 9:
            { // Update Medicine
                // Check if there are any medicines to update
                if (medicineList.getCount() == 0)
                {
                    cout << RED << "No medicines available to update." << RESET << endl;
                    break;
                }

                // Get and validate medicine ID
                int updateId;
                cout << "Enter Medicine ID to update: ";
                if (!(cin >> updateId))
                {
                    cout << RED << "Invalid ID format!" << RESET << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                // Attempt to update medicine
                if (medicineList.updateMedicine(updateId))
                {
                    cout << GREEN << "Medicine updated successfully!" << RESET << endl;
                }
                else
                {
                    cout << RED << "Medicine with ID " << updateId << " not found." << RESET << endl;
                }
                break;
            }

            case 10:
            { // Auto-Delete Expired Medicines
                // Check if there are any medicines to check
                if (medicineList.getCount() == 0)
                {
                    cout << RED << "No medicines in the system." << RESET << endl;
                    break;
                }

                // Get and validate current date
                int currentMonth, currentYear;
                if (!getCurrentDate(currentMonth, currentYear))
                {
                    break;
                }

                // Process deletion of expired medicines
                cout << YELLOW << "\nChecking for expired medicines..." << RESET << endl;
                medicineList.autoDeleteExpired(currentMonth, currentYear);
                break;
            }

            case 0:
            { // Exit Program
                goto main;
            }

            default:
            { // Invalid Choice
                cout << RED << "Invalid choice! Please enter a number between 0 and 10." << RESET << endl;
                break;
            }
            }
        } while (choice != 0);
    }
    case 3:
    {
        MedicineListQueue medicineList;
        int choice;

        cout << "\n"
             << "=============================================" << endl;
        cout << GREEN << "    Welcome To Medicine Management System" << RESET << endl;
        cout << "=============================================" << endl;

        do
        {
            // Display menu options
            cout << "\n-----------------------------------" << endl;
            cout << CYAN << "    Medicine Management System" << RESET << endl;
            cout << "-----------------------------------\n"
                 << endl;
            cout << "1. Add Medicine\n";
            cout << "2. Search by Name\n";
            cout << "3. Search by ID\n";
            cout << "4. Search by Expiry Date\n";
            cout << "5. Sort by Name\n";
            cout << "6. Sort by ID\n";
            cout << "7. Sort by Expiry Date\n";
            cout << "8. Display All Medicines\n";
            cout << "9. Update Medicine\n";
            cout << "10. Auto-Delete Expired\n";
            cout << "0. Back\n";
            cout << "Enter your choice: ";

            // Input validation for menu choice
            if (!(cin >> choice))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << RED << "Invalid input! Please enter a number." << RESET << endl;
                continue;
            }

            // Process user choice
            switch (choice)
            {
            case 1:
            { // Add Medicine
                int newId;
                cout << "Enter medicine ID: ";
                if (!(cin >> newId))
                {
                    cout << RED << "Invalid ID! Please enter a number." << RESET << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                if (!medicineList.isIdUnique(newId))
                {
                    cout << RED << "ID already exists! Please use a unique ID." << RESET << endl;
                    continue;
                }

                string name;
                cout << "Enter medicine name: ";
                cin.ignore();
                getline(cin, name);

                double price;
                cout << "Enter medicine price: ";
                cin >> price;

                int quantity;
                cout << "Enter medicine quantity: ";
                cin >> quantity;

                string expiryDate = inputExpiryDate();

                medicineList.addMedicine(newId, name, price, quantity, expiryDate);
                break;
            }

            case 2:
            { // Search by Name
                string searchName;
                cout << "Enter medicine name to search: ";
                cin.ignore();
                getline(cin, searchName);
                medicineList.searchByName(searchName);
                break;
            }
            case 3:
            { // Search by ID
                int searchId;
                cout << "Enter medicine ID to search: ";
                cin >> searchId;
                medicineList.searchById(searchId);
                break;
            }

            case 4:
            { // Search by Expiry Date
                string searchExpiry = inputExpiryDate();
                medicineList.searchByExpiryDate(searchExpiry);
                break;
            }

            case 5:
            { // Sort by Name
                medicineList.sortByName();
                cout << GREEN << "Medicines sorted by name successfully!" << RESET << endl;
                medicineList.displayAll(); // Show sorted results
                break;
            }

            case 6:
            { // Sort by ID
                medicineList.sortById();
                cout << GREEN << "Medicines sorted by ID successfully!" << RESET << endl;
                medicineList.displayAll(); // Show sorted results
                break;
            }

            case 7:
            { // Sort by Expiry Date
                medicineList.sortByExpiryDate();
                cout << GREEN << "Medicines sorted by expiry date successfully!" << RESET << endl;
                medicineList.displayAll(); // Show sorted results
                break;
            }

            case 8:
            { // Display All Medicines
                medicineList.displayAll();
                break;
            }

            case 9:
            { // Update Medicine
                // Check if there are any medicines to update
                if (medicineList.getCount() == 0)
                {
                    cout << RED << "No medicines available to update." << RESET << endl;
                    break;
                }

                // Get and validate medicine ID
                int updateId;
                cout << "Enter Medicine ID to update: ";
                if (!(cin >> updateId))
                {
                    cout << RED << "Invalid ID format!" << RESET << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                // Attempt to update medicine
                if (medicineList.updateMedicine(updateId))
                {
                    cout << GREEN << "Medicine updated successfully!" << RESET << endl;
                }
                else
                {
                    cout << RED << "Medicine with ID " << updateId << " not found." << RESET << endl;
                }
                break;
            }

            case 10:
            { // Auto-Delete Expired Medicines
                // Check if there are any medicines to check
                if (medicineList.getCount() == 0)
                {
                    cout << RED << "No medicines in the system." << RESET << endl;
                    break;
                }

                // Get and validate current date
                int currentMonth, currentYear;
                if (!getCurrentDate(currentMonth, currentYear))
                {
                    break;
                }

                // Process deletion of expired medicines
                cout << YELLOW << "\nChecking for expired medicines..." << RESET << endl;
                medicineList.autoDeleteExpired(currentMonth, currentYear);
                break;
            }

            case 0:
            { // Exit Program
                goto main;
            }

            default:
            { // Invalid Choice
                cout << RED << "Invalid choice! Please enter a number between 0 and 10." << RESET << endl;
                break;
            }
            }
        } while (choice != 0);
    }
    case 4:
    {
        cout << "\n=========================================================" << endl;
        cout << GREEN << "   Thank you for using the Medicine Management System" << RESET << endl;
        cout << "=========================================================" << endl;
        break;
    }

    default:
        cout << "Invalid choice\n";
    }
    return 0;
}