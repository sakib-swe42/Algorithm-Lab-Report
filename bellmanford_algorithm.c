#include<stdio.h>

#define INF 999999

typedef struct {
    int u, v, w;
} Edge;

void bellman_ford(int V, int E, Edge edges[], int src)
{
    int dist[100], i, j;

    for(i = 0; i < V; i++)
        dist[i] = INF;

    dist[src] = 0;

    for(i = 0; i < V-1; i++)
    {
        for(j = 0; j < E; j++)
        {
            if(dist[edges[j].u] != INF && dist[edges[j].u] + edges[j].w < dist[edges[j].v])
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
        }
    }

    for(j = 0; j < E; j++)
    {
        if(dist[edges[j].u] != INF && dist[edges[j].u] + edges[j].w < dist[edges[j].v])
        {
            printf("Graph contains a negative-weight cycle");
            return;
        }
    }

    printf("Vertex Distance from Source\n");
    for(i = 0; i < V; i++)
        printf("%d %d\n", i, dist[i]);
}

int main()
{
    int V, E, i, src;
    Edge edges[100];

    scanf("%d %d", &V, &E);

    for(i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    scanf("%d", &src);

    bellman_ford(V, E, edges, src);

    return 0;
}
