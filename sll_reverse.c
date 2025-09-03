#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the end of the list
void insertEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to reverse the linked list
void reverseList(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    
    while (current != NULL) {
        next = current->next;  // Store next node
        current->next = prev;  // Reverse current node's pointer
        prev = current;        // Move prev to current
        current = next;        // Move to next node
    }
    
    *head = prev;  // Update head to new front of list
}

// Function to print linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;
    
    int size, value;
    
    scanf("%d", &size);
    printf("Enter list elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &value);
        insertEnd(&head, value);
    }
    
    printf("Original list:\n");
    printList(head);
    
    reverseList(&head);
    
    printf("\nReversed list:\n");
    printList(head);
    
    return 0;
}