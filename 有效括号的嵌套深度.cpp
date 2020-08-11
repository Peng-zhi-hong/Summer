/*��Ŀ������һ������Ч�����ַ����� seq�����㽫��ֳ��������ཻ����Ч�����ַ�����
A B����ʹ�������ַ����������С�����ཻ��ÿ�� seq[i] ֻ�ָܷ� A �� B ��
���е�һ�������ܼ����� A Ҳ���� B ��
A �� B �е�Ԫ����ԭ�ַ����п��Բ�������
A.length + B.length = seq.length
�����С��max(depth(A), depth(B))?�Ŀ���ȡֵ��С��
���ַ�����һ������Ϊ seq.length �Ĵ����� answer ��ʾ������������£�
answer[i] = 0��seq[i] �ָ� A ��
answer[i] = 1��seq[i] �ָ� B ��
������ڶ������Ҫ��Ĵ𰸣�ֻ�践���������� һ�� ���ɡ�*/
/*˼·�������� ( ���±�����Ƕ����ȵ���ż���෴��Ҳ����˵��
�±���Ϊ������ (����Ƕ�����Ϊż��������� B��
�±���Ϊż���� (����Ƕ�����Ϊ����������� A��
������ ) ���±�����Ƕ����ȵ���ż����ͬ��Ҳ����˵��
�±���Ϊ������ )����Ƕ�����Ϊ����������� A��
�±���Ϊż���� )����Ƕ�����Ϊż��������� B��

ans.append((i & 1) ^ (ch == '('))*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define LEN 10001
int* maxDepthAfterSplit(char * seq);
int main()
{
	int i;
	char seq[30] = "((()(()))()((()))((()))())";
	int *str;
	int *returnSize;
    str = maxDepthAfterSplit(seq);
	for(i = 0;i < strlen(seq);i++)
	  printf("%d",str[i]);
}
//��һ 
int* maxDepthAfterSplit(char * seq){
    int *ans = (int *)malloc(sizeof(int) * LEN);
    memset(ans, 0, LEN);
    int ans_id = 0;
    int depth = 1;
    for (int i = 0; i < strlen(seq); i++) {
        if (seq[i] == '(') {
          
            ans[ans_id++] = (++depth % 2);
        }
        if (seq[i] == ')') {
            ans[ans_id++] = (depth-- % 2);
        }
    }
    return ans;
}
    
//����
//int* maxDepthAfterSplit(char * seq){
//    int sl = strlen(seq);
//    int isA = 0;
//   
//    // �����ڴ�
//    int * ret = (int *)malloc(sizeof(int) * sl);
//    // ��ʼ����
//    for (int i = 0; i < sl; i++) {
//        // �ж���ǰһ����ͬ�򽻻�����
//        if (i != 0 && seq[i] == seq[i - 1]) {
//            isA = 1 - isA;
//        }
//        ret[i] = isA;
//    }
//    return ret;
//}

