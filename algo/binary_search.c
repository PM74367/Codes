#include <stdio.h>
#include <stdlib.h>
int bs(int arr[],int key,int l,int r)
{   
    int m=l + (r-l)/2;
    if(l<=r)
    {     
        if(arr[m]==key)
            return m;
        else if(arr[m]>key)
            {
                r=m-1;
                return bs(arr,key,l,r);
            }
        else if(arr[m]<key)
            {
                 l=m+1;
                return bs(arr,key,l,r);
            }
    }
        return -1;

}
int main()
{   int n;
    puts("Enter the size of array.");
    scanf("%d",&n);
    if(n>0)
    {
        int arr[n];
        puts("Enter the elements of array in ascending or descending");
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        puts("Enter the element to find in the array");
        int key;
        scanf("%d",&key);
        int ans=bs(arr,key,0,n-1);
        if(ans==-1)
            puts("Element not found");
        else 
            printf("Element found at %d position\n",ans+1);
            return 0;
    } 
  return 0;
}