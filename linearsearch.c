#include<stdio.h>
int found=0; 
void sort(int a[],int ele,int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        if(ele==a[i])
        {
            printf("the searched element at %d  position\n",i);
            found=1;
            break;
        }
    }
    if(found==0)
        printf(" search is unsuccessful\n ");
}
int main()
{
    int a[50],i,n,ele;
    printf("enter no.of elemets in an array\n");
    scanf("%d",&n);
    printf(" enter elemets in an array\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf(" enter the elements u want to search\n");
    scanf("%d",&ele);
    sort(a,ele,n);

    return 0;
}
