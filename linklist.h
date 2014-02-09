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
 * Description: Main class for free list, 
 * support some function such as adding, deleting, inserting, and so on.
 */
template <class Type>
class Linklist
{
    Freelist<Type> *freelist;
    Node<Type> *head;

private:
    Node<Type> *getend();
    bool _getnth(int ind, Node<Type> *&ptr);

public :
    Linklist();
    ~Linklist();
    //adding...
    void append(Type &data);
    bool insertafter(int index, Type &data);
    void push(Type &data);

    //get the nth value
    bool getnth(int ind, Type &buf);

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
    while(ptr->nex)
        ptr = ptr->nex;
    return ptr;
}

template <class Type>
bool Linklist<Type>::_getnth(int ind, Node<Type> *&ptr)
{
    assert(ind >= 0);
    ptr = head;
    for(int i = 0; i < ind; ++i)
    {
        if(ptr->nex)
            ptr = ptr->nex;
        else
            return false;
    }
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
    Node<Type> *ptr = head->nex;
    while(ptr)
    {
        nodeprinter(ptr->value);
        ptr = ptr->nex;
    }
    return;
}

#endif
