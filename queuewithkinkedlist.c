#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *temp,*newnode,*current,*front=NULL,*rear=NULL;
void enqueue();
void dequeue();
void display();
void main()
{
	int ch;
	clrscr();
	do
	{
		printf("ENter your choice\n1.enqueue,2.dequeue,3.display,4.exit\n");
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
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter your data\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(front==NULL&&rear==NULL)
	{
		rear=newnode;
		front=rear;
	}
	else
	{
		rear->next=newnode;
		rear=newnode;
	}
}
void dequeue()
{
	if(front==NULL)
		printf("queue is underflow\n");
	else
	{
		temp=front;
		printf("The deleted element is %d",front->data);
		front=front->next;
		free(temp);
		if(front==NULL)
			rear=NULL;
	}
}
void display()
{
	if(front==NULL&rear==NULL)
		printf("queue is underflow\n");
	else
	{
		for(temp=front;temp!=NULL;temp=temp->next)
		{
			printf("%d\t",temp->data);
		}
	}
}