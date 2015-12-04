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
#include <cstdlib>
#include <string>
#include <sstream>
#include <vector>

#include "output.h"
#include "parse.h"

using namespace std;

int main(int argc, char** argv)
{
    vector<long> numbers;
    string input;

    if(argc == 2)
    {
        input = parseFile(argc, argv);
        if(exists(input))
        {
            numbers = readFile(input);
        }
    }
    else
    {
        cout << "Enter numbers you want to know about\n";
        cin >> input;
        cout << endl;
        
        stringstream stream(input);

        int n;

        while(stream >> n) //reading input
        {
            numbers.push_back(n);

            while(stream.peek() == ',' || stream.peek() == ' ')
            {
                stream.ignore();
            }
        }
    }
    
    /*
    for(int i = 0; i < numbers.size(); ++i)
    {
        cout << numbers.at(i) << " ";
    }
    */

    if(numbers.size() < 1) // if nothing is entered
    {
        exit(1);
    }
    else if(numbers.size() == 1) // if one number is entered
    {
        singleNumber(numbers.at(0));
    }
    else // if multiple numbers are entered
    {
        multiNumber(numbers);
    }
    return 0;
}
