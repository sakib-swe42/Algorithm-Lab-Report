#include<stdio.h>

int max(int a, int b)
{
    if(a > b) return a;
    return b;
}

int lis(int arr[], int n)
{
    int dp[1000], i, j, ans = 1;

    for(i = 0; i < n; i++)
        dp[i] = 1;

    for(i = 1; i < n; i++)
    {
        for(j = 0; j < i; j++)
        {
            if(arr[j] < arr[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    for(i = 0; i < n; i++)
        ans = max(ans, dp[i]);

    return ans;
}

int main()
{
    int n, i, arr[1000];

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d", lis(arr, n));

    return 0;
}
