#include <stdio.h>
#define INF 9999
#define MAX_SIZE 100

// Function to find the vertex with the minimum distance value
int minDistance(int dist[], int visited[], int vertices)
{
    int min = INF, min_index;

    for (int v = 0; v < vertices; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

// Function to print the constructed distance array
void printSolution(int dist[], int vertices)
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < vertices; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

// Function that implements Dijkstra's algorithm
void dijkstra(int graph[MAX_SIZE][MAX_SIZE], int source, int vertices)
{
    int dist[MAX_SIZE];
    int visited[MAX_SIZE];

    // Initialize all distances as INFINITE and visited[] as 0
    for (int i = 0; i < vertices; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    // Distance of source vertex from itself is always 0
    dist[source] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < vertices - 1; count++) {
        int u = minDistance(dist, visited, vertices);

        // Mark the picked vertex as visited
        visited[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
        }
    }

    // Print the constructed distance array
    printSolution(dist, vertices);
}

int main()
{
    int vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int graph[MAX_SIZE][MAX_SIZE];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(graph, source, vertices);

    return 0;
}

