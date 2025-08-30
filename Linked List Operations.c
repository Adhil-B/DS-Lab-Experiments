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
        printf("List is empty!\n");
        return;
    }
    
    if (head->data == data) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Node with data %d deleted\n", data);
        return;
    }
    
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != data) {
        temp = temp->next;
    }
    
    if (temp->next == NULL) {
        printf("Node with data %d not found\n", data);
    } else {
        struct Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        free(nodeToDelete);
        printf("Node with data %d deleted\n", data);
    }
}

void displayList() {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    printf("Linked List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void linkedListOperations() {
    printf("\n=== LINKED LIST OPERATIONS ===\n");
    int choice, data;
    
    while (1) {
        printf("\nLinked List Menu:\n");
        printf("1. Insert at beginning\n2. Insert at end\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
                
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
                
            case 3:
                printf("Enter data to delete: ");
                scanf("%d", &data);
                deleteNode(data);
                break;
                
            case 4:
                displayList();
                break;
                
            case 5:
                return;
                
            default:
                printf("Invalid choice!\n");
        }
    }
}
