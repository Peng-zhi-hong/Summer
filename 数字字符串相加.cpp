/*���������ַ�����ʽ�ķǸ�����num1 ��num2���������ǵĺ͡�
ע�⣺
num1 ��num2 �ĳ��ȶ�С�� 5100.
num1 ��num2 ��ֻ��������0-9.
num1 ��num2 ���������κ�ǰ���㡣
�㲻��ʹ���κ΃Ƚ� BigInteger �⣬Ҳ����ֱ�ӽ�������ַ���ת��Ϊ������ʽ��*/

/*˼·:�����ַ����������(ע���Ƿ��λ)���ٵ������*/ 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char num1[10];
	char num2[5];
	printf("���������ַ���num1:");
	scanf("%s",num1);
	printf("���������ַ���num2:");
	scanf("%s",num2);
	int l1 = strlen(num1);
    int l2 = strlen(num2);
    int len = (l1 > l2) ? l1 : l2;
    int i = l1 - 1, j = l2 - 1, k = 0, carry = 0;
    char *p = (char*)malloc(sizeof(char) * (len + 2));
    /*�����������*/
    while(i >= 0 && j >= 0){
        p[k++] = (num1[i] - '0' + num2[j] - '0' + carry) % 10 + '0';
        carry = (num1[i] - '0' + num2[j] - '0' + carry) / 10;
        i--;
        j--;
    }
    /*����ϳ��ַ���ʣ�೤��*/
    while(i >= 0){
        p[k++] = (num1[i] - '0' + carry) % 10 + '0';
        carry = (num1[i] - '0' + carry ) / 10;
        i--;
    }
    while(j >= 0){
        p[k++] = (num2[j] - '0' + carry) % 10 + '0';
        carry = (num2[j] - '0' + carry ) / 10;
        j--;
    }
    /*�ж����λ�Ƿ��λ*/
    if(carry == 1)
        p[k++] = '1';
    /*��ת*/
    for(i = 0; i < k / 2; i++){
        char t = p[i];
        p[i] = p[k - 1 - i];
        p[k - 1 - i] = t;
    }
    p[k] = '\0';
	
printf("���Ϊ = %s",p);
		
}
