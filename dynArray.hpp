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
<<<<<<< HEAD
    if (!errorCheck)
      return NULL;

    return *(arrayP + index);
    == == == =
                 return arrayP[index];
>>>>>>> fb8cbf139eb06593c8b154e8094e98df1920d16e
  }

  void addItem(T item, int index)
  {
    if (index == itemAmount + 1)
    {
      addLast(T item)
    }
    else
    {
    }
  }

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
    size = newSize;
    arrayP = newArray;
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