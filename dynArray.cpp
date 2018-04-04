#include <iostream>
#include "dynArray.h"

DynArray::DynArray()
{
    arrayP = new int[10];
    this->size = 10;
    this->itemAmount = 0;

    std::cout << "CREATED" << std::endl;
}

DynArray::DynArray(int size)
{
    arrayP = new int[size];
    this->size = size;
    this->itemAmount = 0;

    std::cout << "CREATED" << std::endl;
}

DynArray::~DynArray()
{
    delete[] this->arrayP;
    arrayP = NULL;

    std::cout << "DELETED" << std::endl;
}

int DynArray::getSize()
{
    return this->size;
}

void DynArray::addInt(int item)
{
    if (itemAmount == size)
        expandArray();

    *(arrayP + itemAmount) = item;
    this->itemAmount++;
}