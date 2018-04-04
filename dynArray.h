#ifndef DYNARRAY_H
#define DYNARRAY_H

/*
 * An implementation of a "vector" or "ArrayList" meant for practice
 */

class DynArray
{
public:
  DynArray(int size);
  DynArray();
  ~DynArray();

  int getSize();
  int removeInt(int index);

  void addLast(int item);
  int getInt(int index);

  void printAll();

private:
  void expandArray();
  int *arrayP;
  int size;
  int itemAmount;
};
#endif