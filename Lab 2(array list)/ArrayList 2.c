#include<stdio.h>
#define MAX_SIZE 200

int list[MAX_SIZE];
int length;

void initializeList()
{
	length = 0 ;
}

int searchItem(int item)
{
    //Search for the item in list
    //Return the position of the item in list
    //If not found, return -1
    int c;
    for (c = 0; c <length ; c++)
  {
    if (list[c] == item)
    {
        return c;
         break;
    }
  }
  if (c == length)
  {
       return -1;
  }

}

int insertItemAt(int newitem, int position)
{
    //Insert new item in the array in specified position preserving the order of items
    //Increase length by 1
  list[position-1]=newitem;
    length++;
}

int insertItemFront(int newitem)
{
    //Insert new item at the front of the list using insertItemAt function
    int i;
    for(i=length-1;i>=0;i--)
    {
        list[i+1]=list[i];
    }
    list[0]=newitem;
    length++;

}

int insertItemRear(int newitem)
{
    //Insert new item at the rear or end of the list using insertItemAt function
    list[length]=newitem;
    length++;
}

int deleteItemAt(int position)
{
    //Delete the item at specified position preserving the order of items
    //Decrease length by 1
    int c;

   if (position==-1)
      printf("Item not found.\n");
   else
   {
      for (c = position; c <length; c++)
        list[c] = list[c+1];
        length=length-1;
   }

}

int deleteItem(int item)
{
    //Delete the item from list
    //Search for the position of item in list using searchItem function
    //Delete the item using deleteItemAt function
     int c,position;
   position=searchItem(item);
   deleteItemAt(position);

}

void printList()
{
    int i;
    for(i=0;i<length;i++){
        printf("%d ", list[i]);
    }
    printf("Current length: %d\n", length);
}

int main()
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item at position. 2. Insert new item at front. 3. Insert new item at rear\n");
        printf("4. Delete a specific item. 5. Print. 6.Exit.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            int pos;
            scanf("%d %d", &item,&pos);
            insertItemAt(item,pos);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d",&item);
            insertItemFront(item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            insertItemRear(item);
        }
        else if(ch==4)
        {
            int item;
            scanf("%d", &item);
            deleteItem(item);
        }
        else if(ch==5)
        {
            printList();
        }
        else if(ch==6)
        {
            break;
        }
    }

}
