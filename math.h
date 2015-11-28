/*
 * =====================================================================================
 *
 *       Filename:  math.h
 *
 *    Description:  header file for math.cpp
 *
 *        Version:  1.0
 *        Created:  12/23/2014 06:30:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen (), gzackwebs@tfwno.gf
 *
 * =====================================================================================
 */

#include <vector>
#include <string>

#ifndef MATH_CPP
#define MATH_CPP

bool isEven(long);
bool isPrime(long);
std::vector<long> factor(long);
std::string decToHex(long);
std::string decToBin(long);
long sum(std::vector<long>);
double average(std::vector<long>);
double standardDeviation(std::vector<long>);
std::vector<long> bubbleSort(std::vector<long>);
long median(std::vector<long>);
double rootMeanSquare(std::vector<long>);

#endif
