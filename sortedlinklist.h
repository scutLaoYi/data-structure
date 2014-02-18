#ifndef SORTEDLINKLIST_H
#define SORTEDLINKLIST_H
#include "linklist.h"
/*
 * Practice of data structures -- Sorted Link List
 * Date: 2014-02-08 
 * Author: scutLaoYi
 * License: GNU GPL v2
 * Contact: scutlaoyi@gmail.com
 * Personal Site: www.scutlaoyi.tk
 */

template <class Type>
class SortedLinklist: public Linklist<Type>
{
    public:
    SortedLinklist();
    ~SortedLinklist();

    protected:
    bool insertafter(int index, Type &data);
    void push(Type &data);

    public:
    void append(Type &value);
    void mergewithotherlist(SortedLinklist<Type> *ptr);
};

template <class Type>
SortedLinklist<Type>::SortedLinklist()
{
    return;
}

template <class Type>
SortedLinklist<Type>::~SortedLinklist()
{
    return;
}

template <class Type>
void SortedLinklist<Type>::append(Type &data)
{
    Node<Type> *ptr = this->head;
    while(ptr->nex && ptr->nex->value < data)
        ptr = ptr->nex;

    Node<Type> *tempnex = ptr->nex;
    ptr->nex = this->freelist->newnode(data);
    ptr->nex->nex = tempnex;
    return;
}

template <class Type>
void SortedLinklist<Type>::mergewithotherlist(SortedLinklist<Type> *listptr)
{
    assert(this != listptr);
    //two pointer for each list and one for the new list.
    Node<Type> *ptra = listptr->head->nex;
    Node<Type> *ptrb = this->head->nex;
    Node<Type> *traveller = this->head;

    //merge, smaller first
    while(ptra && ptrb)
    {
        if(ptra->value > ptrb->value)
        {
            traveller->nex = ptrb;
            ptrb = ptrb->nex;
        }
        else
        {
            traveller->nex = ptra;
            ptra = ptra->nex;
        }
        traveller = traveller->nex;
    }
    //some nodes left, append to the end of list
    if(ptra)
        traveller->nex = ptra;
    else if(ptrb)
        traveller->nex = ptrb;

    //clear the other list
    listptr->head->nex = 0;
}

#endif
