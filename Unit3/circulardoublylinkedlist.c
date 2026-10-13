//92500588005
//Jiya Chauhan
//circular doubly linked list

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
    struct node *prev;
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
        printf("\n1. Create a list");
        printf("\n2. Display the list");
        printf("\n3. Insert at the beginning");
        printf("\n4. Insert at the end");
        printf("\n5. Insert before a given node");
        printf("\n6. Insert after a given node");
        printf("\n7. Delete from the beginning");
        printf("\n8. Delete from the end");
        printf("\n9. Delete a specific node");
        printf("\n10. Exit");

        printf("\n\nEnter your option: ");
        scanf("%d", &option);

        switch (option)
        {
            case 1: create_ll(); break;
            case 2: display(); break;
            case 3: insert_beg(); break;
            case 4: insert_end(); break;
            case 5: insert_before(); break;
            case 6: insert_after(); break;
            case 7: delete_beg(); break;
            case 8: delete_end(); break;
            case 9: delete_node(); break;
            case 10: printf("\nExiting program..."); break;
            default: printf("\nInvalid option!");
        }

    } while (option != 10);

    return 0;
}

/* CREATE LINKED LIST */
void create_ll()
{
    struct node *new_node, *last;
    int num;

    printf("\nEnter -1 to stop.");
    printf("\nEnter data: ");
    scanf("%d", &num);

    while (num != -1)
    {
        new_node = malloc(sizeof(struct node));

        if (new_node == NULL)
        {
            printf("\nMemory allocation failed!");
            return;
        }

        new_node->data = num;

        if (start == NULL)
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
        }

        printf("\nEnter data: ");
        scanf("%d", &num);
    }
}

/* DISPLAY */
void display()
{
    struct node *ptr;

    if (start == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    ptr = start;

    do
    {
        printf("%d <-> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != start);

    printf("(back to start)");
}

/* INSERT AT BEGINNING */
void insert_beg()
{
    struct node *new_node, *last;
    int num;

    printf("\nEnter data: ");
    scanf("%d", &num);

    new_node = malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("\nMemory allocation failed!");
        return;
    }

    new_node->data = num;

    if (start == NULL)
    {
        start = new_node;
        new_node->next = start;
        new_node->prev = start;
        return;
    }

    last = start->prev;

    new_node->next = start;
    new_node->prev = last;
    last->next = new_node;
    start->prev = new_node;
    start = new_node;
}

/* INSERT AT END */
void insert_end()
{
    struct node *new_node, *last;
    int num;

    printf("\nEnter data: ");
    scanf("%d", &num);

    new_node = malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("\nMemory allocation failed!");
        return;
    }

    new_node->data = num;

    if (start == NULL)
    {
        start = new_node;
        new_node->next = start;
        new_node->prev = start;
        return;
    }

    last = start->prev;

    new_node->next = start;
    new_node->prev = last;
    last->next = new_node;
    start->prev = new_node;
}

/* INSERT BEFORE A GIVEN VALUE */
void insert_before()
{
    struct node *ptr, *new_node;
    int key, num;

    if (start == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    printf("\nEnter value before which to insert: ");
    scanf("%d", &key);

    ptr = start;

    do
    {
        if (ptr->data == key)
            break;

        ptr = ptr->next;
    } while (ptr != start);

    if (ptr->data != key)
    {
        printf("\nValue not found!");
        return;
    }

    printf("\nEnter new data: ");
    scanf("%d", &num);

    new_node = malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("\nMemory allocation failed!");
        return;
    }

    new_node->data = num;
    new_node->next = ptr;
    new_node->prev = ptr->prev;
    ptr->prev->next = new_node;
    ptr->prev = new_node;

    if (ptr == start)
        start = new_node;
}

/* INSERT AFTER A GIVEN VALUE */
void insert_after()
{
    struct node *ptr, *new_node;
    int key, num;

    if (start == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    printf("\nEnter value after which to insert: ");
    scanf("%d", &key);

    ptr = start;

    do
    {
        if (ptr->data == key)
            break;

        ptr = ptr->next;
    } while (ptr != start);

    if (ptr->data != key)
    {
        printf("\nValue not found!");
        return;
    }

    printf("\nEnter new data: ");
    scanf("%d", &num);

    new_node = malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("\nMemory allocation failed!");
        return;
    }

    new_node->data = num;
    new_node->prev = ptr;
    new_node->next = ptr->next;
    ptr->next->prev = new_node;
    ptr->next = new_node;
}

/* DELETE FROM BEGINNING */
void delete_beg()
{
    struct node *temp, *last;

    if (start == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    temp = start;

    if (start->next == start)
    {
        start = NULL;
        free(temp);
        printf("\nNode deleted.");
        return;
    }

    last = start->prev;
    start = start->next;
    start->prev = last;
    last->next = start;

    free(temp);
    printf("\nNode deleted.");
}

/* DELETE FROM END */
void delete_end()
{
    struct node *last, *second_last;

    if (start == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    last = start->prev;

    if (last == start)
    {
        start = NULL;
        free(last);
        printf("\nNode deleted.");
        return;
    }

    second_last = last->prev;
    second_last->next = start;
    start->prev = second_last;

    free(last);
    printf("\nNode deleted.");
}

/* DELETE A SPECIFIC NODE */
void delete_node()
{
    struct node *ptr;
    int key;

    if (start == NULL)
    {
        printf("\nList is empty!");
        return;
    }

    printf("\nEnter value to delete: ");
    scanf("%d", &key);

    ptr = start;

    do
    {
        if (ptr->data == key)
            break;

        ptr = ptr->next;
    } while (ptr != start);

    if (ptr->data != key)
    {
        printf("\nValue not found!");
        return;
    }

    if (ptr->next == ptr)
    {
        start = NULL;
    }
    else
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;

        if (ptr == start)
            start = ptr->next;
    }

    free(ptr);
    printf("\nNode deleted.");
}
