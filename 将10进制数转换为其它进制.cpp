//��10������ת��Ϊ��������
#include<stdio.h>
void From10baseTransformTo1_32(int m,int base)
{
	char num[] = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
	char result[30] = {0};
	int len = 0;
	char temp;
	int start = 0;
	int end = len;
	
	while(m)                //շת������ȴ����������
	{
		result[len++] = num[m%base];
		m = m / base;
	}
	
    start = 0;
	end = len-1;
	while(start < end)   //�ַ�����ת
	{
		temp = result[start];
		result[start] = result[end];
		result[end] = temp;
		start++;
		end--;
	}
  
	start = 0;
	for(start = 0; start < len; start++)
    	printf("%c",result[start]);
	printf("\n");
 
}
int main()
{
	int num,base;
	scanf("%d%d",&num,&base);
	From10baseTransformTo1_32(num,base);
 } 
