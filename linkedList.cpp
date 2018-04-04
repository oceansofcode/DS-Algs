#include <iostream>
#include "linkedList.h"

template <class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
    tail = NULL;
}

template <class T>
T LinkedList<T>::getHead()
{
    return this.head->ele;
}

template <class T>
T LinkedList<T>::getTail()
{
    return this.tail->ele;
}

template <class T>
void LinkedList<T>::addNode(T item)
{
    node *temp = new node;
    temp->ele = item;
    temp->next = NULL;

    if (!head)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}