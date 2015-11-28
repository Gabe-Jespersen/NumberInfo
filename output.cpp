/*
 * =====================================================================================
 *
 *       Filename:  output.cpp
 *
 *    Description:  for organizing the output, takes in numbers, puts out stats
 *
 *        Version:  1.0
 *        Created:  01/18/2015 04:26:37 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen (), gzackwebs@tfwno.gf
 *   Organization:  
 *
 * =====================================================================================
 */

#include <vector>
#include <string>
#include <iostream>

#include "output.h"
#include "math.h"

using namespace std;

void singleNumber(long number)
{
    cout << number << " is ";
    if(isEven(number))
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
        vector<long> factors = factor(number);
        short numberOfFactors = factors.size();//cannot have more than 64 factors

        cout << "Prime factors of " << number << " are ";

        //print factors from vector
        if(numberOfFactors > 2)
        {
            for(short i = 0; i < numberOfFactors - 1; ++i)
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
    string binNumber = decToBin(number);
    cout << number << " in hexadecimal is " << hexNumber << endl;
    cout << number << " in binary is "      << binNumber << endl;
    return;
}

void multiNumber(vector<long> numbers)
{
    cout << "Sum: " << sum(numbers) << endl;
    cout << "Average: " << average(numbers) << endl;
    cout << "Median: " << median(numbers) << endl;
    cout << "Standard Deviation: " << standardDeviation(numbers) << endl;
    cout << "Root Mean Square: " << rootMeanSquare(numbers) << endl;
    return;
}
