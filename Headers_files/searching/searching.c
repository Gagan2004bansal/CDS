#include "searching.h"
#include <string.h>

// Linear search
int l_search(const void* arr, const void* target, int size, size_t elementSize, int (*cmp)(const void*, const void*)) {
    for (int i = 0; i < size; i++) {
        const void* element = (const char*)arr + i * elementSize;
        if (cmp(element, target) == 0) {
            return i;
        }
    }
    return -1;
}

// Binary search (assuming array is sorted)
int b_search(const void* arr, const void* target, int size, size_t elementSize, int (*cmp)(const void*, const void*)) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        const void* element = (const char*)arr + mid * elementSize;

        int result = cmp(element, target);
        if (result == 0) {
            return mid;
        } else if (result < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
