#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void add_beggin();
void add_end();
void add_loc();
void del_loc();
void del_beggin();
void del_end();
void sort();
void find_replace();
int count();
struct node
{
    int data;
    struct node *next,*prev;
};
struct node *start=NULL,*current,*previous,*newnode,*temp,*last;
void main()
{
    int ch;
    do{
        printf("enter your choice\n");
        printf("1.create\n2.display\n3.add_beggin\n4.add_end\n5.add_loc\n6.del_beggin\n7.del_end\n8.del_loc\n9.sort\n10.find_replace\n11.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:create();
            break;
            case 2:display();
            break;
            case 3:add_beggin();
            break;
            case 4:add_end();
            break;
            case 5:add_loc();
            break;
            case 6:del_beggin();
            break;
            case 7:del_end();
            break;
            case 8:del_loc();
            break;
            case 9:sort();
            break;
            case 10:find_replace();
            break;
            case 11:exit(0);
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
        printf("enter your data\n");
        scanf("%d",&newnode->data);
        newnode->prev=NULL;
        newnode->next=NULL;
        if(start==NULL)
        {
            start=newnode;
            current=newnode;
        }
        else
        {
            current->next=newnode;
            newnode->prev=current;
            last=newnode;
            last->next=start;
            start->prev=last;
        }
        printf("if you want to create data don't press 0 you can press other number \n ");
        scanf("%d",&ch);
    }while(ch!=0);
    
}
void display()
{
    if(start==NULL)
    printf("list is empty\n");
    else
    {
        temp=start;
        do 
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }while(temp!=start);
    }
}
void add_beggin()
{
    newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter your data\n");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        newnode->prev=NULL;
        if(start==NULL)
        {
            start=newnode;
            current=newnode;
            last=newnode;
        }
        else
        {
            newnode->next=start;
            start->prev=newnode;
            start=newnode;
            last->next=newnode;
            newnode->prev=last;
            
        }
}
void add_end()
{
    temp=start;
    newnode=(struct node *)malloc(sizeof(struct node));
        printf("enter your data\n");
        scanf("%d",&newnode->data);
        start->prev=NULL;
            start->next=NULL;
        if(start==NULL)
        {
            start=newnode;
        }
        else
        {
            last->next=newnode;
            newnode->prev=last;
            last=newnode;
            last->next=start;
            start->prev=last;
        }
}
void add_loc()
{
    current=start;
    int loc,i;
    printf("enter the loc\n");
    scanf("%d",&loc);
    if(loc>count()+1||loc<=0)
    printf("insertion is not possible\n");
    else if(loc==1)
    {
        add_beggin();
    }
    else if(loc>count())
    {
        add_end();
    }
    else
    {   
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the data\n");
        scanf("%d",&newnode->data);
        for(i=1;i<loc;i++)
        {
        previous=current;
        current=current->next;
        }
    
        previous->next=newnode;
        newnode->prev=previous;
        newnode->next=current;
        current->prev=newnode;
    }
}
void del_beggin()
{
    temp=start;
    if(start==NULL)
    printf("list is empty \n");
    else
    {
        start=start->next;
        start->prev=last;
        last->next=start;
        printf("the delete data is%d\t",temp->data);
        free(temp);
    }
}
void del_end()
{
    temp=start;
    if(start==NULL)
    printf("deletion is not possible\n");
    else
    {
        temp=last->prev;
        temp->next=start;
        start->prev=temp;
        printf("the delete data is%d\t",current->data);
        free(last);
        last=temp;
    }
}
void del_loc()
{
    int loc,i;
    current=start;
    printf("enter the loc\n");
    scanf("%d",&loc);
    if(loc>count()+1||0>loc)
    printf("deletion is not possible\n");
    else if(loc==1)
    del_beggin();
    else if(loc>count())
    {
        del_end();
    }
    else
    {
    
    for(i=1;loc>i;i++)
    {
        previous=current;
        current=current->next;
    }
    previous->next=current->next;
    current->next=previous;
    printf("the delete data is%d\t",current->data);
    free(current);
    }
}
void sort()
{
    int d;
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
    display();
}
void find_replace()
{
    int old,newvalue;
    printf("enter the old and new values\n");
    scanf("%d%d",&old,&newvalue);
    temp=start;
    while(temp->data!=old&&temp!=NULL)
    {
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("the search element is not found\n");
        exit(0);
    }
    temp->data=newvalue;
    printf("after replacing the list is \n");
    display();
}
int count()
{
    int c=0;
    temp=start;
    while(temp!=NULL)
    {
        temp=temp->next;
        c++;
    }
    return c;
}