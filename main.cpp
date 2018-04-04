#include <iostream>
#include "dynArray.h"

int main()
{
    DynArray *myArray = new DynArray(50);

    int arraySize = myArray->getSize();
    std::cout << arraySize << std::endl;

    delete myArray;
    myArray = NULL;
    return 0;
}
