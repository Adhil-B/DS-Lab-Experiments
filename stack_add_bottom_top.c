#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Initialize stack
void initStack(Stack* stack) {
    stack->top = -1;
}

// Check if stack is full
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Check if stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Push to stack
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Error: Stack overflow\n");
        exit(1);
    }
    stack->items[++stack->top] = value;
}

// Pop from stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack underflow\n");
        exit(1);
    }
    return stack->items[stack->top--];
}

// Get bottom element
int getBottom(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty\n");
        exit(1);
    }
    
    // Store elements in a temporary stack
    Stack tempStack;
    initStack(&tempStack);
    
    while (!isEmpty(stack)) {
        push(&tempStack, pop(stack));
    }
    
    int bottom = tempStack.items[tempStack.top];
    
    // Restore original stack
    while (!isEmpty(&tempStack)) {
        push(stack, pop(&tempStack));
    }
    
    return bottom;
}

int main() {
    Stack stack;
    initStack(&stack);
    
    int size;
    scanf("%d", &size);
    
    printf("Enter stack elements (bottom to top):\n");
    for (int i = 0; i < size; i++) {
        int value;
        scanf("%d", &value);
        push(&stack, value);
    }
    
    int bottom = getBottom(&stack);
    int top = stack.items[stack.top];
    
    printf("Bottom element: %d\n", bottom);
    printf("Top element: %d\n", top);
    printf("Sum of bottom and top: %d\n", bottom + top);
    
    return 0;
}