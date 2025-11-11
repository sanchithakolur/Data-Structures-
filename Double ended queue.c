#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int deq[SIZE];
int front = -1, rear = -1;

void leftins(int);
void rightins(int);
void leftdel();
void rightdel();
void display();

int main()
{
    int c1, c2, val;

    while (1)
    {
        printf("\nEnter:\n1. Input Restricted\n2. Output Restricted\n 3. Display\n 4. Exit\n");
        scanf("%d", &c1);

        switch (c1)
        {
        case 1:
            printf("\n1. Insert (Right)\n2. Delete from Left\n3. Delete from Right\n");
            scanf("%d", &c2);

            switch (c2)
            {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &val);
                rightins(val);
                break;
            case 2:
                leftdel();
                break;
            case 3:
                rightdel();
                break;
            default:
                printf("Invalid choice\n");
            }
            break;

        case 2:
            printf("\n1. Insert from Left\n2. Insert from Right\n3. Delete (Left)\n ");
            scanf("%d", &c2);

            switch (c2)
            {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &val);
                leftins(val);
                break;
            case 2:
                printf("Enter the element to insert: ");
                scanf("%d", &val);
                rightins(val);
                break;
            case 3:
                leftdel();
                break;
            default:
                printf("Invalid choice\n");
            }
            break;

        case 3:
            display();
            break;
        case 4:
            exit(0);

        default:
            printf("Invalid main choice\n");
        }

        display();
    }
}

void rightins(int val)
{
    if (rear == SIZE - 1)
    {
        printf("Queue is full\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    deq[rear] = val;
}

void leftins(int val)
{
    if (front == 0)
    {
        printf("Cannot insert from left — Queue full on left side\n");
        return;
    }

    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        front--;
    }

    deq[front] = val;
}

void leftdel()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Deleted element: %d\n", deq[front]);

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void rightdel()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Deleted element: %d\n", deq[rear]);

    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

void display()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", deq[i]);
    printf("\n");
}
