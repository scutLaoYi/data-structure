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
        int (*compare)(Type *a, Type *b);
    public :
        ArrayList(int length, int (*comparefunc)(Type *a, Type* b));
        int getsize();
        //binary search.
        int search(Type value);
        bool get(int index, Type &buf);
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

template <class Type>
ArrayList<Type>::ArrayList(int length,
        int (*comparefunc)(Type *a, Type *b))
{
    this->totallength = length;
    this->compare = comparefunc;
    this->size = 0;
    this->array = 
        new Type[length];
    return;
}

template <class Type>
int ArrayList<Type>::getsize()
{
    return this->size;
}

template <class Type>
int ArrayList<Type>::search(Type value)
{
    return 0;
}

template <class Type>
bool ArrayList<Type>::get(int index, Type &buf)
{
    return false;
}

template <class Type>
bool ArrayList<Type>::set(int index, Type value)
{
    raturn false;
}

template <class Type>
void ArrayList<Type>::bubblesort()
{
    return ;
}

template <class Type>
void ArrayList<Type>::insertsort()
{
    return ;
}
template <class Type>
void ArrayList<Type>::selectsort()
{
    return ;
}

template <class Type>
void ArrayList<Type>::shellsort()
{
    return ;
}

template <class Type>
void ArrayList<Type>::quicksort()
{
    return ;
}

template <class Type>
void ArrayList<Type>::heapsort()
{
    return ;
}

template <class Type>
void ArrayList<Type>::mergesort()
{
    return ;
}


#endif

