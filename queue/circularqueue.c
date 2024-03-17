// modding by a certain value limits cycle to that value
#include<stdio.h>

int arr[5];
int front=-1;
int rear=-1;

int isfull()
{
    if((rear + 1) % 5 == front)
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
        rear = (rear+1) % 5;
        arr[rear] = value;
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
        n = arr[front];
        front = (front + 1) % 5;
        return n;
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
    if(front == -1 && rear == -1)
        printf("Queue is empty\n");
    else
    {
        int i;
        for(i = front;i != rear;i = (i + 1) % 5)
        {
             printf("%d\t",arr[i]);
        }
        printf("%d\n",arr[i]);
    }  
}

void main()
{
    dequeue();//underflow

    enqueue(6);
    enqueue(9);
    enqueue(11);
    enqueue(420);
    enqueue(69);

    printf("Front element:%d\n",peek());

    printf("Elements in queue:\n");
    displayqueue();

    printf("Element removed:%d\n",dequeue());

    enqueue(69);//queue overflows here in linear queue

    printf("Elements in queue:\n");
    displayqueue();
}