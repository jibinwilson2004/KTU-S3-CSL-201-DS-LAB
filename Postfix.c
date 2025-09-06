/*
C Program for Evaluating Postfix Expression
Author: JIBIN WILSON
S7 CSE
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Global variables
int stack[MAX_SIZE], top = -1;

// Function to push
void push(int item)
{
    if (top == MAX_SIZE - 1)
    {
        printf("Stack Overflow");
    }
    else
    {
        top = top + 1;
        stack[top] = item;
    }
}

// Function to pop
int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow");
        return 0;
    }
    else
    {
        int item = stack[top];
        top = top - 1;
        return item;
    }
}

// Function to display stack
void display()
{
    if (top == -1)
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Result: %d", stack[top]);
    }
}

// Main function
int main()
{
    char postfix[100];

    printf("Enter Postfix Expression: ");
    scanf("%s", postfix);

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        if (isalnum(postfix[i]))
        {
            push(postfix[i] - '0');  // Convert char to int
        }
        else
        {
            int a = pop();
            int b = pop();
            int res = 0;

            switch (postfix[i])
            {
                case '+':
                    res = b + a;
                    break;
                case '-':
                    res = b - a;
                    break;
                case '*':
                    res = b * a;
                    break;
                case '/':
                    res = b / a;
                    break;
                case '^':
                    res = b ^ a; // Bitwise XOR (not power)
                    break;
            }
            push(res);
        }
    }

    display();

    return 0;
}

