#include "tools.h"
#include "arraylist.h"

void arraylisttest()
{
    const int LISTLENGTH = 100;
    
    ArrayList<int> *arraylist =
        new ArrayList<int>(LISTLENGTH, compare);
    return ;
}
