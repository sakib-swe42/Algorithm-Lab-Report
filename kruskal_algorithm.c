#include<stdio.h>

typedef struct {
    int u, v, w;
} Edge;

int parent[100];

int find(int x)
{
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void union_set(int a, int b)
{
    parent[find(a)] = find(b);
}

void sort(Edge e[], int E)
{
    int i, j;
    Edge temp;

    for(i = 0; i < E-1; i++)
    {
        for(j = 0; j < E-i-1; j++)
        {
            if(e[j].w > e[j+1].w)
            {
                temp = e[j];
                e[j] = e[j+1];
                e[j+1] = temp;
            }
        }
    }
}

void kruskals_mst(Edge e[], int E, int V)
{
    int i;
    int total = 0;

    for(i = 0; i < V; i++)
        parent[i] = i;

    sort(e, E);

    printf("Edge Weight\n");

    for(i = 0; i < E; i++)
    {
        if(find(e[i].u) != find(e[i].v))
        {
            printf("%d - %d %d\n", e[i].u, e[i].v, e[i].w);
            total += e[i].w;
            union_set(e[i].u, e[i].v);
        }
    }

    printf("Total weight: %d", total);
}

int main()
{
    int V, E, i;
    Edge edges[100];

    scanf("%d %d", &V, &E);

    for(i = 0; i < E; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    kruskals_mst(edges, E, V);

    return 0;
}
