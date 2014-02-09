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

    int fifth;
    if(linklist->getnth(5, fifth))
        printf("\nThe fifth element:%d\n", fifth);
    else
        printf("\nSomething wrong when get the fifth element.\n");
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
    printf("your choice is: %d\n", choice);

    linklisttest();
    return 0;

}
