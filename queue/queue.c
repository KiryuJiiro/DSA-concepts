#include<stdio.h>

int arr[5];
int front=-1;
int rear=-1;

int isfull()
{
    if(rear==(4))
        return 1;
    else
        return 0;
}

int isempty()
{
    if(rear == -1 && front == -1)
        return 1;
    else
        return 0;
}

void enqueue(int value)
{
    if(isfull())
    {
        printf("Queue overflow\n");
    }
    else if(rear == -1 && front == -1)
    {
        rear = 0;
        front = 0;
        arr[rear] = value;
    }
    else
        arr[++rear] = value;
}

int dequeue()
{
    int n;
    if(isempty())
    {
        printf("Queue underflow\n");
    }
    else if(rear == front)
    {
        n=arr[front];
        rear = -1;
        front = -1;
        return n;
    }
    else 
    {
        return arr[front++];
    }
}

int peek()
{
    if(isempty())
    {
        printf("Queue underflow\n");
    }
    else
        return arr[front];
}

void displayqueue()
{
    int i = 5;
    for(i = front;i <= rear;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void main()
{
    dequeue();

    enqueue(6);
    enqueue(9);
    enqueue(11);
    enqueue(420);
    enqueue(64);

    printf("Front element:%d\n",peek());
    printf("Elements in queue:\n");
    displayqueue();
    printf("Element removed:%d\n",dequeue());
    printf("Element removed:%d\n",dequeue());
    printf("Element removed:%d\n",dequeue());
    displayqueue();

}