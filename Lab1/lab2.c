#include<stdio.h>

int isPrimeFlag(int n)
{
    int i,flag=1,count=0;
    for(i=2; i<=n-1; i++)
    {
        if(n%i==0)
        {
            count++;
            flag=0;
            break;
        }
    }
    return flag;
}
int main()
{
    int n,isprime;
    scanf("%d",&n);
    isprime=isPrimeFlag(n);
    if(isprime==1)
    {
        printf("Prime");
    }
    else if(isprime==0)
    {
        printf("Not prime");

        int i,count=0;
        for(i=2; i<=n; i++)
        {
            if(n%i==0)
            {
                count++;
            }
        }
        printf("\n");
        printf("%d",count);
        printf("\n");
    }
}
