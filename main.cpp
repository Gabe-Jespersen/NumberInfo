/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  main file
 *
 *        Version:  1.0
 *        Created:  12/23/2014 06:14:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen, gzackwebs@tfwno.gf
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>
#include <vector>

#include "math.h"

using namespace std;

int main(int argc, char **argv)
{
    int number;
    cout << "Enter a number you want to know about\n";
    cin >> number;
    cout << endl;

    cout << number << " is ";
    if(number % 2 == 0)
    {
        cout << "even\n";
    }
    else
    {
        cout << "odd\n";
    }

    bool numberPrime = isPrime(number);
    if(numberPrime)
    {
        cout << number << " is prime\n";
    }
    else
    {
        cout << number << " is not prime\n";//covering -1-1
    }

    if(!numberPrime && (number < -2 || number > 2))
    {
        vector<int> factors = factor(number);
        int numberOfFactors = factors.size();

        cout << "Prime factors of " << number << " are ";

        //print factors from vector
        if(numberOfFactors > 2)
        {
            for(int i = 0; i < numberOfFactors - 1; ++i)
            {
                cout << factors.at(i) << ", ";
            }
        }
        else
        {
            cout << factors.at(0) << " ";
        }
        //print last one
        cout << "and " << factors.at(numberOfFactors-1) << endl;
    }

    string hexNumber = decToHex(number);
    cout << number << " in hexadecimal is " << hexNumber << endl;

    cout << endl;
    return 0;
}
