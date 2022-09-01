#include<stdio.h>
void selection(int a[30],int n);
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
    selection(a,n);
    printf("after sorting the elements\n");
    for(c=0;c<n;c++)
    {
        printf("%d\n",a[c]);
    }
}
void selection(int a[30],int n)
{
    int i,j,temp=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}