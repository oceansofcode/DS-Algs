#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <iostream>

/*
 * A simple implementation of a "vector" or "ArrayList"
 */

template <typename T>
class DynArray
{
public:
  DynArray() : DynArray(10) {}

  DynArray(int size)
  {
    arrayP = createArray(size);
    this->size = size;
    this->itemAmount = 0;

    std::cout << "CREATED" << std::endl;
  }

  ~DynArray()
  {
    delete[] this->arrayP;
    arrayP = NULL;

    std::cout << "DELETED" << std::endl;
  }

  int getAmount()
  {
    return this->itemAmount;
  }

  int getSize()
  {
    return this->size;
  }

  void addLast(T item)
  {
    if (itemAmount == size)
      expandArray();

    arrayP[itemAmount] = item;
    itemAmount++;
  }

  T getItem(int index)
  {
    if (!errorCheck(index))
      return 0;

    return arrayP[index];
  }

  void addItem(T item, int index);

  T removeItem(int index);

  void printAll()
  {
    for (int i = 0; i < this->itemAmount; i++)
    {
      std::cout << "Item: " << getItem(i)
                << " at index: " << i << std::endl;
    }
  }

  /*
   * returns a static array version of the code
   * for use in functions that take in a standard array,
   * note that changes in this array will not change anything
   * in the class' array
   * 
   * The array returned will be of the same size as the class array
   * to facilitate copying every element, the cost of this is at worst
   * twice the space used as elements in the array.
   */

  T *toArray()
  {
    T *staticArray = copyArray(size);

    return staticArray;
  }

private:
  T *arrayP;

  T *createArray(int size)
  {
    T *array = new T[size];

    for (int i = 0; i < size; i++)
    {
      array[i] = 0;
    }

    return array;
  }

  void expandArray()
  {
    int newSize = this->size * 2;
    T *newArray = copyArray(newSize);

    delete[] arrayP;
    this->size = newSize;
    arrayP = newArray;
  }

  T *copyArray(int size)
  {
    T *newArray = createArray(size);

    for (int i = 0; i < size; i++)
    {
      newArray[i] = arrayP[i];
    }

    return newArray;
  }

  bool errorCheck(int index)
  {
    if (index > itemAmount)
      return false;

    return true;
  }

  int size;

  int itemAmount;
};

#endif