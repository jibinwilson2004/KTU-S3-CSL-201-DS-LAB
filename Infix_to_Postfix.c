/*
C Program for converting Infix Expression to Postfix Expression
Author: Jibin Wilson
S7 CSA
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
char postfix[MAX_SIZE];
int top = -1;

void push(char item)
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

char pop()
{
    char item = stack[top];
    top = top - 1;
    return item;
}

int precedence(char n)
{
    switch (n)
    {
        case '^':
            return 3;
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;
        default:
            return 0;
    }
}

int main()
{
    int i, j = 0;
    char infix[MAX_SIZE];
    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    for (i = 0; i < strlen(infix); i++)
    {
        switch (infix[i])
        {
            case '(':
                push(infix[i]);
                break;

            case ')':
                while (stack[top] != '(')
                {
                    postfix[j] = pop();
                    j++;
                }
                pop();
                break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                if (precedence(infix[i]) > precedence(stack[top]))
                {
                    push(infix[i]);
                }
                else if (precedence(infix[i]) <= precedence(stack[top]))
                {
                    if (infix[i] == '^')
                    {
                        push(infix[i]);
                    }
                    else
                    {
                        while (precedence(infix[i]) <= precedence(stack[top]))
                        {
                            postfix[j] = pop();
                            j++;
                        }
                        push(infix[i]);
                    }
                }
                break;

            default:
                postfix[j] = infix[i];
                j++;
        }
    }

    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';
    printf("Postfix Expression: %s\n", postfix);
    return 0;
}

