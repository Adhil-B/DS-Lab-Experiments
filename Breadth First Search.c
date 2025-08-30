#define MAX_VERTICES 100

int adjMatrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int bfsQueue[MAX_VERTICES];
int bfsFront = -1, bfsRear = -1;

void bfsEnqueue(int vertex) {
    if (bfsRear >= MAX_VERTICES - 1) return;
    if (bfsFront == -1) bfsFront = 0;
    bfsQueue[++bfsRear] = vertex;
}

int bfsDequeue() {
    if (bfsFront == -1 || bfsFront > bfsRear) return -1;
    return bfsQueue[bfsFront++];
}

int isBfsQueueEmpty() {
    return (bfsFront == -1 || bfsFront > bfsRear);
}

void bfs(int startVertex, int numVertices) {
    printf("BFS traversal starting from vertex %d: ", startVertex);
    
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }
    
    bfsFront = bfsRear = -1;
    visited[startVertex] = 1;
    bfsEnqueue(startVertex);
    
    while (!isBfsQueueEmpty()) {
        int currentVertex = bfsDequeue();
        printf("%d ", currentVertex);
        
        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = 1;
                bfsEnqueue(i);
            }
        }
    }
    printf("\n");
}

void breadthFirstSearch() {
    printf("\n=== BREADTH FIRST SEARCH ===\n");
    int numVertices, numEdges, u, v, startVertex;
    
    printf("Enter number of vertices: ");
    scanf("%d", &numVertices);
    
    // Initialize adjacency matrix
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            adjMatrix[i][j] = 0;
        }
    }
    
    printf("Enter number of edges: ");
    scanf("%d", &numEdges);
    
    printf("Enter edges (u v):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d", &u, &v);
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // For undirected graph
    }
    
    printf("Enter starting vertex: ");
    scanf("%d", &startVertex);
    
    bfs(startVertex, numVertices);
}
