#include<stdio.h>

typedef struct {
    int weight;
    int value;
    double ratio;
} Item;

void sort(Item arr[], int n)
{
    int i, j;
    Item temp;
    
    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j].ratio < arr[j+1].ratio)
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

double fractional_knapsack(Item items[], int n, int capacity)
{
    int i;
    double total = 0;

    for(i = 0; i < n; i++)
    {
        if(capacity >= items[i].weight)
        {
            total += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            total += items[i].ratio * capacity;
            break;
        }
    }

    return total;
}

int main()
{
    int n, i, capacity;
    Item items[1000];

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &items[i].weight);

    for(i = 0; i < n; i++)
        scanf("%d", &items[i].value);

    scanf("%d", &capacity);

    for(i = 0; i < n; i++)
        items[i].ratio = (double)items[i].value / items[i].weight;

    sort(items, n);

    printf("%.2lf", fractional_knapsack(items, n, capacity));

    return 0;
}
