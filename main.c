// #include <stdio.h>
// // #include "Headers_files/searching/searching.h"
// // #include "Headers_files/sorting/sorting.h"
// // #include "Headers_files/String/String.h"
// #include "Headers_files/Linked_List/linkedList.h"

// int main(){

//     //  --- Searching ---

//     // int arr[] = {1, 3, 6, 7, 9};
//     // int target = 9;

//     //    >> Linear Search <<
//     // int ans1 = l_search(arr, &target, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]));
//     // printf("Linear Search : %d\n", ans1);

//     //    >> Binary Search <<
//     // int ans2 = b_search(arr, &target, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]));
//     // printf("Binary Search : %d\n", ans2);

//     //  --- Searching End ---

//     //  --- Sorting Start ---

//     // int arr1[] = {5, 2, 9, 4, 5, 6};
//     // selectionSort(arr1, sizeof(arr1)/sizeof(arr1[0]), sizeof(arr1[0]), compareInt);

//     // for(int i = 0; i<6; i++){
//     //     printf("%d ", arr1[i]);
//     // }
//     // printf("\n");

//     //  --- Sorting End ---

//     //  --- Custom String Start ---

//     // String str = create();

//     // printf("Enter a string: ");
//     // readS(&str);

//     // printf("Your input: %s\n", getS(&str));

//     // printf("String Length: %zu\n", lenghtS(&str));

//     // printf("Check String is Empty or not : %d\n", isemptyS(&str));

//     // String str2 = create();

//     // printf("Enter the string to reverse : ");
//     // readS(&str2);
//     // reverseS(&str2);
//     // printf("Reverse String %s\n", getS(&str2));

//     // freeS(&str);
//     // freeS(&str2);

//     //  --- Custom String End ---

//     //  --- Linked List Start ---

//     Node* head = NULL;

//     InsertAtHead(&head, 10);
//     InsertAtHead(&head, 5);
//     InsertAtTail(&head, 20);
//     InsertAtTail(&head, 25);

//     printf("Initial list: ");
//     PrintList(head);

//     InsertAtPosition(&head, 15, 3);
//     printf("After inserting 15 at position 3 : ");
//     PrintList(head);

//     int position = SearchList(head, 20);
//     if (position != -1) {
//         printf("Element 20 found at position: %d\n", position);
//     } else {
//         printf("Element 20 not found in the list.\n");
//     }

//     int length = LengthList(head);
//     printf("List length: %d\n", length);

//     DeleteByValue(&head, 10);
//     printf("After deleting the value 10: ");
//     PrintList(head);

//     DeleteAtPosition(&head, 2);
//     printf("After deleting the node at position 2: ");
//     PrintList(head);

//     SortList(&head);
//     printf("After sorting the list: ");
//     PrintList(head);

//     DeleteList(&head);
//     printf("After deleting the entire list: ");
//     PrintList(head);

//     //  --- Linked List End ---

//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Headers_files/searching/searching.h"
#include "Headers_files/sorting/sorting.h"
#include "Headers_files/String/String.h"
#include "Headers_files/Linked_List/linkedList.h"

// Book structure
typedef struct {
    char title[100];
    char author[100];
    int year;
} Book;

// Helper functions
void print_book(const Book* book) {
    printf("Title: %s, Author: %s, Year: %d\n", book->title, book->author, book->year);
}

int compare_books(const void* a, const void* b) {
    return strcmp(((Book*)a)->title, ((Book*)b)->title);
}

// Function to read a string
void read_string(String* str) {
    char buffer[256];
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; 
    appendS(str, buffer);
}

void menu() {
    printf("Library Management System\n");
    printf("1. Add Book\n");
    printf("2. Display Books\n");
    printf("3. Search Book\n");
    printf("4. Remove Book\n");
    printf("5. Update Book\n");
    printf("6. Clear Library\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

// Function to load books from file into an array
int load_books_from_file(Book* books, int max_books) {
    FILE *file = fopen("library_data.txt", "r");
    if (file == NULL) {
        perror("Unable to open file");
        return 0;
    }
    int count = 0;
    char line[256];
    while (fgets(line, sizeof(line), file) && count < max_books) {
        sscanf(line, "%99[^;];%99[^;];%d", books[count].title, books[count].author, &books[count].year);
        count++;
    }
    fclose(file);
    return count;
}

// Function to save a single book to file
void save_book_to_file(const Book* book) {
    FILE *file = fopen("library_data.txt", "a");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }
    fprintf(file, "%s;%s;%d\n", book->title, book->author, book->year);
    fclose(file);
}

// Function to overwrite the entire book file
void save_all_books_to_file(Book* books, int count) {
    FILE *file = fopen("library_data.txt", "w");
    if (file == NULL) {
        perror("Unable to open file");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s;%s;%d\n", books[i].title, books[i].author, books[i].year);
    }
    fclose(file);
}

// Function to remove a book from the list by title 
void remove_book(Book* books, int* book_count, const char* title) {
    int index = -1;
    for (int i = 0; i < *book_count; i++) {
        if (strcmp(books[i].title, title) == 0) {
            index = i;
            break;
        }
    }

    if (index >= 0) {
        for (int i = index; i < *book_count - 1; i++) {
            books[i] = books[i + 1];
        }
        (*book_count)--;
        save_all_books_to_file(books, *book_count);
        printf("Book removed successfully.\n");
    } else {
        printf("Book not found.\n");
    }
}

// Function to clear the entire library (delete all books)
void clear_library() {
    FILE *file = fopen("library_data.txt", "w");
    if (file != NULL) {
        fclose(file);
        printf("Library cleared successfully.\n");
    } else {
        perror("Unable to clear library");
    }
}

// Function to update a book's information
void update_book(Book* books, int book_count, const char* title) {
    int index = -1;
    for (int i = 0; i < book_count; i++) {
        if (strcmp(books[i].title, title) == 0) {
            index = i;
            break;
        }
    }

    if (index >= 0) {
        printf("Enter new title: ");
        String new_title = create();
        read_string(&new_title);
        
        printf("Enter new author: ");
        String new_author = create();
        read_string(&new_author);
        
        printf("Enter new year: ");
        int new_year;
        scanf("%d", &new_year);
        getchar(); // Consume newline character

        strcpy(books[index].title, getS(&new_title));
        strcpy(books[index].author, getS(&new_author));
        books[index].year = new_year;

        save_all_books_to_file(books, book_count);
        printf("Book updated successfully.\n");

        freeS(&new_title);
        freeS(&new_author);
    } else {
        printf("Book not found.\n");
    }
}

int main() {
    Book books[10000];   
    int book_count = load_books_from_file(books, 10000);  // Load books from file at the start
    int choice;
    String title_str = create();
    String author_str = create();
    int year;

    while (1) {
        menu();
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                // Add Book
                printf("Enter title: ");
                read_string(&title_str);

                printf("Enter author: ");
                read_string(&author_str);

                printf("Enter year: ");
                scanf("%d", &year);
                getchar(); // Consume newline character

                // Create a new book and save to file
                if (book_count < 10000) {
                    strcpy(books[book_count].title, getS(&title_str));
                    strcpy(books[book_count].author, getS(&author_str));
                    books[book_count].year = year;
                    save_book_to_file(&books[book_count]);  // Save the new book to file
                    book_count++;
                } else {
                    printf("Library is full!\n");
                }

                // Clear strings for next input
                freeS(&title_str);
                freeS(&author_str);
                title_str = create();
                author_str = create();
                break;

            case 2:
                // Display Books
                if (book_count == 0) {
                    printf("No books to display.\n");
                } else {
                    // Reload books from file before displaying
                    book_count = load_books_from_file(books, 10000);
                    sort(books, book_count, sizeof(Book), compare_books);  // Sort before displaying

                    printf("Books:\n");
                    for (int i = 0; i < book_count; i++) {
                        print_book(&books[i]);
                    }
                }
                break;

            case 3:
                // Search Book
                printf("Enter title to search: ");
                read_string(&title_str);

                // Reload books from file before searching
                book_count = load_books_from_file(books, 10000);
                int index = b_search(books, getS(&title_str), book_count, sizeof(Book), compare_books);

                if (index >= 0) {
                    print_book(&books[index]);
                } else {
                    printf("Book not found.\n");
                }

                // Clear string
                freeS(&title_str);
                title_str = create();
                break;

            case 4:
                // Remove Book
                printf("Enter title of the book to remove: ");
                read_string(&title_str);

                remove_book(books, &book_count, getS(&title_str));

                // Clear string
                freeS(&title_str);
                title_str = create();
                break;

            case 5:
                // Update Book
                printf("Enter title of the book to update: ");
                read_string(&title_str);

                update_book(books, book_count, getS(&title_str));

                // Clear string
                freeS(&title_str);
                title_str = create();
                break;

            case 6:
                // Clear Library
                clear_library();
                book_count = 0;  // Reset book count
                break;

            case 7:
                // Exit
                freeS(&title_str);
                freeS(&author_str);
                exit(0);

            default:
                printf("Invalid choice, try again.\n");
        }
    }

    return 0;
}
