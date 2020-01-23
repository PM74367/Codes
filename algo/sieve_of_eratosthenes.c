#include <stdio.h>
#include <string.h>
#include <stdbool.h>
void generate_series(int n)
{
    bool prime[n+1];//array is from 0 - 50 th index 
    memset(prime,true,sizeof(prime));
    for(int i=2;i*i<=n;i++)//move from 2 to number whose square is less than =n for ex in case of 50 we move from 2 to 7 as 7sq is 49
        if(prime[i]==true)//check if number in array is marked or not and skip if it marked
            for(int j=i*i;j<=n;j+=i) //mark all the elements starting from isquare to i's multiples until n
                prime[j]=false;

    for(int k=2;k<=n;k++)//n is 50 
        if(prime[k]==true)
            printf("%d ",k);
}

int main()
{
    int n;
    puts("Enter the number upto which you want the prime numbers");
    scanf("%d",&n);
    generate_series(n);
    
    return 0;
}