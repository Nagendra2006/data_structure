#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int top=-1;
int stack[MAX];
void push();
void pop();
void display();
void main()
{
    int ch;
    do 
    {
        printf("enter your choice\n");
        printf("1.push,2,pop,3.display,4.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:display();
            break;
            case 4:exit(0);

        }
    }while(ch!=4);
}
void push()
{
    int n;
    if(top>=MAX-1)
    {
        printf("stack is full\n");
    }
    else
    {
        printf("enter the element\n");
        scanf("%d",&n);
        top=top+1;
        stack[top]=n;
    }
}
void pop()
{
    if(top<0)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("the poped element is %d",stack[top]);
        top=top-1;
       printf("\n");
    }
}
void display()
{
    int i;
    if(top==-1)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("the elements are \n");
        for(i=top;i>=0;i--)
        {
            printf("%d",stack[i]);
        }
    }
}