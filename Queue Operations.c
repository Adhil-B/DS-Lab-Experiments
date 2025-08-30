#define QUEUE_SIZE 100

int queue[QUEUE_SIZE];
int front = -1, rear = -1;

void enqueue(int data) {
    if (rear >= QUEUE_SIZE - 1) {
        printf("Queue Overflow!\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = data;
    printf("Enqueued %d to queue\n", data);
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow!\n");
        return -1;
    }
    return queue[front++];
}

void displayQueue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void queueOperations() {
    printf("\n=== QUEUE OPERATIONS ===\n");
    int choice, data;
    
    while (1) {
        printf("\nQueue Menu:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
                
            case 2:
                data = dequeue();
                if (data != -1) {
                    printf("Dequeued element: %d\n", data);
                }
                break;
                
            case 3:
                displayQueue();
                break;
                
            case 4:
                return;
                
            default:
                printf("Invalid choice!\n");
        }
    }
}
