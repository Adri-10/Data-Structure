#include<stdio.h>
int ascending(int n) {
    int i,k;
    if (n==0)
    {
        return 0;
    }
    if(n==1)
    {
      printf("%d ",n);
      return n;
    }
    else
    {
     ascending(n-1);
    }
     printf("%d ",n);
}
int main() {
    int n;
    scanf("%d", &n);
    ascending(n);
    return 0;
}



