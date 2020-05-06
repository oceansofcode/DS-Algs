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

  typedef struct _Node
  {
    int value;
    _Node *next;
    _Node *previous;
  } Node;

  Node *header;
  Node *trailer;

  Node *createNode(int value);
  void deleteNode(Node *toDelete);
  Node *findNode(int value);
  bool isNode(Node *checkNode);

  Node *getNext(Node *start);
  bool hasNext(Node *node);
};
#endif