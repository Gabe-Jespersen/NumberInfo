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
#include <sstream>
//temp
#include <iostream>


#include "math.h"

using namespace std;

bool isEven(long toCheck)
{
    if(toCheck % 2 == 0)
    {
        return true;
    }
    return false;
}

bool isPrime(long toCheck)
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

    unsigned int upTo = ceil(sqrt(toCheck));//needs to go up to 3.1 billion
    for(unsigned int i = 2; i < upTo + 1; ++i)
    {
        if(toCheck % i == 0)
        {
            return false;
        }
    }
    return true;
}

vector<long> factor(long toFactor)
{
    vector<long> factors;

    if(toFactor < 0)
    {
        factors.push_back(-1);
    }

    for(unsigned int i = 2; i < ceil(sqrt(toFactor)) + 1; ++i)
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

string decToHex(long toConvert)
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

string decToBin(long toConvert)
{
    string toReturn;

    if(toConvert == 0)//handling 0, don't want to return an empty string
    {
        toReturn.append("0");
        return toReturn;
    }

    else if(toConvert < 0)
    {
        toReturn.append("-");
        toConvert = toConvert/-1;
    }

    int temp; //used for holding remainder
    while(toConvert != 0)
    {
        temp = toConvert % 2;
        if(!temp)
        {
            toReturn.append("0");
        }
        else
        {
            toReturn.append("1");
        }

        toConvert /= 2;
    }
        
    reverse(toReturn.begin(),toReturn.end());//reversing order
    return toReturn;
}

long sum(vector<long> numbers)
{
    long toReturn = 0;
    for(int i = 0; i < numbers.size(); ++i)
    {
        toReturn += numbers.at(i);
    }
    return toReturn;
}

double average(vector<long> numbers)
{
    double toReturn = sum(numbers);
    toReturn /= numbers.size();
    return toReturn;
}

double standardDeviation(vector<long> numbers)
{
    double toReturn = average(numbers);
    for(int i = 0; i < numbers.size(); ++i)
    {
        numbers.at(i) = pow(numbers.at(i)-toReturn,2);//squaring initial vlaue minus average
    }
    toReturn = sqrt(average(numbers));
    return toReturn;
}

vector<long> bubbleSort(vector<long> toSort)
{
    bool inOrder = true;
    int size = toSort.size();
    int temp;
    do
    {
        inOrder = true;
        for(int i = 0; i < size-1; i++)
        {
            if(toSort.at(i)>toSort.at(i+1))
            {
                inOrder = false;
                temp = toSort.at(i);
                toSort[i] = toSort.at(i+1);
                toSort[i+1] = temp;
            }
        }
    }
    while(!inOrder);
    return toSort;
}

long median(vector<long> numbers)
{
    numbers = bubbleSort(numbers);
    int size = numbers.size();
    if(size % 2 == 0)
    {
        return((numbers.at(size/2 - 1) + numbers.at(size/2))/2);
    }
    else
    {
        return(numbers.at(size/2));
    }
}

double rootMeanSquare(vector<long> numbers)
{
    double sqrtSumOfSquares = 0;
    for(int i = 0; i < numbers.size(); ++i)
    {
        sqrtSumOfSquares += pow(numbers.at(i),2);
    }
    sqrtSumOfSquares = sqrt(sqrtSumOfSquares);

    double sqrtOfCount = sqrt(numbers.size());
    
    double answer = sqrtSumOfSquares/sqrtOfCount;

    return answer;
}
