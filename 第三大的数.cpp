/*��Ŀ������һ���ǿ����飬���ش������е������������������ڣ��򷵻���������������*/

/*˼·���Ӵ�С����������鳤��size���ڵ�����������nums[2]�����򷵻�nums[0]*/
#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b) ; 
int main()
{
	int nums[2] = {0,5};
	int size = sizeof(nums)/sizeof(nums[0]);
	qsort(nums,size,sizeof(nums[0]),cmp);
	if(size >= 3)
	printf("��������� = %d",nums[2]);
	else
	printf("������ = %d",nums[0]);
 }
 int cmp ( const void *a , const void *b )
{
  return *(int *)b - *(int *)a;  //��������
  }
