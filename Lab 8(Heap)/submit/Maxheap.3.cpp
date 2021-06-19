#include<stdio.h>

void max_heapify(int arr[], int n, int i)
{
    int smallest=i;
    int l= 2*i;
    int r= 2*i+1;
    if (l<n && arr[l] < arr[smallest])
    {
        smallest = l;
    }
    if (r < n && arr[r] < arr[smallest])
    {
        smallest = r;
    }
    if (smallest!= i) {
            int s=arr[i];
            arr[i]= arr[smallest];
            arr[smallest]=s;
        max_heapify(arr, n, smallest);
    }
}
void heapSort(int arr[], int n)
{

    for (int i = n/2; i >= 1; i--)
    {
        max_heapify(arr, n, i);
    }
    for (int i=n; i>= 1; i--) {
        int t2=arr[1];
        arr[1]=arr[i];
        arr[i]=t2;
        max_heapify(arr, i, 1);
    }
}

void print_array(int arr[], int n, int k)
{
	heapSort(arr,n);
	for (int i = 1; i <= n; i++)
	{
	    printf("%d ", arr[i]);
	}
}
int main()
{

	int arr[50], i, n, k;
     printf("Enter number of elements: ");
     scanf("%d", &n);

     for(i=1; i<=n; i++)
     {
          printf("Enter elements : ");
          scanf("%d", &arr[i]);

     }
	print_array(arr,n,k);
}
