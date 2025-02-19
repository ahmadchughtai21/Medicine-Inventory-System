#ifndef GLOBALS_H
#define GLOBALS_H

#include <iostream>
#include <string>

using namespace std;

// Terminal color codes for better user interface feedback
#define RESET "\033[0m"
#define BLUE "\033[34m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"

/**
 * Input validation helper functions
 */
bool isDigit(char c)
{
    return (c >= '0' && c <= '9');
}

bool isValidMonth(int month)
{
    return month >= 1 && month <= 12;
}

bool isValidYear(int year)
{
    return year >= 2000 && year <= 9999;
}

/**
 * Validates expiry date format (MM/YYYY)
 * Returns true if format is valid and month is between 1-12
 */
bool isValidExpiryFormat(const string &expiryDate)
{
    if (expiryDate.length() != 7 || expiryDate[2] != '/')
        return false;

    string monthStr = expiryDate.substr(0, 2);
    string yearStr = expiryDate.substr(3, 4);

    for (char c : monthStr)
        if (!isDigit(c))
            return false;
    for (char c : yearStr)
        if (!isDigit(c))
            return false;

    int month = stoi(monthStr);
    return (month >= 1 && month <= 12);
}

/**
 * Gets current date from user with validation
 * Returns false if input is invalid
 */
bool getCurrentDate(int &month, int &year)
{
    cout << "Enter current month (1-12): ";
    cin >> month;
    if (!isValidMonth(month))
    {
        cout << RED << "Invalid month! Please enter a number between 1 and 12." << RESET << endl;
        return false;
    }

    cout << "Enter current year (YYYY): ";
    cin >> year;
    if (!isValidYear(year))
    {
        cout << RED << "Invalid year! Please enter a valid year (2000-9999)." << RESET << endl;
        return false;
    }
    return true;
}

string inputExpiryDate()
{
    string expiryDate;
    do
    {
        cout << "Enter expiry date (MM/YYYY): ";
        cin >> expiryDate;
        if (!isValidExpiryFormat(expiryDate))
        {
            cout << RED << "Invalid format! Please enter in MM/YYYY format." << RESET << endl;
        }
    } while (!isValidExpiryFormat(expiryDate));
    return expiryDate;
}

// struct Medicine
// {
//     int id;
//     string name;
//     double price;
//     int quantity;
//     string expiryDate;
//     Medicine *next;
//     Medicine *prev;

//     // Default constructors
//     Medicine(int i, string n, double p, int q, string exp) : id(i), name(n), price(p), quantity(q), expiryDate(exp), next(nullptr), prev(nullptr) {}
// };

#endif