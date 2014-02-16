#ifndef SORTEDLINKLIST_H
#define SORTEDLINKLIST_H
#include "linklist.h"

template <class Type>
class SortedLinklist: public Linklist<Type>
{
    protected:
    //Freelist<Type> *freelist;
    //Node<Type> *head;

    public:
    SortedLinklist();
    ~SortedLinklist();

    protected:
    bool insertafter(int index, Type &data);
    void push(Type &data);

    public:
    void append(Type &value);
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


#endif
