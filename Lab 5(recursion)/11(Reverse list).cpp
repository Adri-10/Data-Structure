#include<stdio.h>
#include<stdlib.h>
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999

struct listNode
{
    int item;
    struct listNode * next;
};
struct listNode* head=NULL;
struct listNode* tail=NULL;
void initializeList()
{
    head = 0;
    tail = 0;
}
int insertItem(int item)
{
    struct listNode * newNode ;
	newNode = (struct listNode*) malloc (sizeof(struct listNode)) ;
	newNode->item = item ;
	newNode->next = head;
	head = newNode ;
	if(tail==0)
    {
        tail=newNode;
    }
	return SUCCESS_VALUE ;
}

void printList()
{
    struct listNode *temp;
    temp = head;
    while(temp!=0)
    {
        printf("%d->",temp->item);
        temp=temp->next;
    }
    printf("\n");
}
void reverse(struct listNode *p){
if(p->next==NULL){
    head=p;
    return;
}
else
{
reverse(p->next);
}
struct listNode* q = p->next;
q->next=p;
p->next=NULL;
}

int main(void)
{
    initializeList();
    while(1)
    {
        printf("1. Insert new item. 2. Reverse. 3. Exit\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==2)
        {
            printf("List is : ");
            printList();
            printf("After reversing is : ");
            reverse(head);
            printList();
        }
        else if(ch==3)
        {
            break;
        }
    }
}
/*1
61
1
26
1
59
1
31
1
18
2
*/
