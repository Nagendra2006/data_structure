#include<stdio.h>
int a[10],b[100],c[10];
void mergesort(int m,int n)
{
    int i=0,j=0,k=0;
    while(i<m && j<n)
    {
        if(a[i]<b[i])
        {
            c[k++]=a[i++];
        }
        else
        {
            c[k++]=b[j++];
        }
    }
    while(i<m)
    {
        c[k++]=a[i++];
    }
    while(j<n)
    {
        c[k++]=b[j++];
    }
    for(i=0;i<n+m;i++)
    {
        printf("%d\t",c[i]);
    }
}
void main()
{
    int i,j,k=0,m,n;
    printf("enter the size of an aray \n");
    scanf("%d",&m);
    printf("enter the a array elements\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("enter the size of an array b\n");
    scanf("%d",&n);
    printf("enter the b array elements\n");
    for(j=0;j<n;j++)
    {
        scanf("%d",&b[i]);
    }
    mergesort(m,n);
    
}