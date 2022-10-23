#include<stdio.h>
#define Max 5
int front=-1,rear=-1,cq[Max],count=0;
void enqueue()
{
    int n;
    if(count==Max)
        printf("Queue is full");
    else
    {
        printf("enter elements to insert\n");
        scanf("%d",&n);
        rear=(rear+1)%Max;
        cq[rear]=n;
        count++;
    }
}
void dequeue()
{
    if(count==0)
        printf("queue isd empty\n");
    else
    {
        front=(front+1)%Max;
        printf("the deleted element %d",cq[front]);
        count--;
    }
}
void display()
{
    int i;
    if(count==0)
        printf("queue is empty\n");
    else
    {
        printf("te elements are\n");
        for(i=0;i<count;i++)
        {   
            printf("%d\t",cq[i]);
        }
    }
}
void main()
{
        int ch;
        do
        {
            printf("enter your choice\n1.enqueue,2.dequeue,3.display,4.exit\n");
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
}