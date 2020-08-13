#include<iostream>
#include<cstring>
using namespace std;
int main(){
string s2;
cin>>s2;
int len1 = s2.size();
char ch;
  for (int i = 0; i < len1 - 1; i++)          //外层循环控制趟数，总趟数为len-1
        for (int j = 0; j < len1 - 1 - i; j++)  //内层循环为当前i趟数 所需要比较的次数
            if (s2[j] > s2[j + 1])  
                {
                	ch = s2[j];
                	s2[j] = s2[j+1];
                	s2[j+1] = ch;
			
				}
				cout<<s2;
			}
				
