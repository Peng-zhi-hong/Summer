/*��Ŀ������һ������candies��һ������extraCandies������candies[i]����� i ������ӵ�е��ǹ���Ŀ��
��ÿһ�����ӣ�����Ƿ����һ�ַ������������extraCandies���ǹ������������֮�󣬴˺����� ����
�ǹ���ע�⣬�����ж������ͬʱӵ�������ǹ���Ŀ��*/

/*˼·������Ƕ�ף�����	for(i = 0;i < size;i++)��count����������ÿ��Ҫ��0������ 
candies[i]+extraCandies) >= candies[j]��ÿ�ζ�Ҫ�ж�count�Ƿ�������鳤�ȣ��Ǿ�
���һ��True��������һ��False��*/

#include<stdio.h>
int main()
{
	int candies[6] = {2,3,4,1,4,2};
	int extraCandies,i,j,count;
	int size = sizeof(candies)/sizeof(candies[0]);
	printf("���������ǹ�����");
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

