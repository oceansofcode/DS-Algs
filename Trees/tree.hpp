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
    typedef struct _Node
    {
        int value;
        struct _Node *parent;
        struct _Node *leftChild;
        struct _Node *rightChild;
    } Node;

    Node *root;
    int size;
};

#endif