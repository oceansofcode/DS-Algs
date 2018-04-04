#ifndef DYNARRAY_H
#define DYNARRAY_H

class DynArray
{
  public:
    DynArray();
    DynArray(int size);
    ~DynArray();
    int getSize();
    void addInt(int item);
    int getInt(int index);
    int removeInt(int index);

  private:
    void expandArray();
    int *arrayP;
    int size;
    int itemAmount;
};
#endif