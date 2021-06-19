#include<stdio.h>

void MaxHeapify(int arr[], int i, int n)
{
	int l = 2*i;
	int r = 2*i+1;
	int largest =i;
	if (l < n && arr[l] > arr[i])
    {
        largest = l;
    }
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
	    int s=arr[i];
            arr[i]= arr[largest];
            arr[largest]=s;
		MaxHeapify(arr, largest, n);
	}
}
void convertMaxHeap(int arr[], int n)
{
	for (int i = n/2; i >= 1; --i)
    {
        MaxHeapify(arr, i, n);
    }

}
void convertMinHeap(int arr[], int n)
{
	for (int i = n/2; i >= 1; i--)
    {
        MaxHeapify(arr, i, n);
    }
	for (int i=n; i>= 1; i--) {
        int t2=arr[1];
        arr[1]=arr[i];
        arr[i]=t2;
        MaxHeapify(arr, 1,i);
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
      convertMaxHeap(arr, n);
      printf("\nMax Heap : ");
      printf("%d ", arr[1]);
    convertMinHeap(arr,n);
    printf("\nMin Heap : ");
    printf("%d ", arr[1]);
	return 0;
}

