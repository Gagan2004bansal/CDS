#ifndef SEARCHING_H
#define SEARCHING_H
#include <stdlib.h>

int l_search(const void* arr, const void* target, int size, size_t elementSize);
int b_search(const void* arr, const void* target, int size, size_t elementSize);

#endif