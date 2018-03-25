#include <iostream>
#include "sorts.h"
using namespace std;

int main()
{
    int myArray[] = {1, 51, 6524, 41, 42, 345, 4564, 131, 6, 4, 13, 63, 1, 2, 2, 3};
    int arraySize = sizeof(myArray) / sizeof(*myArray);

    bubbleSort(myArray, arraySize);

    bool sorted = sortTest(myArray, arraySize);

    if (!sorted)
        cout << "Not sorted!!!" << endl;
    else
        cout << "GREAT SUCCESS" << endl;
}
