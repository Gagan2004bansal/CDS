#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sorting.h"

// Helper Function: swap
void swap(void* a, void* b, size_t size){
    char* temp = (char*)malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

// Custom Comparator: int
int compareInt(const void* a, const void* b) {
    int int_a = *(int *)a;
    int int_b = *(int *)b;
    return (int_a > int_b) - (int_a < int_b);
}

// Custom Comparator: float
int compareFloat(const void* a, const void* b){
    float float_a = *(float *)a;
    float float_b = *(float *)b;
    return (float_a > float_b) - (float_b < float_a);
}

// Bubble Sort
void bubbleSort(void *arr, size_t n, size_t size, int(*cmp)(const void*, const void*)){
    char* array = (char*)arr;
    for(size_t i = 0; i < n - 1; i++){
        for(size_t j = 0; j < n - i - 1; j++){
            if(cmp(array + j * size, array + (j + 1) * size) > 0){
                swap(array + j * size, array + (j + 1) * size, size);
            }
        }
    }
}

// Insertion Sort
void insertionSort(void* arr, size_t n, size_t size, int(*cmp)(const void*, const void*)){
    char* array = (char*)arr;
    for(size_t i = 1; i < n; i++){
        char* key = (char*)malloc(size);
        memcpy(key, array + i * size, size);
        size_t j = i;
        while (j > 0 && cmp(array + (j - 1) * size, key) > 0){
            memcpy(array + j * size, array + (j - 1) * size, size);
            j--;
        }
        memcpy(array + j * size, key, size);
        free(key);
    }
}

// Selection Sort
void selectionSort(void* arr, size_t n, size_t size, int(*cmp)(const void*, const void*)){
    char *array = (char*)arr;
    for(size_t i = 0; i < n - 1; i++){
        size_t minIndex = i;
        for(size_t j = i + 1; j < n; j++){
            if(cmp(array + j * size, array + minIndex * size) < 0){
                minIndex = j;
            }
        }
        swap(array + i * size, array + minIndex * size, size);
    }
}

// Merge Sort
void mergeArr(void* arr, size_t left, size_t mid, size_t right, size_t size, int(*cmp)(const void*, const void*)){
    size_t m = mid - left + 1;
    size_t n = right - mid;

    char *arr1 = (char*)malloc(m * size);
    char *arr2 = (char*)malloc(n * size);

    memcpy(arr1, (char*)arr + left * size, m * size);
    memcpy(arr2, (char*)arr + (mid + 1) * size, n * size);

    size_t i = 0, j = 0, k = left;
    while(i < m && j < n){
        if(cmp(arr1 + i * size, arr2 + j * size) <= 0){
            memcpy((char*)arr + k * size, arr1 + i * size, size);
            i++;
        } else {
            memcpy((char*)arr + k * size, arr2 + j * size, size);
            j++;
        }   
        k++;
    }

    while(i < m){
        memcpy((char*)arr + k * size, arr1 + i * size, size);
        i++;
        k++;
    }

    while(j < n){
        memcpy((char*)arr + k * size, arr2 + j * size, size);
        j++;
        k++;
    }

    free(arr1);
    free(arr2);
}

void mergeSortRec(void *arr, size_t left, size_t right, size_t size, int(*cmp)(const void*, const void*)){
    if(left < right){
        size_t mid = left + (right - left) / 2;
        mergeSortRec(arr, left, mid, size, cmp);
        mergeSortRec(arr, mid + 1, right, size, cmp);
        mergeArr(arr, left, mid, right, size, cmp);
    }
}

void mergeSort(void *arr, size_t n, size_t size, int(*cmp)(const void*, const void*)){
    mergeSortRec(arr, 0, n - 1, size, cmp);
}

// Quick Sort
void quickSortRec(void* arr, size_t left, size_t right, size_t size, int(*cmp)(const void*, const void*)){
    if(left < right){
        char* array = (char*)arr;
        size_t pivotIndex = left + (right - left) / 2;
        char* pivot = (char*)malloc(size);
        memcpy(pivot, array + pivotIndex * size, size);

        size_t i = left, j = right;
        while(i <= j){
            while(cmp(array + i * size, pivot) < 0) i++;
            while(cmp(array + j * size, pivot) > 0) j--;
            if(i <= j){
                swap(array + i * size, array + j * size, size);
                i++;
                j--;
            }
        }

        free(pivot);
        if(left < j) quickSortRec(arr, left, j, size, cmp);
        if(i < right) quickSortRec(arr, i, right, size, cmp);
    }
}

void quickSort(void *arr, size_t n, size_t size, int(*cmp)(const void*, const void*)){
    quickSortRec(arr, 0, n - 1, size, cmp);
}

// Check if dataset is small then go for quick sort otherwise do merge sort
void sort(void* arr, size_t n, size_t size, int(*cmp)(const void*, const void*)){
    if(n < 16){
        quickSort(arr, n, size, cmp);
    } else {
        mergeSort(arr, n, size, cmp);
    }
}
