/*
 * =====================================================================================
 *
 *       Filename:  parse.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/29/2015 12:57:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen (), gzackwebs@tfwno.gf
 *   Organization:  
 *
 * =====================================================================================
 */

#include <vector>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>

#include "parse.h"

using namespace std;

string parseFile(int argc, char** argv)
{
    return (string)(argv[2]);
}

bool exists(string toCheck)
{
    ifstream ifile(toCheck);
    return ifile;
}

vector<long> readFile(string toRead)
{
    ifstream file(toRead);
    cout << "penis" << endl;
    return {1};
}
