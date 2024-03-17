#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};

struct node* head = NULL;

void makelist(int arr[],int size)
{
    head = (struct node*)malloc(sizeof(struct node));
    head->data = arr[0];
    head->link = NULL;
    struct node* end = head;
    struct node* temp;
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
    struct node* temp = head;
    int count;
    while(temp != NULL)
    {
        count++;
        printf("%d\t",temp->data);
        temp = temp->link;
    }
}

void insertatstart()
{
    struct node* start = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter new data:");
    scanf("%d",&start->data);

    start->link = head;
    head = start;
}

void maxelement()
{
    if(head == NULL)
    {
        printf("Empty list");
        exit(0);
    }
    struct node* temp = head;
    int max = temp->data;
    while(temp != NULL)
    {
        if(temp->data>max)
            max = temp->data;
        temp = temp->link;
    }
    printf("\nMaximum:%d",max);
}


int main()
{
    int n;
    printf("Enter number of datas:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter datas:");
    for(int i = 0;i < n;i++)
        scanf("%d",&arr[i]);
    
    makelist(arr,n);
    countelements();
    insertatstart();
    countelements();
    maxelement();
}