#include <stdio.h>

void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void perm(int arr[],int size)
{   int flag=0;
    int m=0,n=0;
    
    while(1)
    {   
        //step 1 
        int k=0;
        while(k<size-1)
            {
                if(arr[k]<arr[k+1])
                   { m=k;
                    flag=1;
                   }
                k++;   
            }
        if(flag==0)return;
        //step 2 
        int l=m+1;
        while(l<size)
            {
                if(arr[m]<arr[l])
                    n=l;
                l++;
            }
        //step 3 
        swap(&arr[m],&arr[n]);
        //step 4 
        int end=size-1;
        int start=m+1;
        while(start<end)
        {
            swap(&arr[start],&arr[end]);
            start++;
            end--;
        }
        //print the new permutation
        for(int t=0;t<size;t++)
            printf("%d ",arr[t]);
        printf("\n");
        m=0; n=0; flag=0;                
    }
}

int main()
{
    int n;
    puts("Enter the size of array.");
    scanf("%d",&n);
    if(n>0)
    {
        int arr[n];
        puts("Enter the elements of array in ascending or descending");
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        perm(arr,n);
    } 
    return 0;
}

