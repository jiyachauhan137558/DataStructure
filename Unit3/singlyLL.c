//Jiya Chauhan
//92500588005
//singly linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *start = NULL;

void create_ll();
void display();
void insert_beg();
void insert_end();
void insert_before();
void insert_after();
void delete_beg();
void delete_end();
void delete_node();

int main()
{
    int option;

    do
    {
        printf("\n\n***** MAIN MENU *****");
        printf("\n1: Create a list");
        printf("\n2: Display the list");
        printf("\n3: Add a node at the beginning");
        printf("\n4: Add a node at the end");
        printf("\n5: Add a node before a given node");
        printf("\n6: Add a node after a given node");
        printf("\n7: Delete a node from the beginning");
        printf("\n8: Delete a node from the end");
        printf("\n9: Delete the given node");
        printf("\n10: Exit");

        printf("\n\nEnter your option: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                create_ll();
                break;

            case 2:
                display();
                break;

            case 3:
                insert_beg();
                break;

            case 4:
                insert_end();
                break;

            case 5:
                insert_before();
                break;

            case 6:
                insert_after();
                break;

            case 7:
                delete_beg();
                break;

            case 8:
                delete_end();
                break;

            case 9:
                delete_node();
                break;

            case 10:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid option!");
        }

    } while(option != 10);

    return 0;
}

void create_ll()
{
    struct node *new_node, *ptr;
    int num;

    printf("\nEnter -1 to end");

    printf("\nEnter the data: ");
    scanf("%d", &num);

    while(num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));

        if(new_node == NULL)
        {
            printf("\nMemory allocation failed!");
            return;
        }

        new_node->data = num;
        new_node->next = NULL;

        if(start == NULL)
        {
            start = new_node;
        }
        else
        {
            ptr = start;

            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }

            ptr->next = new_node;
        }

        printf("\nEnter the data: ");
        scanf("%d", &num);
    }

    printf("\nLinked list created.");
}

void display()
{
    struct node *ptr;

    if(start == NULL)
    {
        printf("\nList is empty.");
        return;
    }

    ptr = start;

    printf("\nLinked list: ");

    while(ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }

    printf("NULL");
}

void insert_beg()
{
    struct node *new_node;
    int num;

    printf("\nEnter the data: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));

    if(new_node == NULL)
    {
        printf("\nMemory allocation failed!");
        return;
    }

    new_node->data = num;
    new_node->next = start;

    start = new_node;

    printf("\nNode inserted at beginning.");
}

void insert_end()
{
    struct node *new_node, *ptr;
    int num;

    printf("\nEnter the data: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));

    if(new_node == NULL)
    {
        printf("\nMemory allocation failed!");
        return;
    }

    new_node->data = num;
    new_node->next = NULL;

    if(start == NULL)
    {
        start = new_node;
    }
    else
    {
        ptr = start;

        while(ptr->next != NULL)
        {
            ptr = ptr->next;
        }

        ptr->next = new_node;
    }

    printf("\nNode inserted at end.");
}

void insert_before()
{
    struct node *new_node, *ptr, *preptr;
    int num, val;

    if(start == NULL)
    {
        printf("\nList is empty.");
        return;
    }

    printf("\nEnter the data: ");
    scanf("%d", &num);

    printf("\nEnter the value before which the data has to be inserted: ");
    scanf("%d", &val);

    new_node = (struct node *)malloc(sizeof(struct node));

    if(new_node == NULL)
    {
        printf("\nMemory allocation failed!");
        return;
    }

    new_node->data = num;

    if(start->data == val)
    {
        new_node->next = start;
        start = new_node;

        printf("\nNode inserted.");
        return;
    }

    ptr = start;

    while(ptr != NULL && ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    if(ptr == NULL)
    {
        printf("\nValue not found.");
        free(new_node);
        return;
    }

    preptr->next = new_node;
    new_node->next = ptr;

    printf("\nNode inserted.");
}

void insert_after()
{
    struct node *new_node, *ptr;
    int num, val;

    if(start == NULL)
    {
        printf("\nList is empty.");
        return;
    }

    printf("\nEnter the data: ");
    scanf("%d", &num);

    printf("\nEnter the value after which the data has to be inserted: ");
    scanf("%d", &val);

    ptr = start;

    while(ptr != NULL && ptr->data != val)
    {
        ptr = ptr->next;
    }

    if(ptr == NULL)
    {
        printf("\nValue not found.");
        return;
    }

    new_node = (struct node *)malloc(sizeof(struct node));

    if(new_node == NULL)
    {
        printf("\nMemory allocation failed!");
        return;
    }

    new_node->data = num;
    new_node->next = ptr->next;

    ptr->next = new_node;

    printf("\nNode inserted.");
}

void delete_beg()
{
    struct node *ptr;

    if(start == NULL)
    {
        printf("\nList is empty.");
        return;
    }

    ptr = start;
    start = start->next;

    free(ptr);

    printf("\nNode deleted from beginning.");
}

void delete_end()
{
    struct node *ptr, *preptr;

    if(start == NULL)
    {
        printf("\nList is empty.");
        return;
    }

    /* Only one node */
    if(start->next == NULL)
    {
        free(start);
        start = NULL;

        printf("\nNode deleted from end.");
        return;
    }

    ptr = start;

    while(ptr->next != NULL)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    preptr->next = NULL;

    free(ptr);

    printf("\nNode deleted from end.");
}

void delete_node()
{
    struct node *ptr, *preptr;
    int val;

    if(start == NULL)
    {
        printf("\nList is empty.");
        return;
    }

    printf("\nEnter the value of the node which has to be deleted: ");
    scanf("%d", &val);

    ptr = start;

    /* If first node contains the value */
    if(ptr->data == val)
    {
        delete_beg();
        return;
    }

    preptr = ptr;
    ptr = ptr->next;

    while(ptr != NULL && ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }

    if(ptr == NULL)
    {
        printf("\nValue not found.");
        return;
    }

    preptr->next = ptr->next;

    free(ptr);

    printf("\nNode deleted.");
}

