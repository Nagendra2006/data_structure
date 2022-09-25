#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void addbegin();
void addend();
void addlocation();
void deleteatbegin();
void deleteatend();
void deleteatlocation();
void sort();
void findandreplace();
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL,*current,*newnode,*temp,*previous;
void main()
{
	int ch;
	do
	{
	printf("\nEnter Your choice:");
	printf("\n1.Create,2.Display,3.addbegin,4.addend,5.addlocation,6.deleteatbegin,7.deleteatend,8.deleteatlocation,9.sort,10.findandreplace,11.exit\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:create();
		break;
		case 2:display();
		break;
		case 3:addbegin();
		break;
		case 4:addend();
		break;
		case 5:addlocation();
		break;
		case 6:deleteatbegin();
		break;
		case 7:deleteatend();
		break;
		case 8:deleteatlocation();
		break;
		case 9:sort();
		break;
		case 10:findandreplace();
		break;
		case 11:exit(1);
		break;
	}
	}while(ch!=11);
}
void create()
{
	int ch;
	do
	{
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("Enter Your Data:\n");
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		if(start==NULL)
		{
		    start=newnode;
		    current=newnode;
		}
		else
		{
		    current->next=newnode;
		    current=newnode;
		}
		printf("if you want to continue\nDo not press o(Zero)\n");
		scanf("%d",&ch);
	}while(ch!=0);
}
void display()
{
	if(start==NULL)
	printf("The list is empty\n");
	else
	{
		temp=start;
		printf("the elements are\n");
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
		}
	}
}
void addbegin()
{
    newnode=(struct node * )malloc(sizeof(struct node));
    printf("Enter Your Data;\n");
    scanf("%d",&newnode->data);
    if(start==NULL)
    {
        start=newnode;
        newnode->next=NULL;
    }
    else
    {
        newnode->next=start;
        start=newnode;
    }
}
void addend()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter Your data\n");
    scanf("%d",&newnode->data);
    if(start==NULL)
    {
        start=newnode;
        newnode->next=NULL;
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
        newnode->next=NULL;
    }
}
void addlocation()
{
    int loc,i;
    printf("Enter Location\n");
    scanf("%d",&loc);
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter your Data\n");
    scanf("%d",&newnode->data);
    if(start==NULL)
    {
        start=newnode;
        newnode->next=NULL;
    }
    else
    {
        current=start;
        for(i=1;i<loc;i++)
        {
            previous=current;
            current=current->next;
        }
        previous->next=newnode;
        newnode->next=current;
    }
}
void deleteatbegin()
{
    temp=start;
    if(start==NULL)
        printf("Deletion is Not possible\n");
    else
    {
        start=start->next;
        free(temp);
    }
}
void deleteatend()
{
    temp=start;
    if(start==NULL)
        printf("Deletionn is not possible\n");
    else
    {
        while(temp->next->next!=NULL)
            temp=temp->next;
        current=temp->next;
        temp->next=NULL;
        free(current);
    }
}
void deleteatlocation()
{
    int loc,i;
    printf("Enter Loaction\n");
    scanf("%d",&loc);
    if(start==NULL)
        printf("Deletion is not Possible\n");
    else
    {
        current=start;
        for(i=1;i<loc;i++)
        {
            previous=current;
            current=current->next;
        }
        previous->next=current->next;
        free(current);
    }
}
void sort()
{
    int d;
    if(start==NULL)
        printf("List is Empty\nsorting is not possible\n");
    else
    {
        for(previous=start;previous!=NULL;previous=previous->next)
        {
            for(current=previous->next;current!=NULL;current=current->next)
            {
                if(previous->data>current->data)
                {
                    d=previous->data;
                    previous->data=current->data;
                    current->data=d;
                }
            }
        }
    }
    display();
}
void findandreplace()
{
    int old,newvalue;
    if(start==NULL)
        printf("Lis is Empty\n");
    else
    {
        printf("Enter old value to Find\n");
        scanf("%d",&old);
        printf("Enter new value to replace\n");
        scanf("%d",&newvalue);
        temp=start;
        while(temp->data!=old&&temp!=NULL)
            temp=temp->next;
        if(temp==NULL)
            printf("the element not found\n");
        temp->data=newvalue;
        display();
    }
}