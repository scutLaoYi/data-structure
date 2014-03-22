#include "tools.h"
#include "sortedlinklist.h"

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

