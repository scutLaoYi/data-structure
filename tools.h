#ifndef TOOLS_H
#define TOOLS_H

/*
 * This is some shared tools for testing.
 * List:
 *      int value printer
 *      int value comparing function 
 *      random number creater
 */

void printInt(int &value)
{
    printf("%d ", value);
    return ;
}

int compare(int *a, int *b)
{
    return *a - *b;
}

int get_random_int()
{
    return rand() % RANDOM_SIZE;
}

#endif
