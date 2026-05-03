#include<stdio.h>

double power(double base, int exp)
{
    if(exp == 0) return 1;
    return base * power(base, exp-1);
}

int main()
{
    double base;
    int exp;
    
    scanf("%lf %d", &base, &exp);
    printf("%.6lf", power(base, exp));
    
    return 0;
}
