#include "tools.h"
#include "test.h"
#include "arraylist.h"

void arraylisttest()
{
    printf("Array List testing begin!\n");
    const int LISTLENGTH = 100;
    
    ArrayList<int> *arraylist =
        new ArrayList<int>(LISTLENGTH, compare);

    int randomarray[LISTLENGTH];
    int buf;

    printf("test adding...\n");
    for(int i = 0; i < LISTLENGTH; ++i)
    {
        randomarray[i] = rand() % 1000;
        assert(arraylist->add(randomarray[i]));
        printf("%d\t", randomarray[i]);
    }
    assert(!arraylist->add(randomarray[0]));

    printf("\ncheck the value...\n");
    for(int i = 0; i < LISTLENGTH; ++i)
    {
        assert(arraylist->get(i, buf));
        assert(randomarray[i] == buf);
        printf("%d:%d\t", i, buf);
    }

    printf("\ntest the bubble sort...\n");
    arraylist->bubblesort();
    int left, right;
    arraylist->get(0, left);
    printf("sorted:%d ", left);
    for(int i = 1; i < LISTLENGTH; ++i)
    {
        arraylist->get(i, right);
        assert(left <= right);
        left = right;
        printf("%d ", left);
    }

    printf("\nArray List testing passed!\n");
    return ;
}
