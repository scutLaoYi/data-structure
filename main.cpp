#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include "linklist.h"

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
    for(int i = 0; i < 20; i++)
        linklist->append(i);
    for(int i = 25; i < 45; i++)
        linklist->push(i);
    for(int i = 50; i < 70; i++)
        linklist->insertafter(5, i);

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
        printf("\nList after removing the %d element:\n", i);
        linklist->listprint(printInt);
    }

    delete linklist;
    return;
}
    
int main(int argc, char *argv[])
{
    int choice;
    if(argc == 1)
    {
        printf("Choose a data structure to test:\n");
        printf("0: link list;\n");
        scanf("%d", &choice);
    }
    else
        choice = atoi(argv[1]);

    linklisttest();
    return 0;

}
