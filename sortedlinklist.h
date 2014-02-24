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
    SortedLinklist(int (*comp)(Type *a, Type *b));
    ~SortedLinklist();

    protected:
    bool insertafter(int index, Type &data);
    void push(Type &data);

    int (*comparefunc)(Type *a, Type *b);

    public:
    void append(Type &value);
    void mergewithotherlist(SortedLinklist<Type> *ptr);
    void removeduplicates();
    SortedLinklist<Type> *intersectionwith(SortedLinklist<Type> *anotherlist);
};

template <class Type>
SortedLinklist<Type>::SortedLinklist(
        int (*comp)(Type *a, Type *b)
        )
{
    this->comparefunc = comp;
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
    while(ptr->nex && comparefunc(&(ptr->nex->value),&data) < 0)
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
        if(comparefunc(&(ptra->value), &(ptrb->value)) > 0)
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

template <class Type>
void SortedLinklist<Type>::removeduplicates()
{
    Node<Type> *ptr = this->head->nex;
    if(!ptr)
        return;
    Node<Type> *nexptr = ptr->nex;
    while(nexptr)
    {
        if(!comparefunc(&(nexptr->value), &(ptr->value)))
        {
            ptr->nex = nexptr->nex;
            this->freelist->delnode(nexptr);
        }
        else
            ptr = nexptr;
        nexptr = ptr->nex;
    }
    return ;
}

template <class Type>
SortedLinklist<Type> *SortedLinklist<Type>::intersectionwith(SortedLinklist<Type> *anotherlist)
{
    Node<Type> *taila = this->head->nex;
    Node<Type> *tailb = anotherlist->head->nex;
    SortedLinklist<Type> *newlist = new SortedLinklist<Type> (this->comparefunc);
    Node<Type> *newtail = newlist->head;

    while(taila  && tailb)
    {
        int cp = comparefunc(
                &(taila->value),
                &(tailb->value)
                );
        if(!cp)
        {
            newtail->nex = this->freelist->newnode(taila->value);
            newtail = newtail->nex;
            taila = taila->nex;
            tailb = tailb->nex;
        }
        else if(cp > 0)
            tailb = tailb->nex;
        else 
            taila = taila->nex;
    }

    return newlist;
}

#endif
