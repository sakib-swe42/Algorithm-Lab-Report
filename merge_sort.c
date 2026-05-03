#include<stdio.h>

void merge(int arr[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = 0;
    int temp[100000];

    while(i <= mid && j <= right)
    {
        if(arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid)
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

void merge_sort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    int n, i, arr[100000];

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    merge_sort(arr, 0, n - 1);

    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
