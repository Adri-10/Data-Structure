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
};

struct treeNode * searchPrev(struct treeNode * node,int item)
{
    // Return the parent node of the item using recursion
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
}



int calcNodeHeight(struct treeNode * node)
{
    // return height (maximum distance from node to leaf + 1) using recursion
}


int calcHeight(int item) //return height of an item in the tree
{
    // return height of an item using calcNodeHeight function
}

int getSize(struct treeNode * node)
{
    // return size of the tree with node(argument) as root using recursion
}

int calcNodeDepth(struct treeNode * node)
{
    //calculate depth of level of a node using recursion
}

int findLCA(struct treeNode *node,int item1,int item2)
{
    //Find lowest common ancestors of item1 and item2 using recursion
}

int calcDepth(int item)
{
    //Return depth or level of an item using calcNodeDepth function
}


int deleteItem(struct treeNode * node, int item)
{
    //write your code from previous assignment here, you do not need to implement using recursion
}

int getMinItem()
{
    //return the minimum item in the tree using recursion
}

int getMaxItem()
{
    //return the maximum item in the tree using recursion
}

int rangeSearch(struct treeNode * node, int leftBound, int rightBound)
{
    //returns number of items in the range of leftBound and rightBound using recursion
}

int findInOrderSuccessor(int item)
{
    //return In order successor of the item in the tree (You need not use recursion)
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
}

void printPostOrder(struct treeNode * node, int height)
{
    //Write your code using recursion to print the tree in post-order
}

int main(void)
{
    initializeTree();
    while(1)
    {
        printf("1. Insert item. 2. Delete item. 3. Search item. \n");
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
            printf("%d\n",getMinItem());
        }
        else if(ch==12)
        {
            printf("%d\n",getMaxItem());
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
