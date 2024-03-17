#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};

struct node* head = NULL;

void createlist(int arr[],int size)
{
    head = (struct node*)malloc(sizeof(struct node));
    head->data = arr[0];
    head->link = NULL;  

    struct node* temp;
    struct node* end = head;

    for(int i = 1;i < size;i++)
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->link = NULL;

        end->link = temp;
        end = temp;
    }
}

void countelements()
{
    struct node* ptr = head;
    int count=0;
    while(ptr != NULL)
    {
        count++;
        printf("%d\t",ptr->data);
        ptr = ptr->link;
    }
    printf("\nNumber of elements:%d",count);
}

void maxelement()
{
    struct node* temp = head;
    if(head == NULL)
    {
        printf("Empty list");
        exit(0);
    }
    else
    {
        int max;
        max = temp->data;
        while(temp != NULL)
        {
            if(max < temp->data)
                max = temp->data;
            temp = temp->link;
        }
        printf("\nMax value:%d",max);
    }
}
void minelement()
{
    struct node* temp = head;
    if(head == NULL)
    {
        printf("Empty list");
        exit(0);
    }
    else
    {
        int max;
        max = temp->data;
        while(temp != NULL)
        {
            if(max > temp->data)
                max = temp->data;
            temp = temp->link;
        }
        printf("\nMin value:%d",max);
    }
}

void insertatstart()
{
    struct node* start = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter data:");
    scanf("%d",&start->data);
    start->link = head;
    head = start;
}




int main()
{
    int arr[5] = {1,2,3,4,5};
    createlist(arr,5);
    countelements();
    insertatstart();
    countelements();
    maxelement();
    minelement();
}
