/*��Ŀ��ʵ��strStr()������
����һ��haystack �ַ�����һ�� needle �ַ������� haystack 
�ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� (��0��ʼ)����
�������ڣ��򷵻� -1��*/
 
/*˼·������memcmp�Ƚϣ���� memcmp(&haystack[i], needle, n_l) == 0,˵����haystack�д���
needle�ַ�����i����needle�ַ������ֵĵ�һ��λ�ã�����ͷ���-1�������ڡ�*/ 

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
	printf("������"); 
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

 

