#ifndef ARRAYLIST_H
#define ARRAYLIST_H

/*
 * Practice of data structures -- Array List
 * Date: 2014-03-22 
 * Author: scutLaoYi
 * License: GNU GPL v2
 * Contact: scutlaoyi@gmail.com
 * Personal Site: http://www.scutlaoyi.tk
 */

template <class Type>
class ArrayList
{
    private:
        int size;
        int totallength;
        Type *array;

        //compare function
        int (*compare)(Type a, Type b);
    public :
        ArrayList(int size, int (*comparefunc)(Type a, Type b));
        int getsize();
        //binary search.
        int search(Type value);
        Type get(int index);
        bool set(int index, Type value);
        
        //sorting function.
        void bubblesort();
        void insertsort();
        void selectsort();

        void shellsort();
        void quicksort();
        void heapsort();
        void mergesort();
}
#endif
