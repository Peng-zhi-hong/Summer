/*题目：梅森数（Mersenne Prime）指的是形如2n-1的正整数，其中指数n是素数，
即为Mn。如果一个梅森数是素数，则称其为梅森素数。例如22-1=3、23-1
=7都是梅森素数。*/

#include <math.h>
#include <stdio.h>
int prime(long long n)
{
    int i;
    long k;
    k=sqrt(n)+1;
    for(i=2; i<=k; i++)
        if(n%i == 0)
            return 0;
    return 1;
}
int main()
{
    int n=0, i;
    long long mp;
    printf("Mersenne Prime:\n");
    for(i=2; i<=100; i++)
    {
        mp=pow(2,i)-1;
        if(mp < 0)return 0;
        if( prime(mp) )
        {
            n++;
            printf("M(%d)=%lld", i, mp);
            printf("\n");
        }
    }
    printf("the number of Mersenne Prime less than 20 is:%d\n", n);
   
    return 0;
}
