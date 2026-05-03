#include<stdio.h>

#define INF 999999

int min(int a, int b)
{
    if(a < b) return a;
    return b;
}

int min_coins(int coins[], int n, int amount)
{
    int dp[1000], i, j;

    for(i = 0; i <= amount; i++)
        dp[i] = INF;

    dp[0] = 0;

    for(i = 1; i <= amount; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(coins[j] <= i)
                dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
        }
    }

    if(dp[amount] == INF) return -1;
    return dp[amount];
}

int main()
{
    int n, amount, i;
    int coins[100];

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &coins[i]);

    scanf("%d", &amount);

    printf("%d", min_coins(coins, n, amount));

    return 0;
}
