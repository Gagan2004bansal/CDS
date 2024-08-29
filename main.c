#include <stdio.h>
#include "Headers_files/searching/searching.h"
#include "Headers_files/sorting/sorting.h"

int main(){
    

    //  --- Searching --- 
    
    int arr[] = {1, 3, 6, 7, 9};
    int target = 9;

    //    >> Linear Search << 
    int ans1 = l_search(arr, &target, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]));
    printf("Linear Search : %d\n", ans1);

    //    >> Binary Search << 
    int ans2 = b_search(arr, &target, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]));
    printf("Binary Search : %d\n", ans2);

    //  --- Searching End --- 


    //  --- Sorting Start ---
    
    int arr1[] = {5, 2, 9, 4, 5, 6};
    selectionSort(arr1, sizeof(arr1)/sizeof(arr1[0]), sizeof(arr1[0]), compareInt);

    for(int i = 0; i<6; i++){
        printf("%d ", arr1[i]);
    }
    printf("\n");
    //  --- Sorting End ---

    return 0;
}