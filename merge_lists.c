#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list
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

// Function to merge two linked lists
Node* mergeLists(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    
    Node* result = NULL;
    
    if (head1->data < head2->data) {
        result = head1;
        result->next = mergeLists(head1->next, head2);
    } else {
        result = head2;
        result->next = mergeLists(head1, head2->next);
    }
    
    return result;
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
    Node* head1 = NULL;
    Node* head2 = NULL;
    
    int size1, size2, value;
    
    // Read first list
    scanf("%d", &size1);
    for (int i = 0; i < size1; i++) {
        scanf("%d", &value);
        insertEnd(&head1, value);
    }
    
    // Read second list
    scanf("%d", &size2);
    for (int i = 0; i < size2; i++) {
        scanf("%d", &value);
        insertEnd(&head2, value);
    }
    
    // Merge and print
    Node* mergedList = mergeLists(head1, head2);
    printList(mergedList);
    
    return 0;
}