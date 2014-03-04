#ifndef LINKSTACK_H
#define LINKSTACK_H
#include <cassert>
#include "node.h"

/*
 * Practice of data structures -- Link Stack
 * Author: scutLaoYi
 * License: GNU GPL v2
 * Contact: scutlaoyi@gmail.com
 * Personal Site: http://www.scutlaoyi.tk
 */

template <class Type>
class LinkStack
{
    protected:
    Freelist<Type> *freelist;
    Node<Type> *top;

    public:
    LinkStack();
    void push(Type &element);
    bool pop();
    bool peek(Type &buf);
    bool isempty();
    void insertatbottom(Type &value);
    void reverse();
};

template <class Type>
LinkStack<Type>::LinkStack()
{
    freelist = new Freelist<Type>();
    top = 0;
    return;
}

template <class Type>
void LinkStack<Type>::push(
        Type &element
        )
{
    Node<Type> *temptr = freelist->newnode(element);
    temptr->nex = top;
    top = temptr;
    return;
}

template <class Type>
bool LinkStack<Type>::pop()
{
    if(isempty())
        return false;
    Node<Type> *temptr = top;
    top = top->nex;
    freelist->delnode(temptr);
    return true;
}

template <class Type>
bool LinkStack<Type>::peek(Type &buf)
{
    if(isempty())
        return false;
    buf = top->value;
    return true;
}

template <class Type>
bool LinkStack<Type>::isempty()
{
    return top ? false : true;
}

template <class Type>
void LinkStack<Type>::insertatbottom(Type &value)
{
    if(isempty())
    {
        top = freelist->newnode(value);
        return;
    }

    Node<Type> *ptr = top;
    while(ptr->nex)
        ptr = ptr->nex;
    ptr->nex = freelist->newnode(value);
    return;
}

template <class Type>
void LinkStack<Type>::reverse()
{
    Type buf;
    if(this->peek(buf))
    {
        this->pop();
        reverse();
        this->insertatbottom(buf);
    }
    return;
}
    
#endif
