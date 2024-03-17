#include<stdio.h>
#include<stdlib.h>
#define n 5

int list[n];
int top=-1;

int isempty()
{
    return (top == -1);
}

int isfull()
{
    return(top == (n-1));
}

void push(int value)
{
    if(isfull())
    {
        printf("Stack overflow\n");
        exit(1);
    }
    list[++top]=value;
}

int peek()
{
    if(isempty())
    {
        printf("Stack is empty\n");\
        exit(1);
    }
    return list[top];
}

int pop()
{
    if(isempty())
    {
        printf("stack underflow\n");
        exit(1);
    }
    return list[top--];
}

int main()
{
    push(69);
    push(420);
    push(911);

    printf("top value is: %d\n",peek());
    printf("Popped value: %d\n",pop());
    printf("Popped value: %d\n",pop());
    printf("top value is: %d\n",peek());
    return 0;
}