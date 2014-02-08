#include "node.h"


template <class Type>
Node<Type>::Node()
{
    this->nex = 0;
    return;
}

/*
 * Implementation of free list.
 */
template <class Type>
Freelist<Type>::Freelist()
{
    top = 0;
}

template <class Type>
Freelist<Type>::~Freelist()
{
    while(top)
    {
        Node<Type> *temp = top;
        top = top->nex;
        delete temp;
    }
    return;
}

template <class Type>
Node<Type>* Freelist<Type>::newnode()
{
    if(top)
    {
        Node<Type> *temp = top;
        top = top->nex;
        temp->nex = 0;
        return temp;
    }
    return new Node<Type>();
}

template <class Type>
void Freelist<Type>::delnode(Node<Type> *ptr)
{
    ptr->nex = top;
    top = ptr;
    return;
}

