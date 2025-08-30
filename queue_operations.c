#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return rear == MAX_SIZE - 1;
}

void enqueue(int data) {
    if (isFull()) {
        return;
    }
    
    if (isEmpty()) {
        front = 0;
    }
    
    queue[++rear] = data;
}

int dequeue() {
    if (isEmpty()) {
        return -1;
    }
    
    int data = queue[front];
    
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    
    return data;
}

int peek() {
    if (isEmpty()) {
        return -1;
    }
    return queue[front];
}

void display() {
    if (isEmpty()) {
        return;
    }
    
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
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
                enqueue(data);
                break;
                
            case 2:
                result = dequeue();
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