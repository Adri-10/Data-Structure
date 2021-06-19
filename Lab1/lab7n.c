#include <stdio.h>
#include <math.h>
#include<time.h>
int main()
{
    int n,i,j;
    scanf("%d",&n);
 clock_t start=clock();
    int arr[n+1];
    for(i=2; i<=n; i++)
        arr[i]=i;
    i = 2;
    while ((i*i)<=n)
    {
        if (arr[i]!= 0)
        {
            for(j=2;j<=n; j++)
            {
                if (arr[i]*j > n)
                    break;
                else
                    arr[arr[i]*j]=0;
            }
        }
        i++;
    }
    int count=0;
for(i=2; i<=n; i++)
    {
        if (arr[i]!=0)
        {
           count++;
        }
    }

        printf("%d\n",count);
clock_t end=clock();
 float seconds = (float)(end - start) / CLOCKS_PER_SEC;
printf("Time taken: %.5f",seconds);

    return 0;
}
