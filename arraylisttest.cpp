#include "tools.h"
#include "arraylist.h"

void arraylisttest()
{
    printf("Array List testing begin!\n");
    const int LISTLENGTH = 100;
    
    ArrayList<int> *arraylist =
        new ArrayList<int>(LISTLENGTH, compare);

    int randomarray[LISTLENGTH];

    printf("test adding...\n");
    for(int i = 0; i < LISTLENGTH; ++i)
    {
        randomarray[i] = rand() % 1000;
        assert(arraylist->add(randomarray[i]));
        printf("%d\t", randomarray[i]);
    }
    assert(!arraylist->add(randomarray[0]));

    int buf;
    printf("check the value...\n");
    for(int i = 0; i < LISTLENGTH; ++i)
    {
        assert(arraylist->get(i, buf));
        assert(randomarray[i] == buf);
        printf("%d\t", i, buf);
    }

    printf("Array List testing passed!\n");
    return ;
}
