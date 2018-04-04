#include <iostream>
#include "dynArray.h"

int main()
{
    DynArray *myArray = new DynArray();

    for (int i = 0; i < 200; i++)
    {
        myArray->addLast(i);

        std::cout << myArray->getSize() << std::endl;
    }

    myArray->printAll();

    delete myArray;
    myArray = NULL;

    return 0;
}
