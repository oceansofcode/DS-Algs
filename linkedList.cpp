#include <iostream>
#include "linkedList.h"

/*
 * Two constructors, either creating an empty list if 
 * no arguments are entered, or creating a list with an initial value
 */

LinkedList::LinkedList()
{
    header = NULL;
    trailer = NULL;
    size = 0;
}

LinkedList::LinkedList(int initialValue)
{
    struct Node *newNode = createNode(initialValue);

    header = newNode;
    trailer = newNode;
    size = 1;
}

LinkedList::Node *LinkedList::createNode(int value)
{
    struct Node *newNode = new struct Node;
    newNode->value = value;
    newNode->next = NULL;
    newNode->previous = NULL;
}
/*
 * Acessor methods for the int value of the head, tail, and the size of the list
 */
int LinkedList::getHead()
{
    return header->value;
}

int LinkedList::getTail()
{
    return trailer->value;
}

int LinkedList::getSize()
{
    return size;
}

/*
 * Takes in an int value and creates a Node corresponding
 * to it's value and position
 */

void LinkedList::addNode(int value)
{
    struct Node *newNode = createNode(value);

    if (!header)
    {
        header = newNode;
        trailer = newNode;
        return;
    }

    trailer->next = newNode;
    newNode->previous = trailer;
    trailer = newNode;
}

bool LinkedList::removeNode(int value)
{
    struct Node *toRemove = findNode(value);

    if (!isNode(toRemove))
        return false;
}

/*
 * Returns true if the item is in the list,
 * false otherwise. Delegates to private methods.
 */
bool LinkedList::searchList(int value)
{
    struct Node *foundNode = findNode(value);
    return isNode(foundNode);
}

/*
 * Returns a node associated with an integer value, or NULL
 * if such a node does not exist. This method is private as
 * it should only be used by public functions as a subroutine.
 */

LinkedList::Node *LinkedList::findNode(int value)
{
    struct Node *currentNode = header;

    // Loop invariant: The current node is not the last node of the list
    while (currentNode->next)
    {
        if (currentNode->value == value)
            return currentNode;

        currentNode = currentNode->next;
    }

    return NULL;
}

// Private method to check if a node exists. Facilitates code-reuse
bool LinkedList::isNode(struct Node *checkNode)
{
    if (checkNode)
        return true;
    else
        return false;
}