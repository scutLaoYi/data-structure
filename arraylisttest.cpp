#include "tools.h"
#include "test.h"
#include "arraylist.h"

const int LISTLENGTH = 100;
void shuffle(ArrayList<int> *arraylist)
{
    for(int t = 0; t < LISTLENGTH; ++t)
    {
        int ind1 = rand() % arraylist->getsize();
        int ind2 = rand() % arraylist->getsize();
        int temp1, temp2;
        assert(arraylist->get(ind1, temp1));
        assert(arraylist->get(ind2, temp2));
        assert(arraylist->set(ind1, temp2));
        assert(arraylist->set(ind2, temp1));
    }
    return;
}
        
void checksorted(ArrayList<int> *arraylist)
{
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
    return;
}

void checklist(ArrayList<int> *arraylist)
{
    int buf;
    printf("\ncheck the value...\n");
    for(int i = 0; i < LISTLENGTH; ++i)
    {
        assert(arraylist->get(i, buf));
        printf("%d:%d\t", i, buf);
    }
    printf("\n");
    return;
}

void checksearching(ArrayList<int> *arraylist, 
		int *randomarray)
{
	printf("Trying searching...\n");

	int buf;
	for(int i = 0; i < LISTLENGTH; ++i)
	{
		printf("Search %d:", randomarray[i]);
		int ind = arraylist->search(randomarray[i]);
		assert(ind >= 0);
		assert(arraylist->get(ind, buf));
		assert(buf == randomarray[i]);
		printf("Get!");
	}
	assert(arraylist->search(-1) == -1);
	printf("\nsearching test passed!");

}

void arraylisttest()
{
    printf("Array List testing begin!\n");
    
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

    checklist(arraylist);

	checksearching(arraylist, randomarray);
    
    printf("\ntest the bubble sort...\n");
    shuffle(arraylist);
    checklist(arraylist);
    arraylist->bubblesort();
    checksorted(arraylist);

    printf("\ntest the insert sort...\n");
    shuffle(arraylist);
    checklist(arraylist);
    arraylist->insertsort();
    checksorted(arraylist);
    
    printf("\nArray List testing passed!\n");
    return ;
}
