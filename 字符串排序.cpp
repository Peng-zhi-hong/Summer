#include<iostream>
#include<cstring>
using namespace std;
int main(){
string s2;
cin>>s2;
int len1 = s2.size();
char ch;
  for (int i = 0; i < len1 - 1; i++)          //���ѭ������������������Ϊlen-1
        for (int j = 0; j < len1 - 1 - i; j++)  //�ڲ�ѭ��Ϊ��ǰi���� ����Ҫ�ȽϵĴ���
            if (s2[j] > s2[j + 1])  
                {
                	ch = s2[j];
                	s2[j] = s2[j+1];
                	s2[j+1] = ch;
			
				}
				cout<<s2;
			}
				
