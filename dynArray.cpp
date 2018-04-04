#include <iostream>
#include "dynArray.h"

DynArray::DynArray() : DynArray::DynArray(10) {}

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
    return this->itemAmount;
}

void DynArray::addLast(int item)
{
    if (itemAmount == size)
        expandArray();

    *(arrayP + itemAmount) = item;
    itemAmount++;
}

void DynArray::expandArray()
{
    int newSize = this->size * 2;
    int *newArray = new int[newSize];

    for (int i = 0; i < this->size; i++)
    {
        *(newArray + i) = *(arrayP + i);
    }

    delete[] arrayP;
    size = newSize;
    arrayP = newArray;
}

int DynArray::getInt(int index)
{
    return *(arrayP + index);
}

void DynArray::printAll()
{
    for (int i = 0; i < this->itemAmount; i++)
    {
        std::cout << "Item: " << *(arrayP + i) << " at index: " << i << std::endl;
    }
}