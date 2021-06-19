#include <stdio.h>
#include<string.h>
int length(char str[], int index)
{
    if (str[index]=='\0')
    {
        return 0;
    }
    return (1+length(str,index + 1));
}

int main()
{
    char str[50];
    gets(str);
    int count;
    count = length(str,0);
    printf("%d",count);
    return 0;
}
