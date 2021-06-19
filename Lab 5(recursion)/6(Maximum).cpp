#include <stdio.h>
#include<stdlib.h>
int max(int x,int y)
{
    if(x>y)
    {
        return x;
    }
    else return y;
}
int maxArray(int arr[],int index, int n)
{
    if(index==n-1){
        return arr[index];
    }
    return max(arr[index],maxArray(arr,index+1,n));
}
int main()
{

    int n;
    scanf("%d", &n);
    int largest;
    int arr[50];
    int i;
    for (i = 0; i < n ; i++)
    {
        scanf("%d", &arr[i]);
    }
    if (n==0)
    {
        printf("Empty list\n");
    }
    else
        printf("\n%d",maxArray(arr,0,n));
}
