// Jiya Chauhan: 92500588005
// Defination: Write a program which performs following operations using circular queue. Insert() -> delete() -> display()
#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert();
void delete_element();
void display();

int main()
{
    int option,val;
    do
    {
        printf("\n*****MAIN MANU*****");
        printf("\n1. Insert an Element");
        printf("\n2. Delete an Element");
        printf("\n3. Display the queue");
        printf("\n4. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                insert();
                break;

            case 2:
                val = delete_element();
                if(val!=-1)
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

    // Check if queue is full
    if((front == 0 && rear == MAX - 1) || (front == rear + 1))
    {
        printf("\nQueue Overflow!\n");
        return;
    }

    printf("Enter a value: ");
    scanf("%d", &num);

    if(front == -1)
    {
        front = rear = 0;
    }
    else if(rear == MAX - 1)
    {
        rear = 0;
    }
    else
    {
        rear++;
    }

    queue[rear] = num;
    printf("Inserted: %d\n", num);
}

void delete_element()
{
    int val;

    if(front == -1)
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
    else if(front == MAX - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

void display()
{
    int i;

    if(front == -1)
    {
        printf("\nQueue is Empty!\n");
        return;
    }

    printf("\nQueue elements are:\n");

    if(front <= rear)
    {
        for(i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    else
    {
        for(i = front; i < MAX; i++)
        {
            printf("%d ", queue[i]);
        }

        for(i = 0; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }

    printf("\n");
}
