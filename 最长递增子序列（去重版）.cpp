/*��Ŀ������һ������ΪN�����飬����ȥ�أ�Ȼ���ҳ�һ����ĵ��������У���һ����������
��˳�����ң������磺����һ������Ϊ6������A{5�� 6��6,7�� 7�� 1�� 2�� 8}��
������ĵ���������Ϊ{5��6��7��8}������Ϊ4.*/
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
//�������s1ȥ�أ�������s2 
for( m=0;m<s1.size();m++){
        n=0;
    for(;n<s2.size();n++){//
        if(s2[n]==s1[m]){//�ҵ����ظ���
            break;
        }
    }
    if(n==s2.size()){//��ѭ���Ƿ����������ж�s2���Ƿ�s1[i]
        s2+=s1[m];
    }
}
int len1 = s2.size();
s3 = s2;
//��s2�������� 
char ch;
  for (i = 0; i < len1 - 1; i++)          //���ѭ������������������Ϊlen-1
        for (j = 0; j < len1 - 1 - i; j++)  //�ڲ�ѭ��Ϊ��ǰi���� ����Ҫ�ȽϵĴ���
            if (s2[j] > s2[j + 1])  
                {
                	ch = s2[j];
                	s2[j] = s2[j+1];
                	s2[j+1] = ch;
				}			
int len2 = s3.size() ;
//��̬�滮��s2,s3������������� 
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
        cout<<"����������еĳ���Ϊ��"<<c[len1][len2]<<endl;
    
}
