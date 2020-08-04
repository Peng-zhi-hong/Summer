/*题目：实现strStr()函数。
给定一个haystack 字符串和一个 needle 字符串，在 haystack 
字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如
果不存在，则返回 -1。*/
 
/*思路：运用memcmp比较，如果 memcmp(&haystack[i], needle, n_l) == 0,说明在haystack中存在
needle字符串，i即是needle字符串出现的第一个位置，否则就返回-1，不存在。*/ 

#include<stdio.h>
#include<string.h> 
int strStr(char * haystack, char * needle);
int main()
{
	char haystack[20];
	char needle[10];
	gets(haystack);
	gets(needle);
	int index = strStr(haystack,needle);
	if(index != -1)
	printf("index = %d",index);
    else
	printf("不存在"); 
}

int strStr(char * haystack, char * needle){
    int i;
    int n_l = strlen(needle);
    int h_l = strlen(haystack);
    
    if(NULL == haystack || NULL == needle || 0 == n_l)
        return 0;

    for(i = 0; (i + n_l) <= h_l ; i++)
    {
        if(0 == memcmp(&haystack[i], needle, n_l))
        {
            return i;
        }
    }

    return -1;
}

 

