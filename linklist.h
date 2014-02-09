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
public :
    Linklist();
    ~Linklist();
    //adding...
    void append(Type &data);
    bool insertafter(int index, Type &data);
    void push(Type &data);

    //list travelling...
    //void listprint(void (*nodeprinter)(Type &));
};

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

#endif
