/*给定两个字符串形式的非负整数num1 和num2，计算它们的和。
注意：
num1 和num2 的长度都小于 5100.
num1 和num2 都只包含数字0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库，也不能直接将输入的字符串转换为整数形式。*/

/*思路:两个字符串倒序相加(注意是否进位)后再倒序输出*/ 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char num1[10];
	char num2[5];
	printf("输入数字字符串num1:");
	scanf("%s",num1);
	printf("输入数字字符串num2:");
	scanf("%s",num2);
	int l1 = strlen(num1);
    int l2 = strlen(num2);
    int len = (l1 > l2) ? l1 : l2;
    int i = l1 - 1, j = l2 - 1, k = 0, carry = 0;
    char *p = (char*)malloc(sizeof(char) * (len + 2));
    /*公共部分相加*/
    while(i >= 0 && j >= 0){
        p[k++] = (num1[i] - '0' + num2[j] - '0' + carry) % 10 + '0';
        carry = (num1[i] - '0' + num2[j] - '0' + carry) / 10;
        i--;
        j--;
    }
    /*处理较长字符串剩余长度*/
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
    /*判断最高位是否进位*/
    if(carry == 1)
        p[k++] = '1';
    /*翻转*/
    for(i = 0; i < k / 2; i++){
        char t = p[i];
        p[i] = p[k - 1 - i];
        p[k - 1 - i] = t;
    }
    p[k] = '\0';
	
printf("相加为 = %s",p);
		
}
