/*题目：给定一个非空数组，返回此数组中第三大的数。如果不存在，则返回数组中最大的数。*/

/*思路：从大到小排序，如果数组长度size大于等于三，返回nums[2]，否则返回nums[0]*/
#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b) ; 
int main()
{
	int nums[2] = {0,5};
	int size = sizeof(nums)/sizeof(nums[0]);
	qsort(nums,size,sizeof(nums[0]),cmp);
	if(size >= 3)
	printf("第三大的数 = %d",nums[2]);
	else
	printf("最大的数 = %d",nums[0]);
 }
 int cmp ( const void *a , const void *b )
{
  return *(int *)b - *(int *)a;  //降序排序
  }
