/* C Program for implementing Queue using Array
   Author: Jibin Wilson S7 CSE */

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 3

int queue[MAX_SIZE], REAR = -1, FRONT = -1;

void enqueue()
{
    int item;
    if (REAR == MAX_SIZE - 1)
    {
        printf("Queue is Full\n");
    }
    else
    {
        printf("Enter the item to be pushed: ");
        scanf("%d", &item);
        if (REAR == -1 && FRONT == -1)
        {
            REAR = 0;
            FRONT = 0;
        }
        else
        {
            REAR++;
        }
        queue[REAR] = item;
        printf("%d enqueued successfully.\n", item);
    }
}

void dequeue()
{
    if (FRONT == -1 && REAR == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int item = queue[FRONT];
        printf("Item Deleted is %d\n", item);
        if (REAR == FRONT)
        {
            FRONT = -1;
            REAR = -1;
        }
        else
        {
            FRONT++;
        }
    }
}

void display()
{
    if (FRONT == -1 && REAR == -1)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = FRONT; i <= REAR; i++)
        {
            printf("%d\t", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Enter a valid choice\n");
        }
    }
    return 0;
}

