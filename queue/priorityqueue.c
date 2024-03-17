#include<stdio.h>
#define MAX_SIZE 5

int size = 0;
int data[MAX_SIZE];
int priority[MAX_SIZE];

void enqueue(int newdata, int newpriority)
{
    if(size == MAX_SIZE)
    {
        printf("Queue full!!");
        return;
    }

    int i = size;

    while(i > 0 && newpriority > priority[i-1])
    {
        data[i] = data[i-1];
        priority[i] = priority[i-1];
        i--;
    }

    data[i] = newdata;
    priority[i] = newpriority;
    size++;
}

int dequeue()
{
    if(size == 0)
    {
        printf("Queue empty cannot dequeue");
        return 1;
    }

    int dequeuedData = data[0];

    for(int i = 1;i < size;i++)
    {
        data[i-1] = data[i];
        priority[i-1] = priority[i];
    }
    size--;
    
    return dequeuedData;
}

void displayqueue()
{
    if(size == 0 )
    {
        printf("Queue is emtpy");
        return;
    }
    printf("Priority queue:\n");
    for(int i = 0;i < size;i++)
    {
        printf("%d , %d",data[i],priority[i]);
    }
    printf("\n");
}

int main()
{
    enqueue(10,2);
    enqueue(20,1);
    enqueue(30,1);

    displayqueue();

    printf("Dequeued element:%d",dequeue());
    displayqueue();
}