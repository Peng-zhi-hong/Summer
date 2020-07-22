/*题目：给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。*/

//思路：从后向前(从个位)开始+1,逢九进一,不为九时结束,全为九时数组长度加一，变为首位为1，其余为0 

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


