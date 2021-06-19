#include<stdio.h>
int gcd(int a,int b) {
    if (a==0)
    {
        return b;
    }
    if(b==0)
    {
      return a;
    }
    else
        return gcd(b,a%b);
}
int main() {
    int a,b;
    scanf("%d %d", &a, &b);
    printf("GCD is %d",gcd(a,b));
    return 0;
}
