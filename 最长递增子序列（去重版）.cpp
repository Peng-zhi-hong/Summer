/*题目：输入一个长度为N的数组，首先去重，然后找出一个最长的递增子序列（不一定连续，但
是顺序不能乱）。例如：给定一个长度为6的数组A{5， 6，6,7， 7， 1， 2， 8}，
则其最长的递增子序列为{5，6，7，8}，长度为4.*/
#include <bits/stdc++.h>
#include <algorithm>
#include<cstring>
#include <iostream>
using namespace std;
int main()
{
  int  i, j, m,n;
 string s1,s2,s3;
  getline(cin,s1);
//对输入的s1去重，保存在s2 
for( m=0;m<s1.size();m++){
        n=0;
    for(;n<s2.size();n++){//
        if(s2[n]==s1[m]){//找到有重复的
            break;
        }
    }
    if(n==s2.size()){//看循环是否正常结束判断s2中是否含s1[i]
        s2+=s1[m];
    }
}
int len1 = s2.size();
s3 = s2;
//对s2升序排序 
char ch;
  for (i = 0; i < len1 - 1; i++)          //外层循环控制趟数，总趟数为len-1
        for (j = 0; j < len1 - 1 - i; j++)  //内层循环为当前i趟数 所需要比较的次数
            if (s2[j] > s2[j + 1])  
                {
                	ch = s2[j];
                	s2[j] = s2[j+1];
                	s2[j+1] = ch;
				}			
int len2 = s3.size() ;
//动态规划找s2,s3的最长公共子序列 
int c[len1 + 1][len2 + 1];
        for(i = 0;i <= len1;i++)
        {
            c[i][0] = 0;
        }
        for(j = 0;j <= len2;j++)
       {
            c[0][j] = 0;
        }
        for(i = 1;i <= len1;i++)
        {
            for(j = 1;j <= len2;j++)
            {
                if(s3[i-1] == s2[j-1])
                {
                    c[i][j] = c[i-1][j-1] + 1;
                  
                }
                else
                {
                    c[i][j] = max(c[i-1][j], c[i][j-1]);
                }
            }
        }
        cout<<"最长公共子序列的长度为："<<c[len1][len2]<<endl;
    
}
