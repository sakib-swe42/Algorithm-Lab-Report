#include<stdio.h>

#define INF 999999

int min_distance(int dist[], int visited[], int V)
{
    int min = INF, index = -1, i;
    for(i = 0; i < V; i++)
    {
        if(!visited[i] && dist[i] < min)
        {
            min = dist[i];
            index = i;
        }
    }
    return index;
}

void dijkstra(int graph[100][100], int src, int V)
{
    int dist[100], visited[100] = {0};
    int i, j;

    for(i = 0; i < V; i++)
        dist[i] = INF;

    dist[src] = 0;

    for(i = 0; i < V-1; i++)
    {
        int u = min_distance(dist, visited, V);
        visited[u] = 1;

        for(j = 0; j < V; j++)
        {
            if(!visited[j] && graph[u][j] && dist[u] + graph[u][j] < dist[j])
                dist[j] = dist[u] + graph[u][j];
        }
    }

    printf("Vertex Distance from Source\n");
    for(i = 0; i < V; i++)
        printf("%d %d\n", i, dist[i]);
}

int main()
{
    int V, i, j, src;
    int graph[100][100];

    scanf("%d", &V);

    for(i = 0; i < V; i++)
        for(j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    scanf("%d", &src);

    dijkstra(graph, src, V);

    return 0;
}
