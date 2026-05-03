#include<stdio.h>

int find_kth_largest(int arr[], int size, int k)
{
    int i, j, temp;
    
    for(i = 0; i < k; i++)
    {
        for(j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    return arr[size - k];
}

int main()
{
    int n, k, i, arr[100000];
    
    scanf("%d", &n);
    
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    scanf("%d", &k);
    
    printf("%d", find_kth_largest(arr, n, k));
    
    return 0;
}
