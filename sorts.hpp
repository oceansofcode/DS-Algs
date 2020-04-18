#ifndef SORTS_H
#define SORTS_H

void stupidSort(int unSortedArray[], int size);

void selectionSort(int unSortedArray[], int size);
void insertionSort(int unSortedArray[], int size);
void bubbleSort(int unSortedArray[], int size);

void mergeSort(int unSortedArray[], int start, int end);
void merge(int subArray[], int start, int mid, int end);

void quickSort(int unSortedArray[], int size);
void heapSort(int unSortedArray[], int size);

void radixSort(int unSortedArray[], int size, int range);

void printArray(int unSortedArray[], int size);
bool sortTest(int unSortedArray[], int size);

#endif
