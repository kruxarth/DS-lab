#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure for queue node
typedef struct QueueNode {
    int data;
    struct QueueNode* next;
} QueueNode;

// Structure for queue
typedef struct Queue {
    QueueNode *front, *rear;
} Queue;

// Structure for adjacency list node
typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

// Structure for adjacency list
typedef struct AdjList {
    AdjListNode* head;
} AdjList;

// Structure for graph
typedef struct Graph {
    int numVertices;
    AdjList* array;
} Graph;

// Function to create a new queue
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to check if queue is empty
int isEmpty(Queue* q) {
    return q->front == NULL;
}

// Function to enqueue
void enqueue(Queue* q, int value) {
    QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
    temp->data = value;
    temp->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }
    
    q->rear->next = temp;
    q->rear = temp;
}

// Function to dequeue
int dequeue(Queue* q) {
    if (isEmpty(q))
        return -1;
    
    QueueNode* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    
    if (q->front == NULL)
        q->rear = NULL;
    
    free(temp);
    return data;
}

// Function to create a new adjacency list node
AdjListNode* newAdjListNode(int dest) {
    AdjListNode* newNode = (AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with n vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->array = (AdjList*)malloc(vertices * sizeof(AdjList));
    
    for (int i = 0; i < vertices; i++)
        graph->array[i].head = NULL;
    
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    
    // Add edge from dest to src (for undirected graph)
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to perform BFS traversal
void BFS(Graph* graph, int startVertex) {
    int visited[MAX] = {0};
    Queue* q = createQueue();
    
    printf("BFS Traversal starting from vertex %d: ", startVertex);
    
    visited[startVertex] = 1;
    enqueue(q, startVertex);
    
    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);
        
        AdjListNode* temp = graph->array[currentVertex].head;
        while (temp) {
            int adjVertex = temp->dest;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Function to print the graph
void printGraph(Graph* graph) {
    printf("\nGraph Adjacency List:\n");
    for (int i = 0; i < graph->numVertices; i++) {
        AdjListNode* temp = graph->array[i].head;
        printf("Vertex %d: ", i);
        while (temp) {
            printf("-> %d ", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int vertices = 6;
    Graph* graph = createGraph(vertices);
    
    // Creating a sample graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);
    
    printGraph(graph);
    
    printf("\n");
    BFS(graph, 0);
    
    return 0;
}