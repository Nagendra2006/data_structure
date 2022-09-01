#include<stdio.h>
void insertion(int a[30],int n);
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
    insertion(a,n);
    printf("after sorting the elements\n");
    for(c=0;c<n;c++)
    {
        printf("%d\n",a[c]);
    }
}
void insertion(int a[10],int n)
{
    int temp,i,j;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i;
        while(a[j-1]>temp&&j>0)
        {
            a[j]=a[j-1];
            j=j-1;
        }
        a[j]=temp;
    }

}