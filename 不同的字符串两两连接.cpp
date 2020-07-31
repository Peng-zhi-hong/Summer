/*题目：输入一些不同的字符串，两两连接（不能一样），并输出连接后的字符串及其字符串长度*/
/*思路：先把输入的n字符复制到一个新的字符数组里，每个字符复制n-1遍，然后再遍历把不同的两
字符串连接在一起，最后输出 连接后的字符串及其字符串长度*/ 
#include<stdio.h>
#include<string.h>
int main()
{
			char s[3][10],b[6][10]={0};
			int i,k,n,l,p;
			int m=0;
			for(i = 0;i < 3;i++)
			gets(s[i]);
			//复制到一个新字符串 
			for(i = 0;i < 3;i++){
			for(k = 0 ;k < 2;k++){	
			strcpy(b[m++],s[i]);

	}	
}
			//将不同的字符串连接起来 
			m = 0;
			for(l= 0;l<3;l++){
			for(n = 0;n < 3;n++){
			if(n != m/2){
						strcat(b[m++],s[n]);
				 }
				
			  }
			}
for(int i = 0;i < 6;i++)
printf("b[%d] = %s strlen(b[%d]) = %d\n",i,b[i],i,strlen(b[i]));
}
