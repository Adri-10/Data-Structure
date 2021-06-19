#include<stdio.h>
int descending(int n) {
    if (n==0)
    {
        return 0;
    }
    else
        printf("%d ",n);
        return descending(n-1);

}
int main() {
    int n;
    scanf("%d", &n);
    descending(n);
    return 0;
}


