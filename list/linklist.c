#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* list;
};

void countelements(struct node* ptr)
{
    int count = 0;
    while(ptr != NULL)
    {
        count++;
        ptr = ptr->list;
    }
    printf("Total elements:%d",count);
}

int main()
{
    struct node* head = (struct node*)malloc(sizeof(struct node));
    head->data = 69;
    head->list = NULL;

    struct node* second = (struct node*)malloc(sizeof(struct node));
    second->data = 911;
    second->list = NULL;
    head->list = second;

    struct node* third = (struct node*)malloc(sizeof(struct node));
    third->data = 420;
    third->list = NULL;
    second->list = third;

    struct node* fourth = (struct node*)malloc(sizeof(struct node));
    fourth->data = 64;
    fourth->list = NULL;
    third->list = fourth;

    countelements(head);
}