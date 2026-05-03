#include<stdio.h>

#define INF 999999

void prims_mst(int graph[100][100], int V)
{
    int selected[100] = {0};
    int i, j, x, y;
    int edges = 0;
    int total = 0;

    selected[0] = 1;

    printf("Edge Weight\n");

    while(edges < V - 1)
    {
        int min = INF;
        x = 0;
        y = 0;

        for(i = 0; i < V; i++)
        {
            if(selected[i])
            {
                for(j = 0; j < V; j++)
                {
                    if(!selected[j] && graph[i][j])
                    {
                        if(graph[i][j] < min)
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d %d\n", x, y, graph[x][y]);
        total += graph[x][y];
        selected[y] = 1;
        edges++;
    }

    printf("Total weight: %d", total);
}

int main()
{
    int V, i, j;
    int graph[100][100];

    scanf("%d", &V);

    for(i = 0; i < V; i++)
        for(j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    prims_mst(graph, V);

    return 0;
}
