#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the graph
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a structure for an adjacency list
typedef struct AdjList {
    Node* head;
} AdjList;

// Define a structure for a graph
typedef struct Graph {
    int numVertices;
    AdjList* adjLists;
} Graph;

// Function to create a new node
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a graph with a given number of vertices
Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjLists = (AdjList*)malloc(numVertices * sizeof(AdjList));
    for (int i = 0; i < numVertices; i++) {
        graph->adjLists[i].head = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src].head;
    graph->adjLists[src].head = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest].head;
    graph->adjLists[dest].head = newNode;
}

// Function to perform BFS traversal
void bfs(Graph* graph, int startVertex) {
    int visited[graph->numVertices];
    for (int i = 0; i < graph->numVertices; i++) {
        visited[i] = 0;
    }

    int queue[graph->numVertices];
    int front = 0, rear = 0;

    queue[rear++] = startVertex;
    visited[startVertex] = 1;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        Node* temp = graph->adjLists[vertex].head;
        while (temp != NULL) {
            if (!visited[temp->data]) {
                queue[rear++] = temp->data;
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    // Create a graph with 5 vertices
    Graph* graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);

    // Perform BFS traversal
    printf("BFS Traversal: ");
    bfs(graph, 0);

    return 0;
}