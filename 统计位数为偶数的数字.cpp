//题目：给你一个整数数组 nums，请你返回其中位数为 偶数 的数字的个数。

/*思路：定义一个判断是非位数为偶的函数IsEven( ),遍历数组nums，并调用IsEven( )判断
是否位数为偶数，是就s+1,最后返回s（统计数）。 */
#include<stdio.h>
int IsEven(int n);
int main()
{
	int nums[10] = {1,23,43,2,1,4,41,43,123,4353234};
	int n,s = 0;
	for(int i = 0;i < sizeof(nums)/sizeof(nums[0]);i++)
	{
		n = nums[i];
		if(IsEven(n))
		s++;
		else
		s = s;
	 } 
	printf("位数为偶数的数字的个数 = %d",s);
}
int IsEven(int n)
{
	int count = 0;
	while(n)
	{
		n/=10;
		count++;
		
	}
	if(count%2 == 0)
	return 1;
	else
	return 0;
	
}
