#include<stdio.h>
#include<time.h>
int isPrimeCount(int n)
{
    int i,count=0;
    for(i=1; i<=n/2; i++)
    {
        if(n%i==0)
        {
            count++;
        }
    }
    if(count==1)
    {
        return 1;

    }
    else
    {
        return 0;
    }
}
int main()
{
    int n,i,count=0,isPrime;
    scanf("%d",&n);
    clock_t start=clock();
    for(i=2; i<=n; i++)

    {

        isPrime=isPrimeCount(i);
        if(isPrime==1)
        {


            count++;
        }
    }
    printf("Count of primes %d\n",count);
    clock_t end=clock();
    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %.5f",seconds);

}


