#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top=NULL,*current,*newnode,*temp;
void push();
void pop();
void dis();
void main()
{
    int ch;
    do
    {
        printf("enter your choice\n");
        printf("1.push,2.pop,3.display,4.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:dis();
            break;
            case 4:exit(0);
        }
    } while (ch!=4);   
}
void push()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter your element \n");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(top==NULL)
    {
        top=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }  
}
void pop()
{
    temp=top;
    if(top==NULL)
    {
        printf("list is empty\n");
    }
    else
    {
        printf("the delete element is %d ",top->data);
        top=top->next;
        free(temp);
    }
}
void dis()
{
    if(top==NULL)
    {
        printf("stack is empty\n");
    }
    else
    {
        temp=top;
        printf("the elements are\n");
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
    }
}