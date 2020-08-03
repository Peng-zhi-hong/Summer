/*题目：藏头诗，提取每句诗句的第一个字，然后组成新的字符串输出 。*/
/*思路：一个汉字两个字符长度，所以一个字要占字符数组mean两个字符的长度，提取完输出即可。*/ 

#include<stdio.h>

int main()
{
	int i;
	char poem[4][20]={"我自依依望远游","喜君莫名觉轻愁","欢意足枕独思远","你影如风浮心头"};
	char mean[20];
	for(i=0;i<4;i++)
	{
		mean[2*i]   =  poem[i][0];
		mean[2*i+1] = poem[i][1]; 
	}

	mean[2*i]='\0';
 
	printf("%s\n",mean);
	return 0;
}
