#include<stdio.h>

int max(int a, int b)
{
    if(a > b) return a;
    return b;
}

int knapsack_01(int w[], int v[], int n, int W)
{
    int dp[100][100], i, j;

    for(i = 0; i <= n; i++)
    {
        for(j = 0; j <= W; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(w[i-1] <= j)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i-1]] + v[i-1]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][W];
}

int main()
{
    int n, W, i;
    int w[100], v[100];

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &w[i]);

    for(i = 0; i < n; i++)
        scanf("%d", &v[i]);

    scanf("%d", &W);

    printf("%d", knapsack_01(w, v, n, W));

    return 0;
}
