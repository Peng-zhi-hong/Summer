/*给你数字 k?，请你返回和为?k?的斐波那契数字的最少数目，其中，每个斐波那契数字都可以被使用多次。

斐波那契数字定义为：
F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2， 其中 n > 2 。
数据保证对于给定的 k，一定能找到可行解。*/
#include<stdio.h>
#define N 10000
int Fibon(int n);
int main()
{   int k,n,i=1;
    int count = 0;
	printf("输入k:");
	scanf("%d",&k);
	while(1)
	{
	if( k <= Fibon(i)){
		n=i;
		break;
	}
	i++;
	}
for(i = n; i>=1; i--){
	if(k >= Fibon(i)){
		k = k - Fibon(i);
		count++;
	}

}
	printf("和为k的斐波那契数字的最少数目为:%d",count);	 


}

int Fibon(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return Fibon(n - 1) + Fibon(n - 2);
	}
}
