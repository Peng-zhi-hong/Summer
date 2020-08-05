/*题目：字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为
s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。*/

/*思路：s1+s1,看s2在s1+s1中吗，在就是对的。*/ 
#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
bool isFlipedString(char* s1, char* s2){
    int len_s1=strlen(s1),len_s2=strlen(s2);
    if(len_s1!=len_s2) return false;
    char *cmp=(char*)malloc(sizeof(char)*(2*len_s1+1));
    strcpy(cmp,s1);
    strcat(cmp,s1);
    if(!strstr(cmp,s2))  return false;
    return true;
}
int main()
{
	char s1[9] = "happy";
    char s2[9] = "ppyah";
   
	if(isFlipedString(s1,s2))
	printf("s2是s1旋转而成") ;
	else
	printf("s2不是s1旋转而成");
}
