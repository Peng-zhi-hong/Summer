/*��Ŀ������һ����������ɵķǿ���������ʾ�ķǸ��������ڸ����Ļ����ϼ�һ��
���λ���ִ�����������λ�� ������ÿ��Ԫ��ֻ�洢�������֡�
����Լ���������� 0 ֮�⣬��������������㿪ͷ��*/

//˼·���Ӻ���ǰ(�Ӹ�λ)��ʼ+1,��Ž�һ,��Ϊ��ʱ����,ȫΪ��ʱ���鳤�ȼ�һ����Ϊ��λΪ1������Ϊ0 

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
int plusOne(int* digits, int digitsSize);
int main()
{
	int digits[4] = {9,7,9,9};
	int digitsSize = sizeof(digits)/sizeof(digits[0]);
    int flag =plusOne(digits,digitsSize);
    
if(flag)
	{
	int * result = (int*) malloc (sizeof(int)*(digitsSize+1));
	  
	memset(result,0,sizeof(result[0])*(digitsSize+1));
    result[0] = 1;
    for(int i = 0;i < (digitsSize+1);i++)
      printf("%d",result[i]);
}

else{
	
	for(int i = 0;i < digitsSize;i++)
	printf("%d",digits[i]);
}
}
int plusOne(int* digits,int digitsSize){
	int flag,i;
    for( i=digitsSize-1;i>=0;i--)
    {
        if(digits[i]<9)
        {
            digits[i]++;
            
           flag = 0;
           return flag;
        }
        digits[i]=0;
    }
    if(i<0)
      return 1;
    
}


