#include<stdio.h>

int isPrimeCount(int n)
{
    int i,count=0;
    for(i=1; i<=n; i++)
    {
        if(n%i==0)
        {
            count++;
        }
    }

    if(count==2)
    {
        printf("Prime\n");

    }
    else
    {
        printf("Not prime\n");

    }
    printf("%d",count);
    printf("\n");
}

int main()
{
    int n;
    scanf("%d",&n);
    isPrimeCount(n);

}
