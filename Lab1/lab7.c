#include<stdio.h>
#include<time.h>
#include<math.h>
int main()
{
    int i,n,p,k;
    int arr[10000];
    printf("Enter the array size: ");
    scanf("%d",&n);
    for(i=2; i<=n; i++)
    {
        scanf("%d",&arr[i]);
    }
    p=2;
    for(i=p^2; i<=n; i++)
    {
        while(k<=n)
        {
            k=p*(p+i);
        }
        i++;
    }
    printf("%d",k);
}
