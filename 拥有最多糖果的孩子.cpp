/*题目：给你一个数组candies和一个整数extraCandies，其中candies[i]代表第 i 个孩子拥有的糖果数目。
对每一个孩子，检查是否存在一种方案，将额外的extraCandies个糖果分配给孩子们之后，此孩子有 最多的
糖果。注意，允许有多个孩子同时拥有最多的糖果数目。*/

/*思路：遍历嵌套，外面	for(i = 0;i < size;i++)，count（计数器）每次要归0，里面 
candies[i]+extraCandies) >= candies[j]，每次都要判断count是否等于数组长度，是就
输出一个True，否就输出一个False。*/

#include<stdio.h>
int main()
{
	int candies[6] = {2,3,4,1,4,2};
	int extraCandies,i,j,count;
	int size = sizeof(candies)/sizeof(candies[0]);
	printf("输入额外的糖果数：");
	scanf("%d",&extraCandies);
	for(i = 0;i < size;i++){
		count=0;
	for(j = 0;j < size;j++){
	if((candies[i]+extraCandies) >= candies[j])
	      count++;
 }
 if(count == size)
 printf("True");
 else
 printf("False");}
  
 }

