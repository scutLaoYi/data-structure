#ifndef LINKLIST_H
#define LINKLIST_H

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
    void append(Type &data);
    bool insertafter(int index, Type &data);
    void push(Type &data);
};


#endif
