#ifndef TOOLS_H
#define TOOLS_H

/*
 * This is some shared tools for testing.
 * List:
 *      int value printer
 *      int value comparing function 
 *      random number creater
 */
#include <cstdlib>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cstdio>

#define RANDOM_SIZE 100
void printInt(int &value);
int compare(int *a, int *b);
int get_random_int();
#endif
