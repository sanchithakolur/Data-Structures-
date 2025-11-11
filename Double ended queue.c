#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define size 10
int deq[size];
int front=-1,rear=-1;
void leftins(int);
void rightins(int);
void leftdel();
void rightdel();

void main()
{
    int c1,c2,val;
    while(1)
    {
    printf("Enter 1.Input Restricted\n 2.Output Restricted\n 3.Exit\n");
    scanf("%d",&c1);
    switch(c1)
    {
    case 1:
        printf("Enter 1.Input\n 2.Delete from left\n 3.Delete from right\n");
        scanf("%d",&c2);
        switch(c2)
        {
        case 1:
            {
            printf("Enter the element to insert");
            scanf("%d",&val);
            rightins(val);
            break;
            }
        case 2:
            leftdel();
            break;
        case 3:
            rightdel();
            break;
         break;
            }
        case 2:
             printf("Enter 1.Input from left\n 2.Input from right\n 3.Delete\n");
        scanf("%d",c2);
        switch(c2)
        {
        case 1:
            {
            printf("Enter the element to insert");
            scanf("%d",&val);
            leftins(val);
            break;
            }
        case 2:
             {
            printf("Enter the element to insert");
            scanf("%d",&val);
            rightins(val);
            break;
            }
        case 3:
            leftdel();
             break;
        break;
            }
        case 3:exit(0);
                }
    }

void leftins(int val)
{
    if(front==size/2)
        printf("Queue is full");
    else
    {
        rear++;
        deq[front]=val;
    }
}
void rightins(int val)
{
    if(rear==size/2)
        printf("Queue is full");
    else{
        rear--;
        deq[rear]=val;
    }
}
void leftdel()
{
    if(front==-1||rear==-1)
        printf("Queue is empty");
    else
        printf("delete element is %d",deq[front]);
        front++;
}
void rightdel()
{
    if(front == -1)
        printf("Queue is empty\n");
    else {
        printf("Deleted element is %d\n", deq[rear]);
        rear--;

    }
}

