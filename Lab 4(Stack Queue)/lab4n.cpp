#include<stdio.h>
#include<iostream>
#define Stack_MAX_Size 300
#define QUEUE_MAX_Size 300
#define FAILURE_VALUE -99999
#define SUCCESS_VALUE 99999
class Stack{
private:
    int stack[Stack_MAX_Size];

public:
    int top;
    Stack()
    {
        top=0;
    }
    int push(int item)
    {
        if(top==Stack_MAX_Size) return FAILURE_VALUE;
        stack[top]=item;
        top++;
        return SUCCESS_VALUE;
    }
    int pop()
    {
        if(top==0) return FAILURE_VALUE;
        top--;
        return stack[top];
    }
    bool isEmpty()
    {
        if(top==0) return true;
        else return false;
    }
    bool isFull()
    {
        if(top==Stack_MAX_Size) return true;
        else return false;
    }
    int getLength()
    {
        return top;
    }
    char top_return()
    {
        return stack[top];
    }

};
class Queue{
private:
    int queue[QUEUE_MAX_Size];
    int front,rear,length;
public:
    Queue()
    {
        front=0;
        rear=0;
        length=0;
    }
    int enqueue(int item)
    {
        if(length==QUEUE_MAX_Size) return FAILURE_VALUE;
        queue[front]=item;
        front= (front+1)% QUEUE_MAX_Size;
        length++;
        return SUCCESS_VALUE;
    }
    int dequeue()
    {
        if(length==0) return FAILURE_VALUE;
        int item = queue[rear];
        rear= (rear+1)% QUEUE_MAX_Size;
        length--;
        return item;
    }
    bool isEmpty()
    {
        if(length==0) return true;
        else return false;
    }
    bool isFull()
    {
        if(length==QUEUE_MAX_Size) return true;
        else return false;
    }
    int getLength()
    {
        return length;
    }

};
void SumOfDigit(){
Stack st;
    int i,k,r;
    printf("Enter how many elements: ");
    scanf("%d",&k);
    int arr[k];
    for(i=0;i<k;i++){
        scanf("%d",&arr[i]);
        int value=arr[i];
        int sum=0;
        while(value!=0){
                r=value%10;
     value=value/10;
     sum=sum+r;
        }
        st.push(sum);
    }
    for(i=0;i<k;i++)
    {
        int p= st.pop();
      printf("%d ",p);
    }
}
int palindrome(char str[50]){
   int i,l=0;
   Stack st1,st2,st3;
    for(int i=0;str[i]!='\0';i++){
        st1.push(str[i]);
        st3.push(str[i]);
    }
    while(!st3.isEmpty()){
        st2.push(st3.pop());
    }
    bool flag=true;
    while(!st1.isEmpty() && !st2.isEmpty()){
        if(st1.pop()!=st2.pop()){
            flag=false;
            break;
        }
    }
    if(flag){
        printf("Palindrome\n");
    }
    else{
        printf("Not palindrome\n");
    }
}
int parenthesis(char str[50])
{
 Stack st;
    bool flag=true;
    int x,s=0;

    for(int i=0;str[i]!='\0';i++){
     if(str[i]=='('|| str[i]=='{' || str[i]=='[')
            {
               st.push(str[i]);
            }
         else if(str[i]==')')
        {
              if(st.pop()=='(')
                {
                }
               else
            {
                flag= false;
            break;
            }
        }
        else if(str[i]=='}')
        {
            if(st.pop()=='{') {}
            else
            {
                flag= false;
                break;
            }
        }
        else if(str[i]==']')
        {
            if(st.pop()=='[') {}
            else
            {
                flag= false;
                break;
            }
        }
        }
         if(st.isEmpty()==true && flag==true){
        printf("valid");
    }
    else{
        printf("Invalid");
    }
    }
void infix_postfix(){
    Stack st;
    int x;
    char str[100];
    printf("Enter a string: ");
    scanf("%s",&str);
    for(int i=0;str[i]!='\0';i++){
        if(str[i]!='(' && str[i]!=')' && str[i]!='{' && str[i]!='}' && str[i]!='[' && str[i]!=']' && str[i]!='+' && str[i]!='-' && str[i]!='*' && str[i]!='/'){
             printf("%c",str[i]);
        }
        else if(str[i]=='+' || str[i]=='-'){
            int x=st.pop();
            if(x!=0){
                st.push(x);
            }
            if(x=='*' || x=='/'){
                while(!st.isEmpty() && x!='('){
                    printf("%c",st.pop());
                    x=st.pop();
                    if(x!=0){
                        st.push(x);
                    }
                }
            }
            st.push(str[i]);
        }
        else if(str[i]=='('){
            st.push(str[i]);
        }
        else if(str[i]=='*' || str[i]=='/'){
            int t=st.pop();
            if(x!=0){
                st.push(x);
            }
            if(x=='*' || x=='/'){
                printf("%c",st.pop());
            }
            st.push(str[i]);
        }
        else if(str[i]==')'){
            int x=st.pop();
            if(x!=0){
                st.push(x);
            }
            while(x!='('){
                printf("%c",st.pop());
                x=st.pop();
                if(x!=0){
                    st.push(x);
                }
            }
            st.pop();
        }
    }
    while(!st.isEmpty()){
        printf("%c",st.pop());
    }
}
class Stqueue{
private:
    Stack st1,st2;
    int length;
public:
    Stqueue(){
        length=0;
    }
        int enqueue(int item){
        if(length == QUEUE_MAX_Size) return false;
        while(!st1.isEmpty()){
            st2.push(st1.pop());
        }
        st1.push(item);
        while(!st2.isEmpty()){
            st1.push(st2.pop());
        }
        length++ ;
        return true;
    }
    int dequeue(){
        if(length == 0) return FAILURE_VALUE;
        int item = st1.pop() ;
        length-- ;
        return item ;
    }
    int getLength(){
        return length;
    }
    int isEmpty(){
        if(length==0) return true;
        else return false;
    }
    int isFull(){
        if(length==QUEUE_MAX_Size) return true;
        else return false;
    }
};
void Reverse(){
    Stack st;
    Queue qu;
    int n;
    printf("How many elements: ");
    scanf("%d",&n);
    int num;
    printf("Elements are: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        qu.enqueue(num);
    }
    while(!qu.isEmpty()){
        st.push(qu.dequeue());
    }
    while(!st.isEmpty()){
        qu.enqueue(st.pop());
    }
    printf("After reversing: ");
    while(!qu.isEmpty()){
        printf("\n%d",qu.dequeue());
    }
}
void Reverse_k(){
    Queue qt,temp;
    Stack st;
    int n,k,num;
    printf("How many elements: ");
    scanf("%d",&n);;
    printf("Enter elements: \n");
    for(int i=0;i<n;i++){
        scanf("%d",&num);;
        temp.enqueue(num);
    }
    printf("Enter k: ");
    printf("After reversing till k ");
    scanf("%d",&k);;

    for(int i=0;i<k;i++){
        st.push(temp.dequeue());
    }
    while(!st.isEmpty()){
        qt.enqueue(st.pop());
    }
    while(!temp .isEmpty()){
        qt.enqueue(temp.dequeue());
    }
    while(!qt.isEmpty()){
        printf(" %d",qt.dequeue());
    }
}
int main(void){

while(1)
    {
        printf("\n1. Sum of digits. 2. Palindrome 3. Parenthesis \n");
        printf("4. Infix to Postfix. 5. Implementation of Queue. 6. Reverse\n");
        printf("7. Reverse by K 8. exit.\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            SumOfDigit();
        }
        else if(ch==2){
    char str[50];
     scanf("%s",&str);
        palindrome(str);
        }
    else if(ch==3){
    char str[50];
    printf("Enter an expression: ");
    scanf("%s",&str);
    parenthesis(str);
    }
    else if(ch==4){
        infix_postfix();
    }
    else if (ch==5){
        Stqueue stq;
        int ch2;
        while(1){
            printf("1.Enqueue. 2.Dequeue. 3.Is Empty. 4.Is Full 5.Get Length 6.Exit\n");
            scanf("%d",&ch2);
            if(ch2==1){
              int input;
              scanf("%d",&input);
              stq.enqueue(input);
            }
            else if(ch2==2){
                printf("%d\n",stq.dequeue());
            }
            else if(ch2==3){
                if(stq.isEmpty()){
                    printf("Empty Queue\n");
                }
                else{
                    printf("Not empty\n");
                }
            }
            else if(ch2==4){
                if(stq.isFull()){
                    printf("Full queue\n");
                }
                else{
                    printf("Not full\n");
                }
            }
            else if(ch2==5)
            printf("Length : %d\n",stq.getLength());
            else if(ch2==6)
            break;
        }
    }
    else if(ch==6){
        Reverse();
    }
    else if(ch==7){
        Reverse_k();
    }
    else if(ch==8)
        {
            break;
        }
}
}


