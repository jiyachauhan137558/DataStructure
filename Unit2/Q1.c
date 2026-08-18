// Jiya Chauhan: 92500588005
// Defination: Write a program which performs following operations using simple queue. insert() -> delete() -> display()
#include <stdio.h>

#define MAX 5



int front = -1, rear = -1;
int queue[MAX];

void insert();
void delete_elements();
void display();

int main()
{
    int op;

    do
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                insert();
                break;

            case 2:
                delete_elements();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("\nProgram Exited.\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(op != 4);

    return 0;
}

void insert()
{
    int num;

    if(rear == MAX - 1)
    {
        printf("\nQueue Overflow!\n");
        return;
    }

    printf("Enter a value: ");
    scanf("%d", &num);

    if(front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }

    queue[rear] = num;

    printf("Inserted: %d\n", num);
}

void delete_elements()
{
    int val;

    if(front == -1 || front > rear)
    {
        printf("\nQueue Underflow!\n");
        return;
    }

    val = queue[front];
    printf("Deleted value: %d\n", val);

    if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

void display()
{
    int i;

    if(front == -1 || front > rear)
    {
        printf("\nQueue is Empty!\n");
        return;
    }

    printf("\nQueue elements are:\n");

    for(i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

