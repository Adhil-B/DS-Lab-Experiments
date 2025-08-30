#include <stdio.h>
#define MAX_VERTICES 100

int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];

void dfsRecursive(int vertex, int numVertices) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    for (int i = 0; i < numVertices; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            dfsRecursive(i, numVertices);
        }
    }
}

void dfs(int startVertex, int numVertices) {
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }
    
    dfsRecursive(startVertex, numVertices);
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
        dfs(startVertex, numVertices);
    }
    
    return 0;
}