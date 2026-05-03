#include<stdio.h>
#include<string.h>

int is_palindrome(char str[], int left, int right)
{
    if(left >= right) return 1;
    if(str[left] != str[right]) return 0;
    return is_palindrome(str, left+1, right-1);
}

int main()
{
    char str[1000];
    scanf("%s", str);
    
    int len = strlen(str);
    
    printf("%d", is_palindrome(str, 0, len-1));
    
    return 0;
}
