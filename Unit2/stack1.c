// Jiya Chauhan: 92500588005
// Defination: Write a program which performs following stack operations. ->push() -> pop() -> peep() -> update()
#include <stdio.h>
#define MAX 3

int stack[MAX],top=1;
void push();
void pop();
void peek();
void update();
void display();

void main()

{
    int op;
    do
    {
        printf("\n1.push");
        printf("\n2.pop");
        printf("\n3.peek");
        printf("\n4.update");
        printf("\n5.display");
        printf("\n6.exit");
        printf("\n Enter your choice : ");
        scanf("%d",&op);

        switch(op)
        {

    case 1:
        push();
        break;
    case 2:
        pop();
        break;
    case 3:
        peek();
        break;
    case 4:
        update();
        break;
    case 5:
        display();
        break;
        }

    }while(op!=6);
}
void push()
{

    int value;
    printf("\n Enter value to be inserted :");
    scanf("%d",&value);

    if(top=MAX-1)
    {
        printf("stack is overflow");
    }
    else
    {
        top=top+1;
        stack[top]=value;
    }
}

void pop()
{
    int val;
    if(top==-1)
    {
        printf("stack is underflow ");
    }
    else
    {
        val=stack[top];
        printf("value deleted is : %d",val);
        top=top-1;
    }
}

void peek()
{
    if(top==-1)
    {
        printf("stack is empty");
    }
    else
    {
        printf("\n topmost value is : %d",stack[top]);
    }
}
void update()
{
    int i,x;
    printf("\n enter index to be updated :");
    scanf("%d",&i);

    if(top-i+1<=-1)
    {
        printf("\n invalid index...");
    }
    else
    {
        stack[top-i+1]=x;
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("\n stack is empty");
    }
    else
    {
        for(i=top;i>0;i--)
        {
            printf("\n %d",stack[i]);
        }
    }
}




