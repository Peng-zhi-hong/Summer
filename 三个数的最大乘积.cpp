//��Ŀ������һ���������飬���������ҳ�����������ɵ����˻������������˻���
//˼·�������򣬰��մӴ�С���У����˻����� nums[0]*nums[1]*nums[2] 
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
	printf("���˻� = %d",max);
}
