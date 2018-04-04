#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/*
 * Definies a simple doubly-linked list class that encapsulates
 * an integer value as nodes.
 * The client should only be concerned with the integer values themselves,
 * not the nodes which store them.
 */

// TODO: Change to template class
class LinkedList
{
public:
  LinkedList();
  LinkedList(int initialValue);
  ~LinkedList();

  int getHead();
  int getTail();
  int getSize();

  void addNode(int value);
  bool removeNode(int value);

  bool searchList(int value);
  void printList(int value);

private:
  int size;

  struct Node
  {
    int value;
    struct Node *next;
    struct Node *previous;
  };

  struct Node *header;
  struct Node *trailer;

  struct Node *createNode(int value);
  struct Node *findNode(int value);
  bool isNode(struct Node *checkNode);
};
#endif