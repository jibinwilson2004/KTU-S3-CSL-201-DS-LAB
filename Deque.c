/*
C Program for implementing Double Ended Queue using Array
Author: JIBIN WILSON
S7 CSA
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 3

int queue[MAX_SIZE], LEFT = -1, RIGHT = -1;

int isFull()
{
    return (LEFT == 0 && RIGHT == MAX_SIZE - 1) || (LEFT == RIGHT + 1);
}

int isEmpty()
{
    return LEFT == -1 && RIGHT == -1;
}

void enqueueRight()
{
    int item;
    if (isFull())
    {
        printf("Queue is Full\n");
    }
    else
    {
        printf("Enter the item to be pushed: ");
        scanf("%d", &item);
        if (isEmpty())
        {
            LEFT = RIGHT = 0;
        }
        else if (RIGHT == MAX_SIZE - 1)
        {
            RIGHT = 0;
        }
        else
        {
            RIGHT++;
        }
        queue[RIGHT] = item;
    }
}

void enqueueLeft()
{
    int item;
    if (isFull())
    {
        printf("Queue is Full\n");
    }
    else
    {
        printf("Enter the item to be pushed: ");
        scanf("%d", &item);
        if (isEmpty())
        {
            LEFT = RIGHT = 0;
        }
        else if (LEFT == 0)
        {
            LEFT = MAX_SIZE - 1;
        }
        else
        {
            LEFT--;
        }
        queue[LEFT] = item;
    }
}

void dequeueRight()
{
    int item;
    if (isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        item = queue[RIGHT];
        printf("Item Deleted is %d\n", item);
        if (LEFT == RIGHT)
        {
            LEFT = RIGHT = -1;
        }
        else if (RIGHT == 0)
        {
            RIGHT = MAX_SIZE - 1;
        }
        else
        {
            RIGHT--;
        }
    }
}

void dequeueLeft()
{
    int item;
    if (isEmpty())
    {
        printf("Queue is empty\n");
    }
    else
    {
        item = queue[LEFT];
        printf("Item Deleted is %d\n", item);
        if (LEFT == RIGHT)
        {
            LEFT = RIGHT = -1;
        }
        else if (LEFT == MAX_SIZE - 1)
        {
            LEFT = 0;
        }
        else
        {
            LEFT++;
        }
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty\n");
    }
    else if (LEFT <= RIGHT)
    {
        for (int i = LEFT; i <= RIGHT; i++)
            printf("%d\t", queue[i]);
    }
    else
    {
        for (int i = LEFT; i < MAX_SIZE; i++)
            printf("%d\t", queue[i]);
        for (int i = 0; i <= RIGHT; i++)
            printf("%d\t", queue[i]);
    }
    printf("\n");
}

int main()
{
    while (1)
    {
        int n;
        printf("\n 1. Insertion Through Left\n 2. Insertion Through Right\n 3. Deletion Through Left\n 4. Deletion Through Right\n 5. Display\n 6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &n);
        switch (n)
        {
            case 1: enqueueLeft(); break;
            case 2: enqueueRight(); break;
            case 3: dequeueLeft(); break;
            case 4: dequeueRight(); break;
            case 5: display(); break;
            case 6: exit(0);
            default: printf("Enter a valid choice\n");
        }
    }
    return 0;
}

