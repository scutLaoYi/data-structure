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

#endif
