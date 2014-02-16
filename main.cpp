#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#define DEBUG
#include "linklist.h"
#include "sortedlinklist.h"

void printInt(int &value)
{
    printf("%d ", value);
    return ;
}

void linklisttest()
{
    //allocation...
    Linklist<int> *linklist = new Linklist<int>();

    //adding...
    for(int i = 20; i < 30; i++)
        linklist->append(i);
    for(int i = 9; i != -1; i--) 
        linklist->push(i);
    for(int i = 19; i != 9; i--)
        linklist->insertafter(10, i);

    linklist->listprint(printInt);

    int num;
    if(linklist->getnth(5, num))
        printf("\nThe fifth element:%d\n", num);
    else
        printf("\nSomething wrong when get the fifth element.\n");
    if(linklist->getnth(1, num))
        printf("\nThe first element:%d\n", num);
    else
        printf("\nSomething wrong when get the frist element.\n");
    if(linklist->getnth(100, num))
        printf("\nHey, why it can get the 100th element?\n");
    else
        printf("\nCan't get the 100th element, no enough length.\n");

    for(int i = 1; i < 11; i++)
    {
        linklist->removenth(i);
        printf("List after removing the %d element:\n", i);
        linklist->listprint(printInt);
        printf("\n");
        printf("reverse:");
        linklist->listprintreverse(printInt);
        printf("\n");

        int temp ;
        assert(linklist->getmiddle(temp));
        printf(" Middle:%d", temp);
        if(linklist->getnthfromend(i, temp))
            printf(" %dth  element from end:%d", i, temp);
        else
            printf(" can't get the %dnd element from end!", i);
        temp = 2;
        printf(" element %d exists %d time(s)", temp, linklist->countelement(temp));
        printf("\n");
    }

    printf("---reverse---\n");
    linklist->reverse();
    linklist->listprint(printInt);
    printf("\n");
    linklist->reverse();
    linklist->listprint(printInt);
    printf("\n");

    printf("---rotate---\n");
    for(int i = 1; i < 10; ++i)
    {
        printf("rotate from %d:", i);
        if(linklist->rotatefrom(i))
            linklist->listprint(printInt);
        else
            printf("failed!");
        printf("\n");
    }

    delete linklist;
    return;
}

void sortedlinklisttest()
{
    const int LIST_LENGTH = 20;
    SortedLinklist<int> *list = new SortedLinklist<int>();
    int tempvalue;
    for(int t = 0; t < 10; ++t)
    {
        for(int i = 0; i < LIST_LENGTH; ++i)
        {
            tempvalue = rand() % 100;
            list->append(tempvalue);
        }

        list->listprint(printInt);
        printf("\n");
    }
    return;
}

    
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
    sortedlinklisttest();
    return 0;

}
