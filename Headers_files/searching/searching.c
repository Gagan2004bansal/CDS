#include <stdlib.h>
#include <string.h>
#include "searching.h"

// Linear Search Implementation
int l_search(const void* arr, const void* target, int size, size_t elementSize){

    for(int i = 0; i<size; i++){
        if(memcmp((char*)arr + i * elementSize, target, elementSize) == 0){
            return i;
        }
    }

    return -1;
}

// Binary Search Implementation
int b_search(const void* arr, const void* target, int size, size_t elementSize){

    int start = 0;
    int end = size - 1;
    int mid;
    while(start <= end){

        mid = start + (end - start)/2;

        const void* midEle = (char*)arr + mid * elementSize;

        if(*(int*)target == *(int*)midEle){
            return mid;
        }
        else if(*(int*)target < *(int*)midEle){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }

    }

    return -1;
}