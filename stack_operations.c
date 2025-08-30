#include <stdio.h>
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

int isEmpty() {
    return top == -1;
}

int isFull() {
    return top == MAX_SIZE - 1;
}

void push(int data) {
    if (isFull()) {
        return;
    }
    stack[++top] = data;
}

int pop() {
    if (isEmpty()) {
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (isEmpty()) {
        return -1;
    }
    return stack[top];
}

void display() {
    if (isEmpty()) {
        return;
    }
    
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, data, result;
    
    while (1) {
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                scanf("%d", &data);
                push(data);
                break;
                
            case 2:
                result = pop();
                if (result != -1) {
                    printf("%d\n", result);
                }
                break;
                
            case 3:
                result = peek();
                if (result != -1) {
                    printf("%d\n", result);
                }
                break;
                
            case 4:
                display();
                break;
                
            case 5:
                return 0;
                
            default:
                break;
        }
    }
    
    return 0;
}