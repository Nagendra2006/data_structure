#include<stdio.h>
#define Max 5
int front=-1,rear=-1,queue[Max];
void enqueue();
void dequeue();
void display();
void main()
{
	int ch;
	clrscr();
	do
	{
		printf("Enter Choice\n1,Enqueue,2.dequeue,3.diplay4.exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:enqueue();
			break;
			case 2:dequeue();
			break;
			case 3:display();
			break;
			case 4:exit(1);
			break;
		}
	}while(ch!=4);
getch();
}
void enqueue()
{
	int n;
	if(rear>Max-1)
	{
		printf("Queue is full\n");
	}
	else
	{
		printf("Enter the elements\n");
		scanf("%d",&n);
		rear=rear+1;
		queue[rear]=n;
	}
}
void dequeue()
{
	if(front==rear)
		printf("queue is empty underfow\n");
	else
	{
		front =front+1;
		printf("the deleted element is %d",queue[front]);
	}
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
}
void display()
{
	int i;
	if(front==rear)
		printf("queue is empty\n");
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d\t",queue[i]);
		}
