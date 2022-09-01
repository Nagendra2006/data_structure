#include<stdio.h>
void bubble(int a[30],int n);
void main()
{
    int a[10],c,n;
    printf("enter the size of an array \n");
    scanf("%d",&n);
    printf("enter the elements \n");
    for(c=0;c<n;c++)
    {
        scanf("%d",&a[c]);
    }
    bubble(a,n);
    printf("after sorting the elements\n");
    for(c=0;c<n;c++)
    {
        printf("%d\n",a[c]);
    }
}
void bubble(int a[30],int n)
{
    int i,j,temp=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}