//题目：输入一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

/*思路：对于输入的字符串，从头到尾遍历，如果遇到空格或者'\0'，就调用reverse（）函数，使单词
反转，反转完成后puts（）*/ 

#include<stdio.h>
#include<string.h>
void reverse(char *str, int i, int j);
 char * reverseWords(char * s);
int main(){
	char s[10];
	gets(s);
	puts(reverseWords(s));
}
void reverse(char *str, int i, int j)
{
    char temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

char * reverseWords(char * s)
{   int k=0;
    int left = 0;
    int right = 0;
    while (s[right++] != '\0') {
    	
		 if (s[right] == ' ' || s[right] == '\0') {
		 
            reverse(s, left, right - 1);
            left = right + 1;
        }
    }
    return s;
}

