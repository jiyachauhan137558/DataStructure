// Jiya Chauhan: 92500588005
// Defination: Write a program to find out factorial of number using stack.
#include <stdio.h>
#define MAX 50
int stack[MAX], top = -1;

void push(int value);
int pop();


void main() {

    int n,i,fact=1;

    printf("Enter numbers:\n");
    scanf("%d", &n);
    for (int i = 1; i <=n; i++)
    {
      push(i);
    }
    while(top!=-1)
    {
        fact*=pop();
    }
    printf("\n Factorial is: %d",fact);


}

void push(int value)
 {
    if(top==MAX-1)
{
    printf("\n stack overflow");
}
else
{
    top++;
    stack[top]=value;
}
 }
int pop()
{
    int val;
    if(top==-1)
    {
        printf("\n underflow");
        return -1;
    }
    else{
        val=stack[top];
        top--;
        return val;
    }
}


