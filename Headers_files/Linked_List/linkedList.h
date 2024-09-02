#ifndef LINKED_LIST
#define LINKED_LIST

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Functions
Node* CreateList(int data);
void InsertAtHead(Node** head, int data);
void InsertAtTail(Node** head, int data);
void InsertAtPosition(Node** head, int data, int position);
void DeleteByValue(Node** head, int data);
void DeleteAtPosition(Node** head, int position);
void DeleteList(Node** head);
void PrintList(Node* head);
int SearchList(Node* head, int data);
int LengthList(Node* head);
void SortList(Node** head);

#endif
