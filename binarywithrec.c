#include<stdio.h>
void binarysearch(int a[],int low,int high,int key)
{
    int mid,found=0;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(key==a[mid])
        {
            printf("\n the searched element at %d position",mid);
            found=1;
            break;
        }
        else
            if(key<a[mid])
            return binarysearch(a,low,mid-1,key);
        else
            return binarysearch(a,mid+1,high,key);
    }
    if(found==0)
        printf("\n search is unsuccessful ");
}
void main()
{
    int a[50],i,n,key;
    printf("\n enter no.of elemets in an array ");
    scanf("%d",&n);
    printf("\n enter elemets in an array");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("\n enter the elements u want to search");
    scanf("%d",&key);
    binarysearch(a,0,n,key);
}

