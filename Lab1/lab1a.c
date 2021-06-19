#include<stdio.h>>

int PrimeCount(int n)
{
    for (int i=2;i<n-1;i++)
        {
            if (n%i==0)
                printf("Not prime");
            printf("%d ",i);
        }

}
int main()
{
    int n,isprime;
     scanf("%d",&n);
    PrimeCount(n);
    return 0;
}
