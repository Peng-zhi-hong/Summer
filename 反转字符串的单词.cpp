//��Ŀ������һ���ַ���������Ҫ��ת�ַ�����ÿ�����ʵ��ַ�˳��ͬʱ�Ա����ո�͵��ʵĳ�ʼ˳��

/*˼·������������ַ�������ͷ��β��������������ո����'\0'���͵���reverse����������ʹ����
��ת����ת��ɺ�puts����*/ 

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

