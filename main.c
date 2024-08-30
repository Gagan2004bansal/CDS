#include <stdio.h>
// #include "Headers_files/searching/searching.h"
// #include "Headers_files/sorting/sorting.h"
#include "Headers_files/String/String.h"

int main(){
    

    //  --- Searching --- 
    
    // int arr[] = {1, 3, 6, 7, 9};
    // int target = 9;

    //    >> Linear Search << 
    // int ans1 = l_search(arr, &target, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]));
    // printf("Linear Search : %d\n", ans1);

    //    >> Binary Search << 
    // int ans2 = b_search(arr, &target, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]));
    // printf("Binary Search : %d\n", ans2);

    //  --- Searching End --- 


    //  --- Sorting Start ---
    
    // int arr1[] = {5, 2, 9, 4, 5, 6};
    // selectionSort(arr1, sizeof(arr1)/sizeof(arr1[0]), sizeof(arr1[0]), compareInt);

    // for(int i = 0; i<6; i++){
    //     printf("%d ", arr1[i]);
    // }
    // printf("\n");



    //  --- Sorting End ---


    //  --- Custom String Start ---

    String str = create();

    printf("Enter a string: ");
    readS(&str); 

    printf("Your input: %s\n", getS(&str));

    printf("String Length: %zu\n", lenghtS(&str));

    printf("Check String is Empty or not : %d\n", isemptyS(&str));

    String str2 = create();

    printf("Enter the string to reverse : ");
    readS(&str2);
    reverseS(&str2);
    printf("Reverse String %s\n", getS(&str2));

    freeS(&str); 
    freeS(&str2);

    //  --- Custom String End ---

    return 0;
}