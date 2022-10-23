#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *temp,*newnode,*front=NULL,*rear=NULL;
void enqueue();
void dequeue();
void dis();
void main()
{
    int ch;
    do
    {
        printf("enter your choice\n");
        printf("1.enqueue,2.dequeue,3.display,4.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:enqueue();
            break;
            case 2:dequeue();
            break;
            case 3:dis();
            break;
            case 4:exit(0);
        }
    }while(ch!=4);
}
void enqueue()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter your data\n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(rear==NULL)
    {
        rear=newnode;
        front=newnode;
        rear->next=front;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
}
void dequeue()
{
    temp=front;
    if(front==NULL&&rear==NULL)
        printf("queue is empty");
    else if(front==rear)
    {
        printf("%d",front->data);
        front=NULL;
        rear=NULL;
    }
    else 
    {
        front=front->next;
        printf("%d",temp->data);
        free(temp);
        rear->next=front;
    }
}
void dis()
{
    if(front==NULL&&rear==NULL)
        printf("queue is empty\n");
    else
    {
	temp=front;
	printf("%d\t",temp->data);
	temp=temp->next;
	while(temp->next!=front->next)
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
}
}