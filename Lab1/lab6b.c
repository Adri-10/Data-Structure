#include<stdio.h>
#include<time.h>
#include<math.h>
int isPrimeFlag(int n)
{
    int i,flag=1,count=0;
    for(i=2; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {

            flag=0;

            break;
        }
    }
    return flag;
}
int main()
{
    int n,i,count=0,isPrime;
    scanf("%d",&n);
    clock_t start=clock();
    for(i=2; i<=n; i++)
    {
        isPrime=isPrimeFlag(i);
        if(isPrime==1)
        {
            count++;
        }
    }
    printf("%d",count);
    clock_t end=clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %.5f",seconds);

}


