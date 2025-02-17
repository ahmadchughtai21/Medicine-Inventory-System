#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

#define RESET "\033[0m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"

struct Medicine
{
    int id;
    string name;
    double price;
    int quantity;
    string expiryDate;
    Medicine *next;

    Medicine(int i, string n, double p, int q, string exp)
        : id(i), name(n), price(p), quantity(q), expiryDate(exp), next(nullptr) {}
};

/**
 * Medicine Queue Class
 * Implements a Queue using a circular linked list
 */
class MedicineQueue
{
private:
    Medicine *front;
    Medicine *rear;
    int count;

public:
    MedicineQueue() : front(nullptr), rear(nullptr), count(0) {}

    ~MedicineQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }

    // Checks if the queue is empty
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Adds a medicine to the queue (Enqueue)
    void enqueue(int id, string name, double price, int quantity, string expiryDate)
    {
        Medicine *newMedicine = new Medicine(id, name, price, quantity, expiryDate);
        if (isEmpty())
        {
            front = rear = newMedicine;
            rear->next = front; // Circular Link
        }
        else
        {
            rear->next = newMedicine;
            rear = newMedicine;
            rear->next = front; // Maintain circular nature
        }
        count++;

        cout << GREEN << "Medicine added successfully!" << RESET << endl;
    }

    // Removes expired medicine from queue (Dequeue)
    void autoDeleteExpired(int currentMonth, int currentYear)
    {
        if (isEmpty())
        {
            cout << RED << "No medicines available to check for expiry." << RESET << endl;
            return;
        }

        Medicine *current = front;
        Medicine *prev = nullptr;
        int expiredCount = 0;

        do
        {
            string monthStr = current->expiryDate.substr(0, 2);
            string yearStr = current->expiryDate.substr(3, 4);
            int expiryMonth = stoi(monthStr);
            int expiryYear = stoi(yearStr);

            if (expiryYear < currentYear || (expiryYear == currentYear && expiryMonth < currentMonth))
            {
                Medicine *toDelete = current;
                if (current == front)
                {
                    front = front->next;
                    rear->next = front;
                }
                else if (current == rear)
                {
                    rear = prev;
                    rear->next = front;
                }
                else
                {
                    prev->next = current->next;
                }

                cout << RED << "Deleted expired medicine: " << toDelete->name
                     << " (ID: " << toDelete->id << ", Expiry: " << toDelete->expiryDate << ")" << RESET << endl;
                delete toDelete;
                count--;
                expiredCount++;
                current = prev ? prev->next : front;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        } while (current != front);

        if (expiredCount == 0)
            cout << GREEN << "No expired medicines found." << RESET << endl;
    }

    // Displays all medicines in the queue
    void displayAll()
    {
        if (isEmpty())
        {
            cout << RED << "No medicines available." << RESET << endl;
            return;
        }

        Medicine *current = front;

        cout << CYAN << "\nAvailable Medicines:\n" << RESET;
        cout << "---------------------------------------------------\n";
        cout << setw(5) << "ID" << setw(20) << "Name"
             << setw(10) << "Price" << setw(10) << "Qty"
             << setw(15) << "Expiry Date" << endl;
        cout << "---------------------------------------------------\n";

        do
        {
            cout << setw(5) << current->id
                 << setw(20) << current->name
                 << setw(10) << fixed << setprecision(2) << current->price
                 << setw(10) << current->quantity
                 << setw(15) << current->expiryDate << endl;
            current = current->next;
        } while (current != front);
    }

    // Search medicine by name
    void searchByName(const string &name)
    {
        if (isEmpty())
        {
            cout << RED << "No medicines available." << RESET << endl;
            return;
        }

        Medicine *current = front;
        bool found = false;

        do
        {
            if (current->name == name)
            {
                cout << GREEN << "Medicine Found - ID: " << current->id << ", Expiry: " << current->expiryDate << RESET << endl;
                found = true;
                break;
            }
            current = current->next;
        } while (current != front);

        if (!found)
            cout << RED << "Medicine not found!" << RESET << endl;
    }

    // Search medicine by ID
    void searchById(int id)
    {
        if (isEmpty())
        {
            cout << RED << "No medicines available." << RESET << endl;
            return;
        }

        Medicine *current = front;
        bool found = false;

        do
        {
            if (current->id == id)
            {
                cout << GREEN << "Medicine Found - Name: " << current->name << ", Expiry: " << current->expiryDate << RESET << endl;
                found = true;
                break;
            }
            current = current->next;
        } while (current != front);

        if (!found)
            cout << RED << "Medicine not found!" << RESET << endl;
    }

    // Update medicine details by ID
    void updateMedicine(int id)
    {
        if (isEmpty())
        {
            cout << RED << "No medicines available." << RESET << endl;
            return;
        }

        Medicine *current = front;

        do
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

                cout << GREEN << "Medicine details updated successfully!" << RESET << endl;
                return;
            }
            current = current->next;
        } while (current != front);

        cout << RED << "Medicine not found!" << RESET << endl;
    }

    int getCount() const { return count; }
};
