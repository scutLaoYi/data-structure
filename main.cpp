#define TEST
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include "tools.h"
#include "test.h"
#include "linklist.h"
#include "sortedlinklist.h"
#include "linkstack.h"

int main(int argc, char *argv[])
{
    srand(time(0));
    /*
       int choice;
       if(argc == 1)
       {
       printf("Choose a data structure to test:\n");
       printf("0: link list;\n");
       scanf("%d", &choice);
       }
       else
       choice = atoi(argv[1]);
       */
    linkstacktest();
    return 0;

}
