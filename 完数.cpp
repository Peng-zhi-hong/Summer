/*题目:一个数如果恰好等于它的因子之和，这个数就称为“完数”。例如6 = 1+2+3 找出10000以内的所有完数。*/
/*思路：完数：某自然数除它本身以外的所有因子之和等于该数，则该数被称为完数。*/
#include<stdio.h>
int main(){
	
	int p[80];  //保存分解的因子
	int i,num,count,s,c = 0;
    long int MaxNum = 1000000000; 
 
	for(num = 2; num < MaxNum; num++)
	{
		count = 0;
		s = num;
		for(i = 1; i < num/2+1; i++)      //循环处理每个数
		{
			if(num % i == 0)          //能被i整除
			{
				p[count++]  = i;      //保存因子，让计数器count增加1
				s -= i;               //减去一个因子
			}
		}
		if( 0 == s)
		{
			printf("%d是一个完数，因子是：",num);
			printf("%d = %d",num,p[0]);  //输出完数
			for(i = 1; i < count; i++)
				printf("+%d",p[i]);
			printf("\n");
			c++;
		}
	}
	printf("\n共找到%d个完数。\n",c);
}
