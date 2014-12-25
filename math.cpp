/*
 * =====================================================================================
 *
 *       Filename:  math.cpp
 *
 *    Description:  math used for the number
 *
 *        Version:  1.0
 *        Created:  12/23/2014 06:16:48 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen (), gzackwebs@tfwno.gf
 *
 * =====================================================================================
 */

#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

#include "math.h"

using namespace std;

bool isPrime(int toCheck)
{
    //really needs to be improved
    if(toCheck < 2)
    {
        return false;
    }
    if(toCheck == 2)//sqrt of 2 rounded up is 2, have to do this
    {
        return true;
    }

    int upTo = ceil(sqrt(toCheck));
    for(int i = 2; i < upTo + 1; ++i)
    {
        if(toCheck % i == 0)
        {
            return false;
        }
    }
    return true;
}

vector<int> factor(int toFactor)
{
    vector<int> factors;
    for(int i = 2; i < ceil(sqrt(toFactor)) + 1; ++i)
    {
        if(isPrime(toFactor))
        {
            factors.push_back(toFactor);
            break;
        }
        if(toFactor % i == 0)
        {
            factors.push_back(i);
            toFactor = toFactor / i;
            i = 1; //will be incremented to 2
        }
    }
    return factors;
}

string decToHex(int toConvert)
{
    string hexValue;
    if(toConvert == 0)//handling 0, don't want to return an empty string
    {
        hexValue.append("0");
        return hexValue;
    }

    else if(toConvert < 0)
    {
        hexValue.append("-");
        toConvert = toConvert/-1;
    }

    int temp; //used for holding remainder
    while(toConvert != 0)
    {
        temp = toConvert % 16;
        
        switch(temp)
        {
            case 0:
                hexValue.append("0");
                break;
            case 1:
                hexValue.append("1");
                break;
            case 2:
                hexValue.append("2");
                break;
            case 3:
                hexValue.append("3");
                break;
            case 4:
                hexValue.append("4");
                break;
            case 5:
                hexValue.append("5");
                break;
            case 6:
                hexValue.append("6");
                break;
            case 7:
                hexValue.append("7");
                break;
            case 8:
                hexValue.append("8");
                break;
            case 9:
                hexValue.append("9");
                break;
            case 10:
                hexValue.append("A");
                break;
            case 11:
                hexValue.append("B");
                break;
            case 12:
                hexValue.append("C");
                break;
            case 13:
                hexValue.append("D");
                break;
            case 14:
                hexValue.append("E");
                break;
            case 15:
                hexValue.append("F");
                break;
        }

        toConvert /= 16;
    }

    reverse(hexValue.begin(),hexValue.end());//should be fixed
    return hexValue;
}
