#include <string>
#include <iostream>
#include <chrono>
#include <functional>
using namespace std;

// Function to measure execution time (supports functions with parameters)
double measureExecutionTime(std::function<void()> func) {
    auto start = std::chrono::high_resolution_clock::now(); // Start time
    func(); // Execute the function
    auto end = std::chrono::high_resolution_clock::now(); // End time

    std::chrono::duration<double, std::milli> duration = end - start; // Compute duration in milliseconds
    return duration.count();
}

// Example function to test
void exampleFunction(int n)
{
    for (int i = 0; i < n; i++)
        ; // Simulated work
}

void compareViewMedicines()
{
    double timeTaken = measureExecutionTime([&]() { exampleFunction(99999); });
    cout << "Execution Time: " << timeTaken << " ms" << endl;
}

void compareAddMedicine(string name, double price, int quantity, string expiryDate, string manufacturingDate, string description)
{
    // linkedListAddMedicine(name, price, quantity, expiryDate, manufacturingDate, description);
}

void compareDeleteMedicine(string name)
{
    // linkedListDeleteMedicine();
}

// search for a medicine

void compareSearchByName(string name)
{
    // linkedListSearchByName(name);
}

void compareSearchByPrice(double price)
{
    // linkedListSearchByPrice(price);
}

void compareSearchByQuantity(int quantity)
{
    // linkedListSearchByQuantity(quantity);
}

void compareSearchByExpiryDate(string expiryDate)
{
    // linkedListSearchByExpiryDate(expiryDate);
}

void compareSearchByManufacturingDate(string manufacturingDate)
{
    // linkedListSearchByManufacturingDate(manufacturingDate);
}

void compareViewLowStockMedicines()
{
    // linkedListViewLowStockMedicines();
}

void compareViewOutOfStockMedicines()
{
    // linkedListViewExpiredMedicines();
}

// sort medicines

void compareSortByName()
{
    // linkedListSortByName();
}

void compareSortByPrice()
{
    // linkedListSortByPrice();
}

void compareSortByQuantity()
{
    // linkedListSortByQuantity();
}

void compareSortByExpiryDate()
{
    // linkedListSortByExpiryDate();
}

void compareSortByManufacturingDate()
{
    // linkedListSortByManufacturingDate();
}

// expiry alerts

void compareViewExpiringMedicines()
{
    // linkedListExpiringMedicines();
}

void compareViewExpiredMedicines()
{
    // linkedListExpiredMedicines();
}