//题目：给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积。
//思路：先排序，按照从大到小排列，最大乘积就是 nums[0]*nums[1]*nums[2] 
#include<stdio.h>
int main()
{
	int nums[10] = {1,2,3,4,5,6,7,8,9,10};
	int numsize = sizeof(nums)/sizeof(nums[0]); 
	int i,j,t,max;
	for( i = 0;i < numsize-1;i++)
	for( j = 0;j < (numsize-1-i);j++)
	if(nums[j]<nums[j+1]){
	t = nums[j];
	nums[j] = nums[j+1];
	nums[j+1] = t;
	}
	max = nums[0]*nums[1]*nums[2];
	printf("最大乘积 = %d",max);
}
