#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int data) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack Overflow!\n");
        return;
    }
    stack[++top] = data;
    printf("Pushed %d to stack\n", data);
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow!\n");
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (top < 0) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack[top];
}

void displayStack() {
    if (top < 0) {
        printf("Stack is empty!\n");
        return;
    }
    
    printf("Stack elements: ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void stackOperations() {
    printf("\n=== STACK OPERATIONS ===\n");
    int choice, data;
    
    while (1) {
        printf("\nStack Menu:\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
                
            case 2:
                data = pop();
                if (data != -1) {
                    printf("Popped element: %d\n", data);
                }
                break;
                
            case 3:
                data = peek();
                if (data != -1) {
                    printf("Top element: %d\n", data);
                }
                break;
                
            case 4:
                displayStack();
                break;
                
            case 5:
                return;
                
            default:
                printf("Invalid choice!\n");
        }
    }
}
