#include<stdio.h>

int array_max(int arr[], int size)
{
    if(size == 1) return arr[0];
    
    int max = array_max(arr, size-1);
    
    if(arr[size-1] > max) return arr[size-1];
    return max;
}

int main()
{
    int n, i, arr[1000];
    
    scanf("%d", &n);
    
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("%d", array_max(arr, n));
    
    return 0;
}
