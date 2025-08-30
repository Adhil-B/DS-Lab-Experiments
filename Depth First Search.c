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
    printf("DFS traversal starting from vertex %d: ", startVertex);
    
    for (int i = 0; i < numVertices; i++) {
        visited[i] = 0;
    }
    
    dfsRecursive(startVertex, numVertices);
    printf("\n");
}

void depthFirstSearch() {
    printf("\n=== DEPTH FIRST SEARCH ===\n");
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
    
    dfs(startVertex, numVertices);
}
int main() {
    int choice;
    
    while (1) {
        printf("\n========== MAIN MENU ==========\n");
        printf("1.  Matrix Multiplication\n");
        printf("2.  Odd or Even Number Check\n");
        printf("3.  Factorial (Without Recursion)\n");
        printf("4.  Fibonacci (Without Recursion)\n");
        printf("5.  Factorial (With Recursion)\n");
        printf("6.  Fibonacci (With Recursion)\n");
        printf("7.  Array Operations\n");
        printf("8.  Linear Search\n");
        printf("9.  Binary Search\n");
        printf("10. Linked List Operations\n");
        printf("11. Stack Operations\n");
        printf("12. Stack Application (Infix to Postfix)\n");
        printf("13. Queue Operations\n");
        printf("14. Tree Traversals\n");
        printf("15. AVL Tree Operations\n");
        printf("16. Breadth First Search (BFS)\n");
        printf("17. Depth First Search (DFS)\n");
        printf("18. Exit\n");
        printf("===============================\n");
        printf("Enter your choice (1-18): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: matrixMultiplication(); break;
            case 2: oddEvenCheck(); break;
            case 3: factorialIterative(); break;
            case 4: fibonacciIterative(); break;
            case 5: factorialWithRecursion(); break;
            case 6: fibonacciWithRecursion(); break;
            case 7: arrayOperations(); break;
            case 8: linearSearch(); break;
            case 9: binarySearch(); break;
            case 10: linkedListOperations(); break;
            case 11: stackOperations(); break;
            case 12: infixToPostfix(); break;
            case 13: queueOperations(); break;
            case 14: treeTraversals(); break;
            case 15: avlTreeOperations(); break;
            case 16: breadthFirstSearch(); break;
            case 17: depthFirstSearch(); break;
            case 18: 
                printf("Thank you for using the program!\n");
                printf("==========================================\n");
                exit(0);
            default: 
                printf("Invalid choice! Please enter a number between 1-18.\n");
        }
        
        printf("\nPress Enter to continue...");
        getchar(); // Clear input buffer
        getchar(); // Wait for Enter
    }
    
    return 0;
}
