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
#include <sstream>
#include <vector>

#include "output.h"

using namespace std;

int main(int argc, char **argv)
{
    string input;
    cout << "Enter numbers you want to know about\n";
    cin >> input;
    cout << endl;
    
    vector<long> numbers;
    stringstream stream(input);

    int n;

    while(stream >> n)
    {
        numbers.push_back(n);

        if(stream.peek() == ',' || stream.peek() == ' ')
        {
            stream.ignore();
        }
    }

    /*
    for(int i = 0; i < numbers.size(); ++i)
    {
        cout << numbers.at(i) << " ";
    }
    */

    if(numbers.size() == 1)
    {
        singleNumber(numbers.at(0));
    }
    else 
    {
        multiNumber(numbers);
    }
    return 0;
}
