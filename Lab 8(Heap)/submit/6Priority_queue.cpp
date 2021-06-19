#include<stdio.h>

class Priority_Queue{

private:
      int arr[100];
      int length;
    void MaxHeapify(int arr[],int i,int n)
{
	int l = 2*i;
	int r = 2*i+1;
	int largest =i;
	if (l <=n && arr[l] > arr[i])
    {
        largest = l;
    }
		else largest=i ;
	if (r <=n && arr[r] > arr[largest])
    {
        largest = r;
    }
	if (largest != i)
	{
	    int s=arr[i];
            arr[i]= arr[largest];
            arr[largest]=s;
		MaxHeapify(arr,largest,n);
	}
}
void convertMaxHeap(int n)
{

	for (int i = n/2; i >= 1; i--)
    {
        MaxHeapify(arr,i,n);
    }
}
public:
    Priority_Queue(){
        length=0;
    }
    void PrintQueue()
    {
	for (int i = 1; i <=length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
     }
    void Insert(int n)
    {
        arr[length+1]=n;
        length++;
        convertMaxHeap(length);
    }
    int Max()
    {
        if(length>0)
        {
            return arr[1];
        }
        return -99999;
    }
    int ExtractMax()
    {
        if(length>0)
        {
            int max=arr[1];
            arr[1]=arr[length];
            length--;
            MaxHeapify(arr,1,length);
            return max;
        }
        return -99999;
    }
    void IncreaseKey(int x,int k)
    {
        int i=1;
        while(i<=length)
        {
            if(arr[i]==x)
            {
                break;
            }
            i++;
        }
        if(i>length)
        {
            printf("Item not found\n");
            return;
        }
        else if(arr[i]>k)
        {
            printf("Key is smaller than element\n");
            return;
        }
        else
        {
            arr[i]=k;
            while(i>1 && arr[i] > arr[i/2]){
                int temp=arr[i/2];
                arr[i/2]=arr[i];
                arr[i]=temp;
                i=i/2;
            }
        }

    }
};

int main(){
    Priority_Queue PQ;
    int n,ch;
    while(1){
            printf("1.Insert  2.Maximum  3. Extract Max  4.Increase Key  5.Exit\n");
            scanf("%d",&ch);
        if(ch==1){
             printf("Insert element: ");
            scanf("%d",&n);
            PQ.Insert(n);
            PQ.PrintQueue();
        }
        else if(ch==2){
            printf("%d\n",PQ.Max());
        }
        else if(ch==3){
            printf("%d\n",PQ.ExtractMax());
            PQ.PrintQueue();
        }
        else if(ch==4){
            int p,n;
            printf("Element's key: ");
            scanf("%d",&p);
             printf("New value k: ");
             scanf("%d",&n);
            PQ.IncreaseKey(p,n);
            PQ.PrintQueue();
        }
        else if(ch==5){
            break;
        }
    }

}
