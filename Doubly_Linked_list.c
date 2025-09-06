/*
C Program for Doubly Linked List with position-based insertion and deletion
Author: JIBIN WILSON
S7 CSE
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

void insertAtBeginning()
{
    int value;
    printf("Enter the value to insert at beginning: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

void insertAtEnd()
{
    int value;
    printf("Enter the value to insert at end: ");
    scanf("%d", &value);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition()
{
    int value, pos;
    printf("Enter the value to insert: ");
    scanf("%d", &value);
    printf("Enter the position to insert at: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        insertAtBeginning();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void deleteAtBeginning()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    printf("Deleted %d from beginning\n", temp->data);
    free(temp);
}

void deleteAtEnd()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    if (temp->next == NULL)
    {
        printf("Deleted %d from end\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    printf("Deleted %d from end\n", temp->data);
    free(temp);
}

void deleteAtPosition()
{
    int pos;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (pos == 1)
    {
        deleteAtBeginning();
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("Deleted %d from position %d\n", temp->data, pos);
    free(temp);
}

void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n");
        printf("4. Delete at Beginning\n5. Delete at End\n6. Delete at Position\n");
        printf("7. Display\n8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertAtBeginning();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                insertAtPosition();
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                deleteAtPosition();
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Enter a valid choice\n");
        }
    }

    return 0;
}

