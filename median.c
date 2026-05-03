#include<stdio.h>

int find_median(int arr[], int size)
{
    int i, j, min, temp;
    for(i = 0; i <= size/2; i++)
    {
        min = i;
        for(j = i+1; j < size; j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    return arr[size/2];
}

int main()
{
    int n, i, arr[100000];

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d", find_median(arr, n));

    return 0;
}
