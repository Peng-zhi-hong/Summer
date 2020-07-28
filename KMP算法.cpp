#include<bits/stdc++.h>
#define MAXN 9999
using namespace std;
string str1,str2;//str1为总的字符串  str2为匹配的字符串
int next[MAXN];//next[i]代表str2字符串i位置之前的最长前缀
void getnextarray()//这个函数是求next数组的
{
 if(str2.size()==1)//匹配的字符串只有一个字符
 {
 next[0]=-1;//我们人为规定next[0]为-1,next[1]为0
 next[1]=0;
 return ;
 }
 next[0]=-1;
 next[1]=0;
 int i=2;//i代表填充next数组的i位置（str2字符串i位置前面的字符串的最长前缀）
 int cn=0;//cn始终代表str2字符串i-1位置前面的字符串的最长前缀的下一个字符的位置
 while (i<str2.size())
 {
 if(str2[i-1]==str2[cn])/*如果str2字符串i-1位置上的字符等于str2字
 符串cn位置上的字符的话，直接在next[i]的基础上加1即可*/
 next[i++]=++cn;
 else if(cn>0)//这个条件满足，说明可以往前跳，让cn往前跳
 cn=next[cn];
 else
 next[i++]=0;//str2字符串i位置前面的字符串没有前缀
 }
}
int kmp()//kmp算法，如果匹配成功，返回1，否则，返回0
{
 int s1=0,s2=0;//这是两个指针，s1刚开始指向str1字符串的第一个字符，s2刚开始指向str2字符串的第一个字符
 while (s1<str1.size()&&s2<str2.size())//两个指针都没有到达最后一个字符时，执行下面过程
 {
if(str1[s1]==str2[s2])//str1字符串s1位置上的字符和str2字符串s2位置上的字符相等
 {
 s1++;//让两个指针都往后移动一位
 s2++;
 }
 else if(next[s2]==-1)/*如果程序运行到这里，说明上面的条件不满足，str1字符串s1位置上
 的字符和str2字符串s2位置上的字符不相等，如果这个条件满足，说明str1字符串第一个字符就
 不和str2字符串匹配，让s1往后移动一个位置*/
 s1++;
 else
 s2=next[s2];//这是语句是kmp算法的核心内容，也是kmp算法为什么快的原因
 }

  if(s2==str2.size())//这个条件如果满足，说明str2字符串都已经匹配完了，并且匹配成功了，返回1
    return 1;
  else
    return 0;
}
int main()
{
  cin>>str1>>str2;
  getnextarray();
  if(kmp())
    cout<<"匹配成功"<<endl;
  else
    cout<<"匹配失败"<<endl;
}


