#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// Graph structure
typedef struct {
    int vertices;
    int adj[MAX][MAX];
} Graph;

// Function to create a graph
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    
    // Initialize adjacency matrix with 0
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adj[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1;  // For undirected graph
}

// DFS utility function (recursive)
void DFS_util(Graph* graph, int vertex, int visited[]) {
    // Mark current vertex as visited
    visited[vertex] = 1;
    printf("%d ", vertex);
    
    // Recur for all adjacent vertices
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adj[vertex][i] == 1 && !visited[i]) {
            DFS_util(graph, i, visited);
        }
    }
}

// DFS traversal function
void DFS(Graph* graph, int startVertex) {
    int visited[MAX] = {0};
    
    printf("DFS Traversal starting from vertex %d: ", startVertex);
    DFS_util(graph, startVertex, visited);
    printf("\n");
}

// Function to display the adjacency matrix
void displayGraph(Graph* graph) {
    printf("\nAdjacency Matrix:\n");
    printf("   ");
    for (int i = 0; i < graph->vertices; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < graph->vertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < graph->vertices; j++) {
            printf("%d ", graph->adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices = 6;
    Graph* graph = createGraph(vertices);
    
    // Adding edges
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);
    
    // Display the graph
    displayGraph(graph);
    
    // Perform DFS traversal
    printf("\n");
    DFS(graph, 0);
    
    // Free memory
    free(graph);
    
    return 0;
}