#ifndef NODE_H
#define NODE_H

/*
 * Practice of data structures -- Data Node and Free List
 * Date: 2014-02-08 
 * Author: scutLaoYi
 * License: GNU GPL v2
 * Contact: scutlaoyi@gmail.com
 * Personal Site: www.scutlaoyi.tk
 */

/*
 * Structure: Node
 * Description: Data node, with a value and a pointer to next node.
 */
template <class Type>
struct Node
{
    Type value;
    Node *nex;
public:
    Node();
};

/*
 * Class: Free list
 * Description: 
 * Free list class improve the allocation and deallocation
 * processes.
 */
template <class Type>
class Freelist
{
    Node<Type> *top;
public:
    Freelist();
    ~Freelist();
    Node<Type>* newnode();
    void delnode(Node<Type> *ptr);
};

/*
 * Implementation...
 */

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

#endif
