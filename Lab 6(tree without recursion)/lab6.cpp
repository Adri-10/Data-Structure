#include<stdio.h>
#include<stdlib.h>
#define FALSE_VALUE 0
#define TRUE_VALUE 1

struct treeNode
{
    int item;
    struct treeNode * left; //points to left child
    struct treeNode * right; //points to right child
};

struct treeNode * root;
struct treeNode * current;


void initializeTree()
{
    root = 0;
}

/****** Complete the following functions using Loop ******/
struct treeNode * searchItem(struct treeNode * node, int item)
{
    // return the treeNode holding the item
    while(node!=0){
        if(item==node->item){
            return node;
        }
        if(item > node->item){
            node=node->right;
        }
        else{
            node=node->left;
        }
    }
    return 0;
};

int insertItem(struct treeNode * node, int item)
{
    //If success return TRUE_VALUE, else return FALSE_VALUE
    if(node==0)
    {
        struct treeNode *newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
        newNode->item=item;
        newNode->left=0;
        newNode->right=0;
        root=newNode;
        return TRUE_VALUE;
    }
    else{
        struct treeNode *current;
        while(node!=0){
            if(item < node->item){
                current=node;
                node=node->left;
            }
            else{
                current=node;
                node=node->right;
            }
        }
       struct treeNode *newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
        newNode->item=item;
        newNode->left=0;
        newNode->right=0;
        if(item < current->item){
            current->left=newNode;
        }
        else{
            current->right=newNode;
        }
        return TRUE_VALUE;
    }
}
void deleteItem(struct treeNode * node, int item)
{
    //If success return TRUE_VALUE, else return FALSE_VALUE
          struct treeNode *fn=searchItem(root,item);
          struct treeNode *current;
        if(fn->left==0 && fn->right==0){
            free(fn);
        }
        else if(fn->left==0){
                current=fn->right;
            while(current->left!=0){
                current=current->left;
            }
            fn->item=current->item;
            free(current);
            }
        else{
           current=fn->left;
            while(current->right!=0){
                current=current->right;
            }
            fn->item=current->item;
            free(current);
            //return TRUE_VALUE;
        }
}
int calcLevel(int item)
{
    //return level/depth of an item in the tree
     struct treeNode *node=root;
     int count=0;
     while(node!=0){
        if(item==node->item){
            return count;
        }
        if(item < node->item){
            node=node->left;
        }
            node=node->right;
        count++;
    }
    return FALSE_VALUE;
}

int getMinItem() // return the minimum item in the tree
{
    struct treeNode *temp=root;
    while(temp->left!=0){
        temp=temp->left;
    }
    return temp->item;

}
int getMaxItem() // return the maximum item in the tree
{
    struct treeNode * temp=root;
    while(temp->right!=0){
        temp=temp->right;
    }
    return temp->item;

}
int main(void)
{
    initializeTree();
    while(1)
    {
        printf("\n1. Insert item. 2. Delete item. 3. Search item. \n");
        printf("4. Print level of an item. \n");
        printf("5.Get Minimum  6.Get Maximum \n");
        printf("7.Exit\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(root, item);
        }
        else if(ch==2)
        {
            int item;
            scanf("%d", &item);
            deleteItem(root, item);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            struct treeNode * res = searchItem(root, item);
            if(res!=0) printf("Found.\n");
            else printf("Not found.\n");
        }
        else if(ch==4)
        {
            int item;
            scanf("%d", &item);
            int level = calcLevel(item);
            printf("Level of %d =\n%d\n", item, level);
        }
        else if(ch==5)
        {
            printf("\n%d\n",getMinItem());
        }
        else if(ch==6)
        {
            printf("\n%d\n",getMaxItem());
        }
        else if(ch==7)
        {
            break;
        }
    }

}


