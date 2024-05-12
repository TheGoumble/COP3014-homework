/*
Javier Vargas - 04/05/2024 - Assignment 5
*/


#include "rationalsJV.h"
#include <iostream>
#include <sstream>

using namespace std;
using namespace JV;

Rational Checker(string prompt);

int main()
{
    Rational test1 = Checker("Enter a rational number for test 1 (numerator/denominator): ");

    Rational test2 = Checker("Enter a rational number for test 2 (numerator/denominator): ");

    cout << "\nTest 1 number: " << test1 << endl;
    cout << "Test 2 number: " << test2 << endl << endl;


    // Compute mathamatics operations
    Rational sum = test1 + test2;
    Rational difference = test1 - test2;
    Rational product = test1 * test2;
    Rational quotient = test1 / test2;

    // Output
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Product: " << product << endl;
    cout << "Quotient: " << quotient << endl;

    // Compute comparison operations
    cout << "\nComparison: " << endl;
    cout << "Test1 == Test2: " << boolalpha << (test1 == test2) << endl; // inorder to output True or false
    cout << "Test1 < Test2: " << boolalpha << (test1 < test2) << endl;
    cout << "Test1 <= Test2: " << boolalpha << (test1 <= test2) << endl;
    cout << "Test1 > Test2: " << boolalpha << (test1 > test2) << endl;
    cout << "Test1 >= Test2: " << boolalpha << (test1 >= test2) << endl;
    cout << "Test1 != Test2: " << boolalpha << (test1 != test2) << endl;

    cout << "\nUnary Minus:" << endl;
    Rational negation = -test1;
    cout << "Negation of Test 1: " << negation << endl;
}

Rational Checker(string prompt) { // allow for classes to be params https://stackoverflow.com/questions/1896369/how-to-use-a-class-object-in-c-as-a-function-parameter

    string input;
    Rational object;

    while (true) {
        cout << prompt << endl;
        getline(cin, input);  // Read the entire line as a string

        if (input.empty()) {
            cout << "Invalid input. Please enter again: ";
            continue;
        }

        // Check if the input contains '/'
        size_t pos = input.find('/');
        if (pos != string::npos) {
            // If '/' is present, parse numerator and denominator
            int num, denom;
            if (sscanf_s(input.c_str(), "%d/%d", &num, &denom) == 2 && denom != 0) {
                object = Rational(num, denom);
                break;
            }
            else if (pos == 0) {
                // Denominator only
                int denom;
                if (sscanf_s(input.c_str(), "/%d", &denom) == 1 && denom != 0) {
                    object = Rational(0, denom);
                    break;
                }
            }
        }
        else {
            // No '/' found, try to parse as a whole number
            int num;
            if (sscanf_s(input.c_str(), "%d", &num) == 1) {
                object = Rational(num);
                break;
            }
        }

        cout << "Invalid input. Please enter again: ";
    }
    return object;
}