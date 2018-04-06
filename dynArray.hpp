#ifndef DYNARRAY_H
#define DYNARRAY_H

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
    arrayP = new T[size];
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

    *(arrayP + itemAmount) = item;
    itemAmount++;
  }

  T getItem(int index)
  {
    if (!errorCheck)
      return NULL;

    return *(arrayP + index);
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

private:
  T *arrayP;

  void expandArray()
  {
    int newSize = this->size * 2;
    T *newArray = new T[newSize];

    for (int i = 0; i < this->size; i++)
    {
      *(newArray + i) = *(arrayP + i);
    }

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