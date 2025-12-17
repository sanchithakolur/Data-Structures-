#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create();
void insert_begin();
void insert_position();
void insert_end();
void delete_begin();
void delete_position();
void delete_end();
void display();
int length();

int main()
{
    int choice;

    while (1)
    {
        printf("\n\n--- Singly Linked List Menu ---");
        printf("\n1. Create Linked List");
        printf("\n2. Insert at Beginning");
        printf("\n3. Insert at Any Position");
        printf("\n4. Insert at End");
        printf("\n5. Display List");
        printf("\n6. Delete First Node");
        printf("\n7. Delete Specified Position");
        printf("\n8. Delete Last Node");
        printf("\n9. Find Length of List");
        printf("\n10. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: create(); break;
        case 2: insert_begin(); break;
        case 3: insert_position(); break;
        case 4: insert_end(); break;
        case 5: display(); break;
        case 6: delete_begin(); break;
        case 7: delete_position(); break;
        case 8: delete_end(); break;
        case 9: printf("Length of list = %d\n", length()); break;
        case 10: exit(0);
        default: printf("Invalid choice!");
        }
    }
}


void create()
{
    struct node *newnode, *temp;
    int ch = 1;

    while (ch)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Add another node? (1/0): ");
        scanf("%d", &ch);
    }
}


void insert_begin()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
    display();
}

void insert_position()
{
    struct node *newnode, *temp;
    int pos, i = 1;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > length() + 1)
    {
        printf("Invalid position");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (pos == 1)
    {
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }

    newnode->next = temp->next;
    temp->next = newnode;
    display();
}

void insert_end()
{
    struct node *newnode, *temp;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = NULL;

    if (head == NULL)
    {
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    display();
}

void delete_begin()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
    display();
}

void delete_position()
{
    struct node *temp, *prev;
    int pos, i = 1;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > length())
    {
        printf("Invalid position");
        return;
    }

    if (pos == 1)
    {
        delete_begin();
        return;
    }

    temp = head;
    while (i < pos)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }

    prev->next = temp->next;
    free(temp);
}

void delete_end()
{
    struct node *temp, *prev;

    if (head == NULL)
    {
        printf("List is empty");
        return;
    }

    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

void display()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int length()
{
    int count = 0;
    struct node *temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
