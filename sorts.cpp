#include <iostream>
#include "sorts.hpp"
#include <algorithm>
#include <random>

using namespace std;

//Also known as "bogosort"
void stupidSort(int myArray[], int size)
{
    int *begin, *end, counter;
    bool isSorted;

    begin = myArray;
    end = myArray + size;
    isSorted = sortTest(myArray, size);
    counter = 0;

    while (!isSorted)
    {
        counter++;
        random_shuffle(begin, end);
        isSorted = sortTest(myArray, size);
        cout << "Not sorted yet " << counter << " iterations" << endl;
        //printArray(myArray, size);
    }
}

void selectionSort(int myArray[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        int jMin = i;
        for (int j = i + 1; j < size; j++)
        {
            int smallest = *(myArray + jMin);
            int current = *(myArray + j);

            if (smallest > current)
                jMin = j;
        }

        swap(myArray[jMin], myArray[i]);
    }
}

void bubbleSort(int myArray[], int size)
{
    bool swapped = false;
    int counter = 0;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            counter++;
            if (myArray[j] > myArray[j + 1])
            {
                swap(myArray[j], myArray[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }

    double bigO = counter / size;

    cout << "Bubblesort ran " << counter << " times for " << size << " inputs, this is an average of " << bigO << " times an input" << endl;
}

void printArray(int myArray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << " Number: " << *myArray++ << " at index " << i;
    }
    cout << endl;
}

bool sortTest(int myArray[], int size)
{
    bool isSorted = true;
    int current, next;

    for (int i = 0; i < size - 1; i++)
    {
        current = *(myArray + i);
        next = *(myArray + i + 1);

        if (current > next)
            return false;
    }

    return isSorted;
}