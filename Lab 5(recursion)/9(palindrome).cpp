#include <stdio.h>
#include <math.h>
int reverse(int n)
{
    int digit=(int)log10(n);
      //printf("%d",digit);
    if(n==0)
    {
        return 0;
    }
    return ((n%10 * pow(10, digit))+reverse(n/10));
}
int Palindrome(int n)
{
    if(n==reverse(n))
    {
        return 1;
    }
    return 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    if(Palindrome(n)==1)
    {
        printf("Palindrome");
    }
    else
    {
        printf("Not palindrome");
    }
    return 0;
}
