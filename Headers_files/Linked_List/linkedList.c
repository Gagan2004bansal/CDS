#include "linkedList.h"


Node* CreateList(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory Allocation Failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void InsertAtHead(Node** head, int data) {
    Node* temp = CreateList(data);
    temp->next = *head;
    *head = temp;
}


void InsertAtTail(Node** head, int data) {
    Node* temp = CreateList(data);
    if (*head == NULL) {
        *head = temp;
        return;
    }

    Node* temp1 = *head; 
    while (temp1->next) {
        temp1 = temp1->next;
    }
    temp1->next = temp;  
}


void InsertAtPosition(Node** head, int data, int position) {
    if (position < 1) {
        printf("Position must be >= 1\n");
        return;
    }

    if (position == 1) {
        InsertAtHead(head, data);
        return;
    }

    Node* temp = CreateList(data);
    Node* temp1 = *head; 

    for (int i = 1; i < position - 1 && temp1 != NULL; i++) {
        temp1 = temp1->next;
    }

    if (temp1 == NULL) {
        printf("Position out of bounds\n");
    } else {
        temp->next = temp1->next;
        temp1->next = temp;
    }
}


void DeleteByValue(Node** head, int data) {
    if (*head == NULL) {
        return;
    }

    Node* temp = *head;
    if (temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    Node* prev = NULL;
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}


void DeleteAtPosition(Node** head, int position) {
    if (*head == NULL || position < 1) {
        printf("Position should be >= 1\n");
        return;
    }

    Node* temp = *head;

    if (position == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    Node* prev = NULL;
    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}


void DeleteList(Node** head) {
    Node* current = *head;  
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}


void PrintList(Node* head) {  
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int SearchList(Node* head, int data) { 
    Node* temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == data) {
            return position;
        }
        temp = temp->next;
        position++;
    }

    return -1;  
}


int LengthList(Node* head) {  
    int length = 0;
    Node* temp = head;
    while (temp != NULL) {
        length++; 
        temp = temp->next;
    }
    return length;
}


Node* mergeTwoLists(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node* result = NULL;

    if (head1->data <= head2->data) {
        result = head1;
        result->next = mergeTwoLists(head1->next, head2);
    } else {
        result = head2;
        result->next = mergeTwoLists(head1, head2->next);
    }

    return result;
}


Node* get_middle(Node* head) {
    if (!head) return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}


void SortList(Node** head) {
    if (!(*head) || !(*head)->next) {
        return;
    }

    Node* middle = get_middle(*head);
    Node* next_of_middle = middle->next;

    middle->next = NULL;

    Node* left = *head;
    Node* right = next_of_middle;

    SortList(&left);
    SortList(&right);

    *head = mergeTwoLists(left, right);
}
