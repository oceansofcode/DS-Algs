#ifndef TREE_HPP
#define TREE_HPP

class Tree
{
public:
  Tree();
  ~Tree();

  void addInt(int item);
  bool hasItem(int item);

  bool isEmpty();

  void postOrder();
  void preOrder();
  void inOrder();

private:
  struct Node
  {
    int value;
    Node *parent;
    Node *leftChild;
    Node *rightChild;
  };

  Node *root;
  int size;
};

#endif