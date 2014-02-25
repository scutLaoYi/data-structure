#define TEST
#define RANDOM_SIZE 100
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include "linklist.h"
#include "sortedlinklist.h"
#include "linkstack.h"

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

int compare(int *a, int *b)
{
    return *a - *b;
}

int get_random_int()
{
    return rand() % RANDOM_SIZE;
}

void sortedlinklisttest()
{
    const int LIST_LENGTH = 20;
    SortedLinklist<int> *lista = new SortedLinklist<int>(compare);
    SortedLinklist<int> *listb = new SortedLinklist<int>(compare);
    int tempvalue;
    for(int i = 0; i < LIST_LENGTH; ++i)
    {
        tempvalue = rand() % 100;
        lista->append(tempvalue);

        tempvalue = rand() % 100;
        listb->append(tempvalue);
    }

    lista->listprint(printInt);
    printf("\n");
    listb->listprint(printInt);
    printf("\n");
    printf("intersection:");
    SortedLinklist<int> *intersetlist = lista->intersectionwith(listb);
    intersetlist->listprint(printInt);
    printf("\n");
    printf("merge!\n");
    lista->mergewithotherlist(listb);
    printf("result:");
    lista->listprint(printInt);
    printf("\n");
    printf("removing duplicates...\n");
    lista->removeduplicates();
    printf("result:");
    lista->listprint(printInt);
    return;
}

void linkstacktest()
{
    const int STACK_SIZE = 20;

    printf("LinkStack testing...\n");
    printf("Pushing...\n");
    LinkStack<int> *stack = new LinkStack<int>();
    assert(stack->isempty());

    int bufint;
    int testarray[STACK_SIZE];
    for(int i = 0; i < STACK_SIZE; ++i)
    {
        bufint = get_random_int();
        stack->push(bufint);
        testarray[i] = bufint;
        printf("%d\t", bufint);
    }
    printf("\n");
    assert(!stack->isempty());

    printf("Poping...\n");
    for(int i = STACK_SIZE-1; i != -1; --i)
    {
        assert(stack->peek(bufint));
        printf("%d\t", bufint);
        assert(bufint == testarray[i]);
        assert(stack->pop());
    }
    assert(stack->isempty());
    printf("\n");

    printf("LinkStack testing passed!\n");
    return ;
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
    linkstacktest();
    return 0;

}
