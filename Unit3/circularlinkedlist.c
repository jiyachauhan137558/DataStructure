//92500588005
//Jiya Chauhan
//circular linkedlist

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
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
        printf("\n\n***** CIRCULAR DOUBLY LINKED LIST MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Insert at the beginning");
        printf("\n 4: Insert at the end");
        printf("\n 5: Insert before a given node");
        printf("\n 6: Insert after a given node");
        printf("\n 7: Delete from the beginning");
        printf("\n 8: Delete from the end");
        printf("\n 9: Delete a specific node");
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
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid option! Please try again.");
        }

    } while(option != 10);

    return 0;
}

// 1. Create List
void create_ll()
{
    struct node *new_node, *last;
    int num;

    printf("\nEnter -1 to end input.");
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

        if(start == NULL)
        {
            start = new_node;
            new_node->next = start;
            new_node->prev = start;
        }
        else
        {
            last = start->prev;
            last->next = new_node;
            new_node->prev = last;
            new_node->next = start;
            start->prev = new_node;
        }

        printf("Enter the data: ");
        scanf("%d", &num);
    }

    printf("\nCircular doubly linked list created successfully.");
}

// 2. Display List
void display()
{
    struct node *ptr;

    if(start == NULL)
    {
        printf("\nList is empty.");
        return;
    }

    ptr = start;
    printf("\nCircular doubly linked list: ");
    do
    {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    } while(ptr != start);

    printf("(HEAD)");
}

// 3. Insert at Beginning
void insert_beg()
{
    struct node *new_node, *last;
    int num;

    printf("\nEnter the data to insert: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("\nMemory allocation failed!");
        return;
    }

    new_node->data = num;

    if(start == NULL)
    {
        start = new_node;
        new_node->next = start;
        new_node->prev = start;
    }
    else
    {
        last = start->prev;

        new_node->next = start;
        new_node->prev = last;
        last->next = new_node;
        start->prev = new_node;
        start = new_node;
    }

    printf("\nNode inserted at the beginning.");
}

// 4. Insert at End
void insert_end()
{
    struct node *new_node, *last;
    int num;

    printf("\nEnter the data to insert: ");
    scanf("%d", &num);

    new_node = (struct node *)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("\nMemory allocation failed!");
        return;
    }

    new_node->data = num;

    if(start == NULL)
    {
        start = new_node;
        new_node->next = start;
        new_node->prev = start;
    }
    else
    {
        last = start->prev;

        last->next = new_node;
        new_node->prev = last;
        new_node->next = start;
        start->prev = new_node;
    }

    printf("\nNode inserted at the end.");
}

// 5. Insert Before a Given Node
void insert_before()
{
    struct node *new_node, *ptr;
    int num, val;

    if(start == NULL)
    {
        printf("\nList is empty.");
        return;
    }

    printf("\nEnter the data to insert: ");
    scanf("%d", &num);
    printf("\nEnter the value before which the data has to be inserted: ");
    scanf("%d", &val);

    ptr = start;
    do
    {
        if(ptr->data == val)
            break;
        ptr = ptr->next;
    } while(ptr != start);

    if(ptr->data != val)
    {
        printf("\nValue not found in the list.");
        return;
    }

    if(ptr == start)
    {
        insert_beg();
        return;
    }

    new_node = (struct node *)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("\nMemory allocation failed!");
        return;
    }

    new_node->data = num;
    new_node->next = ptr;
    new_node->prev = ptr->prev;

    ptr->prev->next = new_node;
    ptr->prev = new_node;

    printf("\nNode inserted before %d.", val);
}

// 6. Insert After a Given Node
void insert_after()
{
    struct node *new_node, *ptr;
    int num, val;

    if(start == NULL)
    {
        printf("\nList is empty.");
        return;
    }

    printf("\nEnter the data to insert: ");
    scanf("%d", &num);
    printf("\nEnter the value after which the data has to be inserted: ");
    scanf("%d", &val);

    ptr = start;
    do
    {
        if(ptr->data == val)
            break;
        ptr = ptr->next;
    } while(ptr != start);

    if(ptr->data != val)
    {
        printf("\nValue not found in the list.");
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
    new_node->prev = ptr;

    ptr->next->prev = new_node;
    ptr->next = new_node;

    printf("\nNode inserted after %d.", val);
}

// 7. Delete from Beginning
void delete_beg()
{
    struct node *ptr, *last;

    if(start == NULL)
    {
        printf("\nList is empty.");
        return;
    }

    ptr = start;

    if(start->next == start) // Only one node
    {
        start = NULL;
        free(ptr);
    }
    else
    {
        last = start->prev;
        start = start->next;

        last->next = start;
        start->prev = last;

        free(ptr);
    }

    printf("\nNode deleted from the beginning.");
}

// 8. Delete from End
void delete_end()
{
    struct node *last;

    if(start == NULL)
    {
        printf("\nList is empty.");
        return;
    }

    last = start->prev;

    if(start->next == start) // Only one node
    {
        start = NULL;
        free(last);
    }
    else
    {
        last->prev->next = start;
        start->prev = last->prev;
        free(last);
    }

    printf("\nNode deleted from the end.");
}

// 9. Delete a Specific Node
void delete_node()
{
    struct node *ptr;
    int val;

    if(start == NULL)
    {
        printf("\nList is empty.");
        return;
    }

    printf("\nEnter the value of the node to delete: ");
    scanf("%d", &val);

    ptr = start;
    do
    {
        if(ptr->data == val)
            break;
        ptr = ptr->next;
    } while(ptr != start);

    if(ptr->data != val)
    {
        printf("\nValue not found in the list.");
        return;
    }

    if(ptr == start)
    {
        delete_beg();
        return;
    }

    if(ptr->next == start)
    {
        delete_end();
        return;
    }

    ptr->prev->next = ptr->next;
    ptr->next->prev = ptr->prev;

    free(ptr);
    printf("\nNode with value %d deleted.", val);
}
