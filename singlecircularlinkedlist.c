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
struct node *start=NULL,*current,*newnode,*temp,*previous,*last;
int count()
{
    int d=0;
    temp=start;
    do
    {
        temp=temp->next;
        d++;
    }while(temp->next!=start);
    return d;
}
void main()
{
    int ch;
    clrscr();
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
        current->next=start;
        last=newnode;
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
        do
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }while(temp!=start);
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
    start->next=start;
    }
    else
    {
    newnode->next=start;
    start=newnode;
    last->next=start;
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
    current=newnode;
    current->next=start;
    }
    else
    {
    last->next=newnode;
    newnode->next=start;
    last=newnode;
    }
}
void addlocation()
{
    int loc,i;
    printf("Enter Location\n");
    scanf("%d",&loc);
    if(loc>count()+1||loc<0)
    printf("inserton is not possible\n");
    else if(loc==1)
    addbegin();
    else if(loc>count())
    addend();
    else
    {
     newnode=(struct node *)malloc(sizeof(struct node));
     printf("Enter your Data\n");
    scanf("%d",&newnode->data);
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
    if(start==NULL)
    printf("Deletion is Not possible\n");
    else
    {
    temp=start;
    start=start->next;
    free(temp);
    last->next=start;
    }
}
void deleteatend()
{
    if(start==NULL)
    printf("Deletionn is not possible\n");
    else
    {
    temp=start;
    while(temp->next->next!=start)
        temp=temp->next;
    current=temp->next;
    free(current);
    last=temp;
    temp->next=start;
    }
}
void deleteatlocation()
{
    int loc,i;
    printf("Enter Loaction\n");
    scanf("%d",&loc);
    if(loc>count()+1||loc<0)
    printf("Deletion is not possible\n");
    else if(loc==1)
    deleteatbegin();
    else if(loc>=count())
    deleteatend();
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
    for(previous=start;previous!=last;previous=previous->next)
    {
        for(current=previous->next;current!=start;current=current->next)
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