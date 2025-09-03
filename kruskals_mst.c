#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100

typedef struct Edge {
    int src, dest, weight;
} Edge;

typedef struct Subset {
    int parent;
    int rank;
} Subset;

int compare(const void* a, const void* b) {
    Edge* edge1 = (Edge*)a;
    Edge* edge2 = (Edge*)b;
    return edge1->weight - edge2->weight;
}

int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);
    
    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

void kruskalMST(Edge edges[], int numEdges) {
    qsort(edges, numEdges, sizeof(edges[0]), compare);
    
    Edge result[MAX_EDGES];
    int e = 0, i = 0;
    
    Subset* subsets = (Subset*)malloc(sizeof(Subset));
    
    for (int v = 0; v < numEdges; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    
    while (e < numEdges - 1 && i < numEdges) {
        Edge next_edge = edges[i++];
        
        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);
        
        if (x != y) {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
    }
    
    printf("Edge \tWeight\n");
    for (i = 0; i < e; i++)
        printf("%d - %d \t%d\n", result[i].src, result[i].dest, result[i].weight);
}

int main() {
    Edge edges[] = {
        {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, 
        {1, 3, 8}, {1, 4, 5}, {2, 4, 7}, 
        {3, 4, 9}
    };
    
    int numEdges = sizeof(edges) / sizeof(edges[0]);
    
    kruskalMST(edges, numEdges);
    
    return 0;
}