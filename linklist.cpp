#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>
#include "linklist.h"

/*
 * Implementation of link list
 */

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
    Node<Type> *ptr = head;
    while(ptr->nex)
        ptr = ptr->nex;
    ptr->nex = freelist->newnode();
    ptr->nex->value = data;
    return;
}

template <class Type>
bool Linklist<Type>::insertafter(int index, Type &data)
{
    assert(index >= 0);
    Node<Type> *ptr = head;
    for(int i = 0; i < index; ++i)
    {
        if(!ptr->nex)
            return false;
        ptr = ptr->nex;
    }
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

