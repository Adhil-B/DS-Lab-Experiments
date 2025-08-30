#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(int data) {
    if (head == NULL) {
        return;
    }
    
    if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }
    
    if (temp->next != NULL) {
        struct Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        free(nodeToDelete);
    }
}

void displayList() {
    if (head == NULL) {
        return;
    }
    
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice, data;
    
    while (1) {
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
                
            case 2:
                scanf("%d", &data);
                insertAtEnd(data);
                break;
                
            case 3:
                scanf("%d", &data);
                deleteNode(data);
                break;
                
            case 4:
                displayList();
                break;
                
            case 5:
                return 0;
                
            default:
                break;
        }
    }
    
    return 0;
}