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

    struct node* temp;
    struct node* end = head;

    for(int i = 1;i<size;i++)
    {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = arr[i];
        temp->link = NULL;

        end->link = temp;
        end = temp;
    }
}


int countitems()
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = head;
    int count = 0;

    while(temp != NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}

void displayitems()
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp = head;

    while(temp != NULL)
    {
        printf("%d\t",temp->data);

        temp = temp->link;
    }
}

void insertstart()
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    printf("\nEnter new data at start:");
    scanf("%d",&temp->data);

    temp->link = head;
    head = temp;
}

void insertatend()
{
    struct node* temp;
    struct node* newdata = (struct node*)malloc(sizeof(struct node));

    temp = head;

    printf("\nEnter new data at end:");
    scanf("%d",&newdata->data);
    newdata->link = NULL;

    while(temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = newdata;
}

void removestart()
{
    if(head == NULL)
    {
        printf("\nEmpty list");
        exit(0);
    }
    else
    {
        struct node* temp;
        // temp = (struct node*)malloc(sizeof(struct node));
        temp =  head;
        head = head->link;
        free(temp);
    }
}

void removeend()
{
    struct node* temp = head;
    struct node* prev = (struct node*)malloc(sizeof(struct node));

    if(temp->link == NULL)
    {
        free(temp);
        head->link = NULL;
    }

    while(temp->link != NULL)
    {
        prev = temp;
        temp = temp->link;
    }
    free(temp);
    prev->link = NULL;
}

void insertatspeific()
{
    int data;
    int position;
    printf("\nEnter position:");
    scanf("%d",&position);
    printf("Enter data:");
    scanf("%d",&data);
    if(position == 1)
    {
        insertstart();
        return;
    }
    if(position == countitems()+1)
    {
        insertatend();
        return;
    }
    if(position > countitems()+1)
    {
        printf("Error");
        exit(0);
    }
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->link = NULL;

    struct node* temp = NULL;
    temp = head;
    
    for(int i = 1;i < position - 1;i++)
    {
        temp = temp->link;
    }
    newnode->link = temp->link;
    temp->link = newnode;
}

void removefromspecific()
{
    int position;
    printf("\nEnter position:");
    scanf("%d",&position);
    if(position == 1)
    {
        removestart();
        return;
    }
    if(position == countitems())
    {
        removeend();
        return;
    }
    if(position > countitems())
    {
        printf("Error");
        exit(0);
    }

    struct node* current = head;
    struct node* prev =  NULL;

    for(int i = 1;i<position;i++)
    {
        prev = current;
        current = current->link;
    }
    prev->link = current->link;
    free(current);
}

int main()
{
    int n;
    printf("Enter number of data:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter datas:");    
    for(int i = 0;i<n;i++)
        scanf("%d",&arr[i]);
    
    makelist(arr,n);
    displayitems();
    printf("\nNo of elements:%d",countitems());
    insertstart();
    displayitems();
    printf("\nNo of elements:%d",countitems());
    insertatend();
    displayitems();
    printf("\nNo of elements:%d",countitems());
    removestart();
    printf("\nAfter removing first element:\n");
    displayitems();
    printf("\nNo of elements:%d",countitems());
    removeend();
    printf("\nAfter removing last element:\n");
    displayitems();
    printf("\nNo of elements:%d",countitems());
    insertatspeific();
    displayitems();
    printf("\nNo of elements:%d",countitems());
    removefromspecific();
    displayitems();
    printf("\nNo of elements:%d",countitems());
}