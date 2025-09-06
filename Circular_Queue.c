#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 3
int queue[MAX_SIZE], REAR=-1, FRONT=-1;
void enqueue()
{
	int item;
	if(FRONT==((REAR+1)%MAX_SIZE))
	{
		printf("Queue is Full");
	}
	else
	{
		printf("Enter the item to be pushed:");			
		scanf("%d", &item);
		if(REAR==-1 && FRONT==-1)
		{
			REAR=0;
			FRONT=0;
		}
		else
		{
			REAR=(REAR+1)%MAX_SIZE;	
		}
		queue[REAR]=item;
	}

}

void dequeue()
{
	int item;
	if(REAR==-1 && FRONT==-1)
	{
		printf("Queue is empty");
	}
	else{
		if(REAR==FRONT){
			item = queue[FRONT];
			printf("Item Deleted is %d", item);
			FRONT=-1;
			REAR=-1;
		}else{
			item = queue[FRONT];
			printf("Item Deleted is %d", item);
			FRONT=(FRONT+1)%MAX_SIZE;
		}
	}
}

void display(){
	if(FRONT==-1 && REAR==-1)
     		printf("Queue is empty");
   	else if (FRONT<=REAR)
   	{
 		for(int i=FRONT;i<=REAR;i++)
		{
    			printf("%d\t",queue[i]);
		}
	}
	else
	{
		for (int i = FRONT; i < MAX_SIZE; i++)
            		printf("%d\t", queue[i]);
                for (int i = 0; i <= REAR; i++)
    			printf("%d\t", queue[i]);
    	}
}

void main()
{
	while(1)
	{
		int n;
		printf("\n 1. Enqueue\n 2. Dequeue\n 3. Display\n 4. Exit\n");
		printf("Enter your choice:");
		scanf("%d", &n);
		switch(n)
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
				break;
			default:
				printf("Enter a valid choice");
		

		}
	 }
}
