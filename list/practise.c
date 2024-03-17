#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};
struct node* head ;
void createlist (int arr[])
{
     head = (struct node*)malloc (sizeof(struct node));
    head->data = arr[0];
    head->link = NULL;
    struct node* temp = head;
    for(int i =1; i<5 ; i++)
    {
        struct node* newnode= (struct node*)malloc(sizeof(struct node));
        newnode->data = arr[i];
        newnode->link = NULL;
        temp->link= newnode;
        temp= newnode;
    }
}
int count()

{
  struct node* temp = head;
  int count =0;
  while(temp!= NULL)
  {
    count = count+1;
    temp = temp->link;
    
  }
  return count;
}

void insertatbeg(int n)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->link = NULL;
    struct node* temp= head;
    newnode->link= temp;
    head= newnode;
}

void insertatend(int n)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->link=NULL;
    struct node* temp= head;
    while(temp->link != NULL)
    {
        temp= temp->link;
    }
    temp->link= newnode;
    
    
}
void insertatpos(int n, int position)
{
 struct node* newnode =  head;  
 newnode->data = n;
newnode->link = NULL;
struct node* temp =  head;  
 for(int i =1; i<(position-1) ; i++)
 {
    temp= temp->link;
 }
 newnode->link = temp->link;
 temp->link = newnode;

}

// void deleteatbeg()
// {
//     if(head==NULL)
//     {
//         printf("there is nothing to delete");
//     }
//     struct node* temp = head;
//     head= head->link;
//     free(temp);


// }

// void deleteatend()
// {
//     struct node* temp = head;
    
    
//     while((temp->link)->link !=NULL)
//     {
//         temp= temp->link;
//     }
//     free(temp->link);
//     temp->link= NULL;

// }
void deleteatcertainpos(int pos)
{
    struct node *current= head;
    struct node *prev;

    for(int i=1; i<(pos);i++)
    {
        prev = current;
        current = current->link;
    }
    prev->link = current->link;
    free(current);
}
void display()
{
    struct node* temp= head;
    while(temp != NULL)
    {
        printf("%d \t", temp->data);
        temp = temp->link;
    }
}



int main()
{
    int arr[5];
    printf("insert the dats u want to insert");
    for(int i = 0; i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    createlist(arr);
    display();
    printf("%d\n",count());
    deleteatcertainpos(4);
    printf("%d\n",count());
    display();
    return 0;
}
