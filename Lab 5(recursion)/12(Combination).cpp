#include <stdio.h>
void combinations(int arr[],int check[],int low,int high,
                     int index, int j)
{
    if (index==j)
    {
        for (int k=0; k<j; k++)
            printf("%d ", check[k]);
        printf("\n");
        return;
    }
    for (int i=low; i<=high && high-i+1 >= j-index; i++)
    {
        check[index] = arr[i];
        combinations(arr, check, i+1, high, index+1,j);
    }
}
void print(int arr[],int n,int j)
{
    int check[j];
    combinations(arr,check,0,n-1,0,j);
}
int main()
{
    int n,arr[50],i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("\n");
    for(j=1;j<=n;j++)
    {
       print(arr,n,j);
    }
	return 0;
}

