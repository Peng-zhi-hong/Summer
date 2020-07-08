#include<stdio.h>
int gcd(int a,int b)
{
	return b ? gcd(b,a%b) : a;
	
}
int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	      printf("×î´ó¹«Ô¼Êý = %d\n",a>b?gcd(a,b):gcd(b,a));
	return 0;
} 

/*思路：

第一步：令c为a和b的最大公约数，数学符号表示为c=gcd(a,b).因为任何两个整数的最大公约数c一定是存在的，也就是说必然存在两个数k1,k2使得a=k1*c, b=k2*c

第二步：a mod (b)等价于存在整数r,k3使得余数r=a – k3.b.

             即r = a – k3.b

            = k1.c – k3.k2.c

            = (k1 – k3.k2).c

        显然，a和b的余数r是最大公因数c的倍数。*/
