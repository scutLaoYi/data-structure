#include "tools.h"

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

