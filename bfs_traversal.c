#include <stdio.h>
#define MAX_VERTICES 100

int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int queue[MAX_VERTICES];
int front = -1, rear = -1;

void enqueue(int vertex) {
    if (rear == MAX_VERTICES - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = vertex;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void bfs(int startVertex, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }
    
    front = rear = -1;
    
    visited[startVertex] = 1;
    enqueue(startVertex);
    
    while (!isEmpty()) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);
        
        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

int main() {
    int numVertices, numEdges, u, v, startVertex;
    
    scanf("%d", &numVertices);
    
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    
    scanf("%d", &numEdges);
    
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }
    
    scanf("%d", &startVertex);
    
    if (startVertex >= 0 && startVertex < numVertices) {
        bfs(startVertex, numVertices);
    }
    
    return 0;
}