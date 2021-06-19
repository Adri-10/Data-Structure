#include<stdio.h>
#include<string.h>
int swap(char *a, char *b)
{
  char t = *a;
    *a=*b;
    *b=t;
}
void reverse(char str[],int low,int high)
{
    if(low==high)
    {
        return;
    }
    else if(low<high)
    {
        swap(&str[low],&str[high]);
         reverse(str,low+1,high-1);
    }
}
int main()
{
    char str[50];
     gets(str);
     int n=strlen(str);
    reverse(str,0,n-1);
    printf("%s",str);
    return 0;
}
