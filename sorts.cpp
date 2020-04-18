#include <iostream>
#include "sorts.hpp"
#include <algorithm>
#include <random>
#include <ctime>

//Also known as "bogosort"
void stupidSort(int unSortedArray[], int size)
{
    int *begin, *end, counter;
    bool isSorted;

    begin = unSortedArray;
    end = unSortedArray + size;
    isSorted = sortTest(unSortedArray, size);
    counter = 0;

    std::srand((int)time(0));

    while (!isSorted)
    {
        counter++;
        std::random_shuffle(begin, end);
        isSorted = sortTest(unSortedArray, size);
        std::cout << "Not sorted yet " << counter << " iterations" << std::endl;
    }
    printArray(unSortedArray, size);
}

void selectionSort(int unSortedArray[], int size)
{
    int counter = 0;

    for (int i = 0; i < size - 1; i++)
    {
        int jMin = i;
        for (int j = i + 1; j < size; j++)
        {
            int smallest = *(unSortedArray + jMin);
            int current = *(unSortedArray + j);

            if (smallest > current)
                jMin = j;
            counter++;
        }

        std::swap(unSortedArray[jMin], unSortedArray[i]);
    }

    double bigO = counter / size;

    std::cout << "SelectionSort ran " << counter << " times for " << size << " inputs, this is an average of " << bigO << " times an input" << std::endl;
}

void bubbleSort(int unSortedArray[], int size)
{
    bool swapped = false;
    int counter = 0;

    for (int i = size; i > 1; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            counter++;
            if (unSortedArray[j] > unSortedArray[j + 1])
            {
                std::swap(unSortedArray[j], unSortedArray[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }

    double bigO = counter / size;

    std::cout << "Bubblesort ran " << counter << " times for " << size << " inputs, this is an average of " << bigO << " times an input" << std::endl;
}

void insertionSort(int unSortedArray[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int item = unSortedArray[i];
        int j = i;

        while (j > 0 && unSortedArray[j - 1] > item)
        {
            unSortedArray[j] = unSortedArray[j - 1];
            j--;
        }

        unSortedArray[j] = item;
    }
}

void mergeSort(int unSortedArray[], int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - 1) / 2;
        mergeSort(unSortedArray, start, mid);
        mergeSort(unSortedArray, mid + 1, end);

        merge(unSortedArray, start, mid, end);
    }
}

void merge(int subArray[], int start, int mid, int end)
{
    int i, j, k;
    int leftSize = mid - start + 1;
    int rightSize = end - mid;
    i = j = k = 0;

    int *leftHalf = new int[leftSize];
    int *rightHalf = new int[rightSize];

    for (int i = 0; i < leftSize; i++)
    {
        leftHalf[i] = subArray[start + i];
    }

    for (int j = 0; j < rightSize; j++)
    {
        rightHalf[i] = subArray[mid + 1 + j];
    }

    while (i < leftSize && j < rightSize)
    {
        if (leftHalf[i] <= rightHalf[j])
        {
            subArray[k++] = leftHalf[i++];
        }
        else
        {
            subArray[k++] = rightHalf[j++];
        }
    }

    while (i < leftSize)
    {
        subArray[k++] = leftHalf[i++];
    }

    while (j < rightSize)
    {
        subArray[k++] = rightHalf[j++];
    }

    delete[] leftHalf;
    leftHalf = nullptr;
    delete[] rightHalf;
    rightHalf = nullptr;
}

void printArray(int unSortedArray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << " Number: " << *unSortedArray++ << " at index " << i << std::endl;
    }
}

bool sortTest(int unSortedArray[], int size)
{
    bool isSorted = true;
    int current, next;

    for (int i = 0; i < size - 1; i++)
    {
        current = *(unSortedArray + i);
        next = *(unSortedArray + i + 1);

        if (current > next)
            return false;
    }

    return isSorted;
}