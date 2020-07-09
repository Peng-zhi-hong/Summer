//µ›πÈÀ„∑®
#include<stdio.h> 
long long int fun (long long int a,long long int b,long long int c);
 
int main(void)
{
    long long int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        printf("%lld\n",fun(a,b,c));
    return 0;
}
 
long long int fun(long long int a,long long int b,long long int c)
{
    long long int ans;
    ans = 1;
    if (b == 0) return 1 % c;
    if (b == 1) return a % c;
    ans = fun(a,b/2,c);
    ans = ans * ans % c;
    if (b % 2 == 1) ans = ans * a % c;
    return ans;
}
//—≠ª∑À„∑®£∫
#include <stdio.h>
int fun(long long int a,long long int b,long long int c);
int main(void)
{
	long long int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
	     printf("%d\n",fun(a,b,c));

	return 0;
}
 
int fun(long long int a,long long int b,long long int c)
{
	int ans = 1;
	a = a % c;
	while (b > 0)
	{
		if (b % 2 == 1)
		  ans =ans * a % c;
	    a =a * a % c;
    	b /= 2;
	}
	return ans;
}


