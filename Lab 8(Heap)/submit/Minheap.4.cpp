#include<stdio.h>
void minheapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i;
    int r = 2*i+1;

    if (l <n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        int s=arr[i];
            arr[i]= arr[largest];
            arr[largest]=s;
        minheapify(arr, n, largest);
    }
}

void convertMinHeap(int arr[], int n)
{

    for (int i = n/2; i >= 1; i--)
    {
        minheapify(arr, n, i);
    }
    for (int i=n; i>= 1; i--) {
        int t2=arr[1];
        arr[1]=arr[i];
        arr[i]=t2;
        minheapify(arr, i, 1);
    }
}
void printArray(int arr[], int n)
{
    convertMinHeap(arr,n);
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
	printArray(arr,n);
}
