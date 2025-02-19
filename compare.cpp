#include <string>
#include <iostream>
#include <chrono>
#include <functional>
using namespace std;

// Function to measure execution time (supports functions with parameters)
double measureExecutionTime(std::function<void()> func)
{
    auto start = std::chrono::high_resolution_clock::now(); // Start time
    func();                                                 // Execute the function
    auto end = std::chrono::high_resolution_clock::now();   // End time

    std::chrono::duration<double, std::milli> duration = end - start; // Compute duration in milliseconds
    return duration.count();
}

void compareAddMedicines(int id, string name, double price, int quantity, string expiryDate)
{
    int newId = id;
    int quantity1 = quantity;
    string name1 = name;
    double price1 = price;
    string expiryDate1 = expiryDate;

    double timeTaken = measureExecutionTime([&]()
                                            { addMedicineLink(newId, name1, price1, quantity1, expiryDate1); });
    cout << "Execution Time: " << timeTaken << " ms" << endl;

    double timeTaken1 = measureExecutionTime([&]()
                                             { addMedicineQ(newId, name1, price1, quantity1, expiryDate1); });
    cout << "Execution Time: " << timeTaken1 << " ms" << endl;

    double timeTaken2 = measureExecutionTime([&]()
                                             { addMedicineS(newId, name1, price1, quantity1, expiryDate1); });
    cout << "Execution Time: " << timeTaken2 << " ms" << endl;
}

void compareSearchByName(string searchName)
{
    string searchName1 = searchName;

    double timeTaken = measureExecutionTime([&]()
                                            { searchByNameLink(searchName1); });
    cout << "Execution Time: " << timeTaken << " ms" << endl;

    double timeTaken1 = measureExecutionTime([&]()
                                             { searchByNameQ(searchName1); });
    cout << "Execution Time: " << timeTaken1 << " ms" << endl;

    double timeTaken2 = measureExecutionTime([&]()
                                             { searchByNameS(searchName1); });
    cout << "Execution Time: " << timeTaken2 << " ms" << endl;
}

void compareSearchById(int searchId)
{
    int searchId1 = searchId;

    double timeTaken = measureExecutionTime([&]()
                                            { searchByIdLink(searchId1); });
    cout << "Execution Time: " << timeTaken << " ms" << endl;

    double timeTaken1 = measureExecutionTime([&]()
                                             { searchByIdQ(searchId1); });
    cout << "Execution Time: " << timeTaken1 << " ms" << endl;

    double timeTaken2 = measureExecutionTime([&]()
                                             { searchByIdS(searchId1); });
    cout << "Execution Time: " << timeTaken2 << " ms" << endl;
}

void compareSearchByExpiryDate(string expiryDate)
{
    string expiryDate1 = expiryDate;

    double timeTaken = measureExecutionTime([&]()
                                            { searchByExpiryDateLink(expiryDate1); });
    cout << "Execution Time: " << timeTaken << " ms" << endl;

    double timeTaken1 = measureExecutionTime([&]()
                                             { searchByExpiryDateQ(expiryDate1); });
    cout << "Execution Time: " << timeTaken1 << " ms" << endl;

    double timeTaken2 = measureExecutionTime([&]()
                                             { searchByExpiryDateS(expiryDate1); });
    cout << "Execution Time: " << timeTaken2 << " ms" << endl;
}

void compareSortByName()
{
    double timeTaken = measureExecutionTime([&]()
                                            { sortByNameLink(); });
    cout << "Execution Time: " << timeTaken << " ms" << endl;

    double timeTaken1 = measureExecutionTime([&]()
                                             { sortByNameQ(); });
    cout << "Execution Time: " << timeTaken1 << " ms" << endl;

    double timeTaken2 = measureExecutionTime([&]()
                                             { sortByNameS(); });
    cout << "Execution Time: " << timeTaken2 << " ms" << endl;
}

void compareDisplayAll()
{
    double timeTaken = measureExecutionTime([&]()
                                            { displayAllLink(); });
    cout << "Execution Time: " << timeTaken << " ms" << endl;

    double timeTaken1 = measureExecutionTime([&]()
                                             { displayAllQ(); });
    cout << "Execution Time: " << timeTaken1 << " ms" << endl;

    double timeTaken2 = measureExecutionTime([&]()
                                             { displayAllS(); });
    cout << "Execution Time: " << timeTaken2 << " ms" << endl;
}

void compareSortById()
{
    double timeTaken = measureExecutionTime([&]()
                                            { sortByIdLink(); });
    cout << "Execution Time: " << timeTaken << " ms" << endl;

    double timeTaken1 = measureExecutionTime([&]()
                                             { sortByIdQ(); });
    cout << "Execution Time: " << timeTaken1 << " ms" << endl;

    double timeTaken2 = measureExecutionTime([&]()
                                             { sortByIdS(); });
    cout << "Execution Time: " << timeTaken2 << " ms" << endl;
}

void compareSortByExpiryDate()
{
    double timeTaken = measureExecutionTime([&]()
                                            { sortByExpiryDateLink(); });
    cout << "Execution Time: " << timeTaken << " ms" << endl;

    double timeTaken1 = measureExecutionTime([&]()
                                             { sortByExpiryDateQ(); });
    cout << "Execution Time: " << timeTaken1 << " ms" << endl;

    double timeTaken2 = measureExecutionTime([&]()
                                             { sortByExpiryDateS(); });
    cout << "Execution Time: " << timeTaken2 << " ms" << endl;
}

void compareGetCount()
{
    double timeTaken = measureExecutionTime([&]()
                                            { getCountLink(); });
    cout << "Execution Time: " << timeTaken << " ms" << endl;

    double timeTaken1 = measureExecutionTime([&]()
                                             { getCountQ(); });
    cout << "Execution Time: " << timeTaken1 << " ms" << endl;

    double timeTaken2 = measureExecutionTime([&]()
                                             { getCountS(); });
    cout << "Execution Time: " << timeTaken2 << " ms" << endl;
}

void compareAutoDeleteExpired(int currentMonth, int currentYear)
{
    int currentMonth1 = currentMonth;
    int currentYear1 = currentYear;

    double timeTaken = measureExecutionTime([&]()
                                            { autoDeleteExpiredLink(currentMonth1, currentYear1); });
    cout << "Execution Time: " << timeTaken << " ms" << endl;

    double timeTaken1 = measureExecutionTime([&]()
                                             { autoDeleteExpiredQ(currentMonth1, currentYear1); });
    cout << "Execution Time: " << timeTaken1 << " ms" << endl;

    double timeTaken2 = measureExecutionTime([&]()
                                             { autoDeleteExpiredS(currentMonth1, currentYear1); });
    cout << "Execution Time: " << timeTaken2 << " ms" << endl;
}

void compareUpdateMedicine(int id)
{
    int id1 = id;

    double timeTaken = measureExecutionTime([&]()
                                            { updateMedicineLink(id1); });
    cout << "Execution Time: " << timeTaken << " ms" << endl;

    double timeTaken1 = measureExecutionTime([&]()
                                             { updateMedicineQ(id1); });
    cout << "Execution Time: " << timeTaken1 << " ms" << endl;

    double timeTaken2 = measureExecutionTime([&]()
                                             { updateMedicineS(id1); });
    cout << "Execution Time: " << timeTaken2 << " ms" << endl;
}