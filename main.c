#include <stdio.h>
#include "Headers_files/searching/searching.h"
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

    // --- Searching End --- 

    return 0;
}