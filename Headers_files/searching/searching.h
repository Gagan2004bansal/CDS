// #ifndef SEARCHING_H
// #define SEARCHING_H
// #include <stdlib.h>

// int l_search(const void* arr, const void* target, int size, size_t elementSize);
// int b_search(const void* arr, const void* target, int size, size_t elementSize);

// #endif

#ifndef SEARCHING_H
#define SEARCHING_H

#include <stddef.h> // For size_t

// Linear Search
int l_search(const void* arr, const void* target, int size, size_t elementSize, int (*cmp)(const void*, const void*));

// Binary Search
int b_search(const void* arr, const void* target, int size, size_t elementSize, int (*cmp)(const void*, const void*));

#endif // SEARCHING_H
