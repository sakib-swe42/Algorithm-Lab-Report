#include<stdio.h>

void insert(int out[], int *size, int value)
{
    int i = *size - 1;
    
    while(i >= 0 && out[i] > value)
    {
        out[i+1] = out[i];
        i--;
    }
    
    out[i+1] = value;
    (*size)++;
}

void merge_sorted(int a[], int n, int b[], int m, int out[])
{
    int i, size = 0;
    
    for(i = 0; i < n; i++)
        insert(out, &size, a[i]);
    
    for(i = 0; i < m; i++)
        insert(out, &size, b[i]);
}

int main()
{
    int n, m, i;
    int a[1000], b[1000], out[2000];
    
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    scanf("%d", &m);
    for(i = 0; i < m; i++)
        scanf("%d", &b[i]);
    
    merge_sorted(a, n, b, m, out);
    
    for(i = 0; i < n + m; i++)
        printf("%d ", out[i]);
    
    return 0;
}
