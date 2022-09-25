#include<stdio.h>
void search(int a[],int key,int high)
{
    int mid,found=0;
    int low=0;
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
            high=mid-1;
        else
            low=mid+1;
    }
    if(found==0)
        printf("\n search is unsuccessful ");

}
int main()
{
    int a[50],i,n,key;
    printf("\n enter no.of elemets in an array ");
    scanf("%d",&n);
    printf("\n enter elemets in an array");
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("\n enter the elements u want to search");
    scanf("%d",&key);
    search(a,key,n);
    return 0;
}
