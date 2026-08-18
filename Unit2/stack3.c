// Jiya Chauhan: 92500588005
// Defination: Write a program to print string in reverse order using stack.
#include <stdio.h>

#define MAX 50

char stack[MAX];
int top = -1;

void push(char value);
char pop();

int main()
{
    char str[20];
    int i = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0' && str[i] != '\n')
    {
        push(str[i]);
        i++;
    }

    printf("Reversed string: ");

    while (top != -1)
    {
        printf("%c", pop());
    }

    return 0;
}

void push(char value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        stack[++top] = value;
    }
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    else
    {
        return stack[top--];
    }
}
