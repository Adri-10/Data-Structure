#include <stdio.h>

int dec_to_bin(int n)
{
    if (n==0)
        return 0;
    else
        return ((n%2)+10*dec_to_bin(n/2));
}
int main()
{
   int n;
   scanf("%d",&n);
   printf("%d",dec_to_bin(n));
}
