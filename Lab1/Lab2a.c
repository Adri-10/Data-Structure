#include<stdio.h>

int isPrimeCount(int n)
{
    int i,flag=0;
    for(i=2;i<=n-1;i++)
    {
     if(n%i==0)
    {
        flag++;
        //printf("%d",i);

        //break;
    }
    }
printf("%d",flag);
printf("\n");
    if(flag==2)
    {
        printf("flag");
        printf("\n");

    }
    else
    {
        printf("\n");
        printf("Not prime");

        printf("\n");
    }
}
int main()
{
    int n;
     scanf("%d",&n);
    isPrimeCount(n);

}

