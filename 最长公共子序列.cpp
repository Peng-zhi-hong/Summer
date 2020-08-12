/*题目：给定两个序列 X={x1,x2,…,xm} 和 Y={y1,y2,…,yn}，找出X和Y的最长公共子序列。
Input
输入数据有多组，每组有两行 ，每行为一个长度不超过500的字符串（输入全是大写英文字母（A,Z），表示序列X和Y。
Output
每组输出一行，表示所求得的最长公共子序列的长度，若不存在公共子序列，则输出0。*/
/*思路：利用动态规划 ，逐个比较字符串里元素，相同则  c[i][j] = c[i-1][j-1] + 1;不同则  
c[i][j] = max(c[i-1][j], c[i][j-1]);最后输出的c[m][n]即是 最长公共子序列的长度为。*/ 
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int m, n, i, j;
  char s1[501], s2[501];

    while(1){ 
        cout<<"请输入两个字符串：";
		cin.getline(s1,500);
		cin.getline(s2,500);
        m = strlen(s1);
        n = strlen(s2);
        int c[m + 1][n + 1];
        for(i = 0;i <= m;i++)
        {
            c[i][0] = 0;
        }
        for(j = 0;j <= n;j++)
        {
            c[0][j] = 0;
        }
        for(i = 1;i <= m;i++)
        {
            for(j = 1;j <= n;j++)
            {
                if(s1[i-1] == s2[j-1])
                {
                    c[i][j] = c[i-1][j-1] + 1;
                }
                else
                {
                    c[i][j] = max(c[i-1][j], c[i][j-1]);
                }
            }
        }
        cout<<"最长公共子序列的长度为："<<c[m][n]<<endl;
    }
}
