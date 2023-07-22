
#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numNodes;
    struct Node* adjList[MAX_NODES];
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;
}

void dfs(struct Graph* graph, int startNode) {
    bool visited[MAX_NODES] = { false };
    struct Node* stack[MAX_NODES];
    int top = -1;

    stack[++top] = createNode(startNode);

    while (top != -1) {
        struct Node* currentNode = stack[top--];
        int vertex = currentNode->vertex;

        if (!visited[vertex]) {
            visited[vertex] = true;
            printf("%d ", vertex);

            struct Node* neighbor = graph->adjList[vertex];
            while (neighbor != NULL) {
                int neighborVertex = neighbor->vertex;
                if (!visited[neighborVertex]) {
                    stack[++top] = createNode(neighborVertex);
                }
                neighbor = neighbor->next;
            }
        }
    }
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &graph->numNodes);
    for (int i = 0; i < graph->numNodes; i++) {
        graph->adjList[i] = NULL;
    }

    int numEdges;
    printf("Enter the number of edges: ");
    scanf("%d", &numEdges);

    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        printf("Enter the source and destination of edge %d: ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startNode;
    printf("Enter the starting node for DFS: ");
    scanf("%d", &startNode);

    printf("DFS traversal starting from node %d: ", startNode);
    dfs(graph, startNode);

    return 0;
}
