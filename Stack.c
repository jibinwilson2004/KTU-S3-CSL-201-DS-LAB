/* 
   C Program for implementing Stack using Array
   Author: Jibin Wilson S7 CSE
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 3

int stack[MAX_SIZE], top = -1;

void push(int s[], int t, int maxSize)
{
    int item;
    if (t == maxSize - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter the item to be pushed: ");
        scanf("%d", &item);
        top = t + 1;
        s[top] = item;
    }
}

void pop(int s[], int t)
{
    if (t == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int item = s[t];
        printf("Element deleted is %d\n", item);
        top = t - 1;
    }
}

void display(int s[], int t)
{
    if (t == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        for (int i = t; i >= 0; i--)
        {
            printf("%d\t", s[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                push(stack, top, MAX_SIZE);
                break;
            case 2:
                pop(stack, top);
                break;
            case 3:
                display(stack, top);
                break;
            case 4:
                exit(0);
            default:
                printf("Enter a valid choice\n");
        }
    }

    return 0;
}

