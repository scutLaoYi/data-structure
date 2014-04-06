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

        bool sorted;

        //compare function
        int (*compare)(Type *a, Type *b);

        void swap(int left, int right);
		//heap
		void buildheap();
		void shiftdown(int index, int endindex);
    public :
        ArrayList(int length, int (*comparefunc)(Type *a, Type* b));
        int getsize();
        bool get(int index, Type &buf);
        bool set(int index, Type value);
        bool add(Type value);
        
        //binary search.
        int search(Type value);

        //sorting function.
        void bubblesort();
        void insertsort();
        void selectsort();

        void shellsort();
        void quicksort();
        void heapsort();
        void mergesort();

};

template <class Type>
void ArrayList<Type>::swap(int left, int right)
{
    assert(left >= 0 && left < this->size);
    assert(right >= 0 && right < this->size);
    Type buf = this->array[left];
    this->array[left] = this->array[right];
    this->array[right] = buf;
    return;
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
    this->sorted = false;
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
	if(!this->sorted)
		this->bubblesort();

	int left = 0;
	int right = this->size;
	int mid;

	while(left < right)
	{
		mid = (left + right) >> 1;
		if(value < this->array[mid])
		{
			right = mid;
		}
		else if(value > this->array[mid])
		{
			left = mid + 1;
		}
		else
			return mid;
	}
    return -1;
}

template <class Type>
bool ArrayList<Type>::get(int index, Type &buf)
{
    if(this->size <= index)
        return false;
    buf = this->array[index];
    return true;
}

template <class Type>
bool ArrayList<Type>::set(int index, Type value)
{
    if(this->size <= index)
        return false;
    this->array[index] = value;
    this->sorted = false;
    return true;
}

template <class Type>
bool ArrayList<Type>::add(Type value)
{
    if(this->size >= this->totallength)
        return false;
    this->array[this->size++] = value;
    this->sorted = false;
    return true;
}

template <class Type>
void ArrayList<Type>::bubblesort()
{
    for(int i = 0; i < this->size; ++i)
    {
        bool flag(false);
        for(int j = 1; j < this->size-i; ++j)
        {
            if(compare(&this->array[j-1], 
                        &this->array[j]) > 0)
            {
                swap(j-1, j);
                flag = true;
            }
        }
        //no move, the list is sorted, so just jump out.
        if(!flag)
            break;
    }
    this->sorted = true;
    return ;
}

template <class Type>
void ArrayList<Type>::insertsort()
{
    for(int i = 1; i < this->size; ++i)
    {
        int ptr = i;
        while(ptr > 0 && 
                compare(&this->array[ptr],
                    &this->array[ptr-1]) < 0)
        {
            swap(ptr, ptr-1);
            --ptr;
        }
    }
    this->sorted = true;
}

template <class Type>
void ArrayList<Type>::selectsort()
{
	for(int i = 0; i < this->size; ++i)
	{
		int minind = i;
		for(int j = i+1; j < this->size; ++j)
		{
			if(compare(&this->array[minind],
						&this->array[j]) > 0)
			{
				minind = j;
			}
		}
		if(minind != i)
			swap(minind, i);
	}
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
void ArrayList<Type>::shiftdown(int index, 
		int endindex)
{
	int leftchild = (index<<1)+1;
	//leaf node
	if(leftchild >= endindex)
		return;
	int rightchild = leftchild + 1;

	int maxind = leftchild;
	if(rightchild < endindex)
	{
		maxind = compare(&this->array[leftchild], 
				&this->array[rightchild]) > 0 ?
			leftchild : rightchild;
	}

	if(compare(&this->array[index], 
				&this->array[maxind]) < 0)
	{
		this->swap(index, maxind);
		shiftdown(maxind, endindex);
	}
	return;
}

template <class Type>
void ArrayList<Type>::buildheap()
{
	for(int i = this->size/2; i >= 0; --i)
		shiftdown(i, this->size);
	return;
}
template <class Type>
void ArrayList<Type>::heapsort()
{
	this->buildheap();
	for(int t = this->size-1; t > 0; --t)
	{
		this->swap(0, t);
		this->shiftdown(0, t);
	}
    return ;
}

template <class Type>
void ArrayList<Type>::mergesort()
{
    return ;
}


#endif

