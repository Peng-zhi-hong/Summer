//��Ŀ������һ���������� nums�����㷵������λ��Ϊ ż�� �����ֵĸ�����

/*˼·������һ���ж��Ƿ�λ��Ϊż�ĺ���IsEven( ),��������nums��������IsEven( )�ж�
�Ƿ�λ��Ϊż�����Ǿ�s+1,��󷵻�s��ͳ�������� */
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
	printf("λ��Ϊż�������ֵĸ��� = %d",s);
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
