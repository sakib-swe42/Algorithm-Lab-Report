#include<stdio.h>

int count_digits(int n)
{
    if(n == 0) return 1;
    if(n < 10) return 1;
    return 1 + count_digits(n/10);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", count_digits(n));
    return 0;
}
