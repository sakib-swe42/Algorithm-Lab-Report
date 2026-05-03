#include<stdio.h>
#include<string.h>

int max(int a, int b)
{
    if(a > b) return a;
    return b;
}

int lcs(char s1[], char s2[], int m, int n)
{
    int dp[100][100];
    int i, j;

    for(i = 0; i <= m; i++)
    {
        for(j = 0; j <= n; j++)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[m][n];
}

int main()
{
    char s1[100], s2[100];

    scanf("%s", s1);
    scanf("%s", s2);

    printf("%d", lcs(s1, s2, strlen(s1), strlen(s2)));

    return 0;
}
