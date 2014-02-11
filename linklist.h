#ifndef LINKLIST_H
#define LINKLIST_H
#include <cassert>
#include "node.h"
/*
 * Practice of data structures -- Link List
 * Date: 2014-02-08 
 * Author: scutLaoYi
 * License: GNU GPL v2
 * Contact: scutlaoyi@gmail.com
 * Personal Site: www.scutlaoyi.tk
 */

/* 
 * Class: Link list
 * Description: Main class for free list 
 */
template <class Type>
class Linklist
{
    Freelist<Type> *freelist;
    Node<Type> *head;

private:
    Node<Type> *getend();
    bool _getnth(int ind, Node<Type> *&ptr);

    //make the pointer move one step forward to next node.
    //return true if success and false if it can't move anymore.
    bool step(Node<Type> *&ptr);

public :
    Linklist();
    ~Linklist();
    //adding...
    void append(Type &data);
    bool insertafter(int index, Type &data);
    void push(Type &data);

    //get the nth value
    bool getnth(int ind, Type &buf);
    bool getmiddle(Type &buf);
    bool getnthfromend(int ind, Type &buf);

    //counting
    int countelement(Type &target);

    //reverse
    void reverse();

    //remove the nth value
    bool removenth(int ind);

    //list travelling...
    void listprint(void (*nodeprinter)(Type &));
};

/////////////////////////////////
//Private function

template<class Type>
Node<Type> *Linklist<Type>::getend()
{
    Node<Type> *ptr = head;
    while(step(ptr));
    return ptr;
}

template <class Type>
bool Linklist<Type>::_getnth(int ind, Node<Type> *&ptr)
{
    assert(ind >= 0);
    ptr = head;
    for(int i = 0; i < ind; ++i)
        if(!step(ptr))
            return false;
    return true;
}

template <class Type>
bool Linklist<Type>::step(Node<Type> *&ptr)
{
    if(!ptr->nex)
        return false;
    ptr = ptr->nex;
    return true;
}

/////////////////////////////////////
//Public function
//

template <class Type>
Linklist<Type>::Linklist()
{
    freelist = new Freelist<Type>();
    head = freelist->newnode();
    return;
}

template <class Type>
Linklist<Type>::~Linklist()
{
    while(head)
    {
        Node<Type> *temp = head;
        head = head->nex;
        freelist->delnode(temp);
    }
    delete freelist;
    return;
}

template <class Type>
void Linklist<Type>::append(Type &data)
{
    Node<Type> *ptr = getend();
    ptr->nex = freelist->newnode();
    ptr->nex->value = data;
    return;
}

template <class Type>
bool Linklist<Type>::insertafter(int index, Type &data)
{
    Node<Type> *ptr;
    if(!_getnth(index, ptr))
        return false;
    Node<Type> *temp = freelist->newnode();
    temp->value = data;
    temp->nex = ptr->nex;
    ptr->nex = temp;
    return true;
}

template <class Type>
void Linklist<Type>::push(Type &data)
{
    this->insertafter(0, data);
    return;
}

//------------------------------------

template <class Type>
bool Linklist<Type>::getnth(int ind, Type &buf)
{
    assert(ind>0);
    Node<Type> *ptr;
    if(!_getnth(ind, ptr))
        return false;
    buf = ptr->value;
    return true;
}

template <class Type>
bool Linklist<Type>::getmiddle(Type &buf)
{
    if(!head->nex)
        return false;
    Node<Type> *fast, *slow;
    fast = slow = head;
    while(true)
    {
        assert(step(slow));
        assert(step(fast));
        if(!step(fast) || !fast->nex)
            break;
    }
    buf = slow->value;
    return true;
}

template <class Type>
bool Linklist<Type>::getnthfromend(int ind, Type &buf)
{
    assert(ind >= 0);
    Node<Type> *mainptr, *referptr;
    mainptr = head;
    if(!_getnth(ind, referptr))
        return false;
    while(true)
        if(step(referptr))
            step(mainptr);
        else 
            break;
    buf = mainptr->value;
    return true;
}

template <class Type>
int Linklist<Type>::countelement(Type &target)
{
    int count = 0;
    Node<Type> *ptr = head;
    while(step(ptr))
        if(ptr->value == target)
            ++count;
    return count;
}

//----------------------------------

template <class Type>
void Linklist<Type>::reverse()
{
    Node<Type> *prev, *cur, *nex;
    cur = head->nex;
    prev = 0;
    while(true)
    {
        nex = cur->nex;
        cur->nex = prev;
        prev = cur;
        if(nex) //have some more to deal with
            cur = nex;
        else //reach the end of the list
            break;
    }
    head->nex = cur;
    return;
}
//----------------------------------
template <class Type>
bool Linklist<Type>::removenth(int ind)
{
    assert(ind > 0);
    Node<Type> *ptr;
    if(!_getnth(ind-1, ptr))
        return false;
    if(!ptr->nex)
        return false;
    Node<Type> *temp = ptr->nex;
    ptr->nex = temp->nex;
    freelist->delnode(temp);
    return true;
}


template <class Type>
void Linklist<Type>::listprint(void (*nodeprinter)(Type &))
{
    Node<Type> *ptr = head;
    while(step(ptr))
        nodeprinter(ptr->value);
    return;
}

#endif
