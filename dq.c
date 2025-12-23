#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* prev;
    struct node* next;
};
struct node *head,*temp,*cnode,*newnode;
void display(struct node *head)
{
   temp=head;
   printf("Elements are:\n");
   while(temp!=NULL)
   {
       printf("%d",temp->data);
       temp=temp->next;
   }
}
struct node* createnode()
{
   cnode=(struct node*)malloc(sizeof(struct node));
   cnode->prev=cnode->next=NULL;
   return cnode;
}
void insertatfront(struct node* newnode)
{
    if (head == NULL) {
        head = newnode;
        return;
    }

    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}
void insertatrear(struct node* newnode)
{
    if (head == NULL) {
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}
void deleteatrear()
{
    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        head = NULL;

    free(temp);
}

void deleteatfront()
{
    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

int main()
{
    int c,v;
    while(1){
    printf("Enter the choice:\n 1.Insert at front\n 2.Insert at rear\n 3.Delete at rear\n 4.Delete at front\n 5.Display\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1:{
            newnode=createnode();
               printf("Enter the data");
               scanf("%d",&v);
               newnode->data=v;
               insertatfront(newnode);
               break;
        }
        case 2:{
         newnode=createnode();
               printf("Enter the data");
               scanf("%d",&v);
               newnode->data=v;
               insertatrear(newnode);
               break;
               }
        case 3:{
            deleteatrear();
            break;
        }
        case 4:{
            deleteatfront();
            break;
        }
        case 5:
            display(head);
            break;
    }
}
    return 0;
}
