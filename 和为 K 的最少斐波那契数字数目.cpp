/*给你数字 k，请你返回和为?k?的斐波那契数字的最少数目，其中，每个斐波那契数字都可以被使用多次。

斐波那契数字定义为：
F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2， 其中 n > 2 。
数据保证对于给定的 k，一定能找到可行解。*/
/*思路：
方案中不会包含相邻的数，因为相邻的两个数可以由它们的和代替，从而构造出数目更少的方案。
也不必要包含相同的数，因为f(n)+f(n)=f(n+1)+f(n-2) (n>=2)当n<2时，有f(2)=2f(1)=2f(0)；如此可以将方案中所有相同的数都替换掉。
选取小于f(n)的不相邻且不重复的数，其最大和为f(n-1)+f(n-3)+f(n-5)...+1<=f(n)。（n为奇数时直接可以f(0)+f(2)=f(3), f(3)+f(4)=f(5), ... ,f(n-2)+f(n-1)=f(n); n为偶数时两边同时加上f(0)开始合并
因此和为k的最小子数组中一定可以包含刚好不大于k的斐波那契数。

首先找到大于于等于k的斐波那契数的最小下标 
从后往前进行遍历，如果k>=Fibon(i)，k减去它，并且计数器+1 */
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
