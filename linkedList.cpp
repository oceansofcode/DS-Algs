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
    Node *newNode = createNode(initialValue);

    header = newNode;
    trailer = newNode;
    size = 1;
}

LinkedList::~LinkedList()
{
    Node *currentNode = header;
    while (hasNext(currentNode))
    {
        deleteNode(currentNode);
        currentNode = getNext(currentNode);
    }
}

LinkedList::Node *LinkedList::createNode(int value)
{
    Node *newNode = new Node;
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
    Node *newNode = createNode(value);

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
    Node *toRemove = findNode(value);

    if (!isNode(toRemove))
        return false;

    Node *previousNode = toRemove->previous;
    Node *nextNode = toRemove->next;

    previousNode->next = nextNode;
    nextNode->previous = previousNode;

    deleteNode(toRemove);

    return true;
}

/*
 * Returns true if the item is in the list,
 * false otherwise. Delegates to private methods.
 */
bool LinkedList::searchList(int value)
{
    Node *foundNode = findNode(value);
    return isNode(foundNode);
}

/*
 * Returns a node associated with an integer value, or NULL
 * if such a node does not exist. This method is private as
 * it should only be used by public functions as a subroutine.
 */

LinkedList::Node *LinkedList::findNode(int value)
{
    Node *currentNode = header;

    // Loop invariant: The current node is not the last node of the list
    while (hasNext(currentNode))
    {
        if (currentNode->value == value)
            return currentNode;

        currentNode = getNext(currentNode);
    }

    return NULL;
}

// Private method to check if a node exists. Facilitates code-reuse
bool LinkedList::isNode(Node *checkNode)
{
    if (checkNode)
        return true;
    else
        return false;
}

void LinkedList::deleteNode(Node *toDelete)
{
    delete toDelete;
    toDelete = NULL;
}
/*
 * Used to iterate over Nodes, start will usually be the "header"
 */
LinkedList::Node *LinkedList::getNext(Node *start)
{
    return start->next;
}

bool LinkedList::hasNext(Node *node)
{
    return isNode(node->next);
}