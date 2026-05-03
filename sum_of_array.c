#include<stdio.h>

int array_sum(int arr[], int size)
{
    if(size == 1) return arr[0];
    return arr[size-1] + array_sum(arr, size-1);
}

int main()
{
    int n, i, arr[1000];
    
    scanf("%d", &n);
    
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("%d", array_sum(arr, n));
    
    return 0;
}
