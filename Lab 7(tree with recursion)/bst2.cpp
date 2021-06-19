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


void initializeTree()
{
    root = 0;
}


struct treeNode * searchItem(struct treeNode * node, int item)
{
    // Solve using recursion
    if(node==0 || node->item==item)
    {
        return node;
    }
    else
    {
        if(item < node->item)
        {
            searchItem(node->left,item);
        }
        searchItem(node->right,item);
    }
};

struct treeNode * searchPrev(struct treeNode * node,int item)
{
    // Return the parent node of the item using recursion
     if(node!=0)
    {
       if(node->left!=0 && node->left->item==item)
       {
           return node;
       }
       else if(node->right!=0 && node->right->item==item)
       {
           return node;
       }
       else
       {
          if(item < node->item)
           {
               searchPrev(node->left,item);
           }
           else if(item > node->item)
           {
              searchPrev(node->right,item);
           }
           else if(item==root->item)
           {
               return 0;
           }
       }
        }
        return 0;
    };

struct treeNode * makeTreeNode(int item)
{
    struct treeNode * node ;
    node = (struct treeNode *)malloc(sizeof(struct treeNode));
    node->item = item;
    node->left = 0;
    node->right = 0;
    return node;
};

struct treeNode * insertItem(struct treeNode * node, int item)
{
    // Insert item in the tree using recursion
    if(node!=0){
       if(item < node->item){
          if(node->left==0){
            struct treeNode *newNode=makeTreeNode(item);
            node->left=newNode;
            return newNode;
        }
            insertItem(node->left,item);
    }
    else if(item > node->item){
        if(node->right==0){
            struct treeNode *newNode=makeTreeNode(item);
            node->right=newNode;
            return newNode;
        }
            insertItem(node->right,item);
    }
}
else
{
struct treeNode *newNode=makeTreeNode(item);
        root=newNode;
        return newNode;
    }
};

int calcNodeHeight(struct treeNode * node)
{
    // return height (maximum distance from node to leaf + 1) using recursion
    if (node==NULL)
       return 0;
   else
   {
       int l=calcNodeHeight(node->left);
       int r=calcNodeHeight(node->right);
       if (l>r)
           return(l+1);
       else return(r+1);
   }
}


int calcHeight(int item) //return height of an item in the tree
{
    // return height of an item using calcNodeHeight function
    struct treeNode* node=searchItem(root,item);
    return calcNodeHeight(node);
}

int getSize(struct treeNode * node)
{
    // return size of the tree with node(argument) as root using recursion
    if(node==0){
        return 0;
    }
        return 1+getSize(node->left)+getSize(node->right);
}

int calcNodeDepth(struct treeNode * node,struct treeNode *tmp,int depth)
{
    //calculate depth of level of a node using recursion
    if(node==tmp){
        return depth;
    }
    else{
        if(node->item < tmp->item){
            calcNodeDepth(node,tmp->left,depth+1);
        }
        else{
            calcNodeDepth(node,tmp->right,depth+1);
        }
    }

}

int findLCA(struct treeNode *node,int item1,int item2)
{
    //Find lowest common ancestors of item1 and item2 using recursion
     if(item1 <= node->item && node->item  <= item2){
        return node->item;
    }
    else if(item1 > node->item){
        findLCA(node->right,item1,item2);
    }
    else if(item2 < node->item){
        findLCA(node->left,item1,item2);
    }
}

int calcDepth(int item)
{
    //Return depth or level of an item using calcNodeDepth function
     struct treeNode * node=searchItem(root,item);
    if(node!=0){
        return calcNodeDepth(node,root,0);
    }
        return FALSE_VALUE;
}


int deleteItem(struct treeNode * node, int item)
{
    //write your code from previous assignment here, you do not need to implement using recursion
      struct treeNode *sn=searchItem(node,item);
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
        }
}

int getMinItem(struct treeNode * node)
{
    //return the minimum item in the tree using recursion
    if(node->left==0)
    {
        return node->item;
    }
    getMinItem(node->left);
}

int getMaxItem(struct treeNode * node)
{
    //return the maximum item in the tree using recursion
    if(node->right==0){
        return node->item;
    }
        getMaxItem(node->right);
}

int rangeSearch(struct treeNode * node, int leftBound, int rightBound)
{
    //returns number of items in the range of leftBound and rightBound using recursion
    if(node==0)
    {
        return 0;
    }
    if(leftBound <= node->item && node->item <= rightBound)
    {
        return 1+rangeSearch(node->left,leftBound,rightBound)+rangeSearch(node->right,leftBound,rightBound);
    }
    else if(leftBound > node->item)
    {
        rangeSearch(node->right,leftBound,rightBound);
    }
    else if(rightBound < node->item)
    {
        rangeSearch(node->left,leftBound,rightBound);
    }

}

int findInOrderSuccessor(int item)
{
    //return In order successor of the item in the tree (You need not use recursion)
    struct treeNode *sn=searchItem(root,item);
    struct treeNode *tmp,*prev;
    if(sn->right!=0)
    {
        tmp=sn->right;
        while(tmp->left!=0)
        {
            tmp=tmp->left;
        }
        return tmp->item;
    }
    else
    {
        tmp=sn;
        prev=searchPrev(root,tmp->item);
        while(tmp->item > prev->item && prev!=0)
        {
            tmp=prev;
            prev=searchPrev(root,prev->item);
        }
        if(prev!=0)
        {
            return prev->item;
        }

            return FALSE_VALUE;
    }
}

void printInOrder(struct treeNode * node, int height)
{
    if(node==0) return;

    //print left sub-tree
    printInOrder(node->left, height-1);

    //print item
    for(int i=0;i<height;i++)printf("   ");
    printf("%03d\n",node->item);

    //print right sub-tree
    printInOrder(node->right, height-1);
}

void printPreOrder(struct treeNode * node, int height)
{
    //Write your code using recursion to print the tree in pre-order
    if(node==0) return;
    for(int i=0;i<height;i++)printf("   ");
    printf("%03d\n",node->item);
    printPreOrder(node->left, height-1);
    printPreOrder(node->right, height-1);
}

void printPostOrder(struct treeNode * node, int height)
{
    //Write your code using recursion to print the tree in post-order
    if(node==0) return;
    printPostOrder(node->left, height-1);
    printPostOrder(node->right, height-1);
    for(int i=0;i<height;i++)printf("   ");
    printf("%03d\n",node->item);

}

int main(void)
{
    initializeTree();
    while(1)
    {
        printf("1. Insert item. 2. Parent node. 3. Search item. \n");
        printf("4. Print height of tree. 5. Print height of an item. \n");
        printf(" 6. PrintInOrder. 7. PrintPreOrder 8. PrintPostOrder\n");
        printf(" 9. Print depth of an item. 10.Print size 11.Get Minimum 12.Get Maximum \n");
        printf("13.Delete item 14.RangeSearch 15.findLCA  16.findInorderSuccessor 17.Exit\n");

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
            struct treeNode * res = searchPrev(root, item);
            if(res==0) printf("No parent found.\n");
            else printf("%d\n",res->item);
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
            int height = calcNodeHeight(root);
            printf("Height of tree = %d\n", height);
        }
        else if(ch==5)
        {
            int item;
            scanf("%d", &item);
            int height = calcHeight(item);
            printf("Height of %d = %d\n", item, height);
        }
        else if(ch==6)
        {
            int h = calcNodeHeight(root);
            printf("\n--------------------------------\n");
            printInOrder(root, h);
            printf("--------------------------------\n");
        }
        else if(ch==7)
        {
            int h = calcNodeHeight(root);
            printf("\n--------------------------------\n");
            printPreOrder(root, h);
            printf("--------------------------------\n");
        }
        else if(ch==8)
        {
            int h = calcNodeHeight(root);
            printf("\n--------------------------------\n");
            printPostOrder(root, h);
            printf("--------------------------------\n");
        }
        else if(ch==9)
        {
            int item;
            scanf("%d", &item);
            int depth = calcDepth(item);
            printf("Depth of %d = %d\n", item, depth);
        }
        else if(ch==10)
        {
            printf("Size of tree is %d\n",getSize(root));
        }
        else if(ch==11)
        {
            printf("%d\n",getMinItem(root));
        }
        else if(ch==12)
        {
            printf("%d\n",getMaxItem(root));
        }
        else if(ch==13)
        {
            int item;
            scanf("%d",&item);
            int func = deleteItem(root,item);
            if(func==-1) printf("Item not present\n");
            else printf("Deleted item: %d\n",func);
        }
        else if(ch==14)
        {
            int leftBound,rightBound;
            scanf("%d %d",&leftBound,&rightBound);
            int num = rangeSearch(root,leftBound,rightBound);
            printf("%d\n",num);
        }
        else if(ch==15)
        {
            int item1,item2;
            scanf("%d %d",&item1,&item2);
            printf("LCA is: %d\n",findLCA(root,item1,item2));
        }
        else if(ch==16)
        {
            int item;
            scanf("%d",&item);
            printf("In order successor of %d is: %d\n",item,findInOrderSuccessor(item));
        }
        else if(ch==17)
        {
            break;
        }
    }

}
