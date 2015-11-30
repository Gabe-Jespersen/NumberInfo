/*
 * =====================================================================================
 *
 *       Filename:  parse.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/29/2015 12:57:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Gabe Jespersen (), gzackwebs@tfwno.gf
 *   Organization:  
 *
 * =====================================================================================
 */

#include <string>
#include <vector>

#ifndef PARSE_H
#define PARSE_H

std::string parse(int, char**);
bool exists(std::string);
std::vector<long> readFile(std::string);

#endif