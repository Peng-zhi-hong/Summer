/*��Ŀ���ַ�����ת�����������ַ���s1��s2�����д������s2�Ƿ�Ϊ
s1��ת���ɣ����磬waterbottle��erbottlewat��ת����ַ�������*/

/*˼·��s1+s1,��s2��s1+s1�����ھ��ǶԵġ�*/ 
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
	printf("s2��s1��ת����") ;
	else
	printf("s2����s1��ת����");
}
