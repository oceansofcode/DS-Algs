#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class LinkedList
{
public:
  LinkedList();
  T getHead();
  T getTail();

  void addNode(T item);

private:
  struct Node
  {
    T ele;
    struct Node *next;
  };
  struct Node *head;
  struct Node *tail;
};
#endif
