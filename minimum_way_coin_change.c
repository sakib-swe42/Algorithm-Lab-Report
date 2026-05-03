#include<stdio.h>

int count_ways(int coins[], int n, int amount)
{
    int dp[1000] = {0};
    int i, j;

    dp[0] = 1;

    for(i = 0; i < n; i++)
    {
        for(j = coins[i]; j <= amount; j++)
        {
            dp[j] += dp[j - coins[i]];
        }
    }

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

    printf("%d", count_ways(coins, n, amount));

    return 0;
}
