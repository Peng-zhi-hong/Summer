/*题目：给你一个「有效括号字符串」 seq，请你将其分成两个不相交的有效括号字符串，
A B，并使这两个字符串的深度最小。不相交：每个 seq[i] 只能分给 A 和 B 二
者中的一个，不能既属于 A 也属于 B 。
A 或 B 中的元素在原字符串中可以不连续。
A.length + B.length = seq.length
深度最小：max(depth(A), depth(B))?的可能取值最小。
划分方案用一个长度为 seq.length 的答案数组 answer 表示，编码规则如下：
answer[i] = 0，seq[i] 分给 A 。
answer[i] = 1，seq[i] 分给 B 。
如果存在多个满足要求的答案，只需返回其中任意 一个 即可。*/
/*思路：左括号 ( 的下标编号与嵌套深度的奇偶性相反，也就是说：
下标编号为奇数的 (，其嵌套深度为偶数，分配给 B；
下标编号为偶数的 (，其嵌套深度为奇数，分配给 A。
右括号 ) 的下标编号与嵌套深度的奇偶性相同，也就是说：
下标编号为奇数的 )，其嵌套深度为奇数，分配给 A；
下标编号为偶数的 )，其嵌套深度为偶数，分配给 B。

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
//法一 
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
    
//法二
//int* maxDepthAfterSplit(char * seq){
//    int sl = strlen(seq);
//    int isA = 0;
//   
//    // 分配内存
//    int * ret = (int *)malloc(sizeof(int) * sl);
//    // 开始遍历
//    for (int i = 0; i < sl; i++) {
//        // 判断与前一个相同则交换分配
//        if (i != 0 && seq[i] == seq[i - 1]) {
//            isA = 1 - isA;
//        }
//        ret[i] = isA;
//    }
//    return ret;
//}

