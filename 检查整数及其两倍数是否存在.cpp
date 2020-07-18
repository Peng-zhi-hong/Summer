//题目：给你一个整数数组 arr，请你检查是否存在两个整数 N 和 M，满足 N 是 M 的两倍（即，N = 2 * M）。
//思路：二重循环嵌套，除数不为零，跳过去,整除为2即（ arr[i]/arr[j] == 2 && arr[i]%arr[j] == 0） 
#include<stdio.h>
int main()
{   int i,j;
    int flag = 0;
	int arr[5]={1,0,2,5,9};
	for( i = 0; i < 5;i++)
	for( j = 0; j < 5;j++)
	{
	if(arr[j] == 0)
	  continue;
	  if(arr[i]/arr[j] == 2 && arr[i]%arr[j] == 0)
	   flag = 1;
	   }
	if(flag)
	printf("True");
	else
	printf("False");
}
