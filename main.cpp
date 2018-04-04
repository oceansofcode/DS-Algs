#include <iostream>
#include "linkedList.hpp"

int main()
{
    LinkedList myList;

    for (int i = 0; i < 20; i++)
    {
        myList.addNode(i);
    }

    return 0;
}
