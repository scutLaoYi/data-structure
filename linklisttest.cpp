#include "tools.h"
#include "linklist.h"

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

