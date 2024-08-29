#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stddef.h>

// sort 
void mergeSort(void* arr, size_t n, size_t size, int (*cmp)(const void*, const void*));
void quickSort(void* arr, size_t n, size_t size, int (*cmp)(const void*, const void*));
void bubbleSort(void* arr, size_t n, size_t size, int (*cmp)(const void*, const void*));
void insertionSort(void* arr, size_t n, size_t size, int (*cmp)(const void*, const void*));
void selectionSort(void* arr, size_t n, size_t size, int (*cmp)(const void*, const void*));
void sort(void* arr, size_t n, size_t size, int(*cmp)(const void*, const void*));

// helper function : swap
void swap(void* a, void *b, size_t size);

// custom comparator : int or float
int compareInt(const void* a, const void* b);
int compareFloat(const void* a, const void* b);

#endif