#include<bits/stdc++.h>
#define MAXN 9999
using namespace std;
string str1,str2;//str1Ϊ�ܵ��ַ���  str2Ϊƥ����ַ���
int next[MAXN];//next[i]����str2�ַ���iλ��֮ǰ���ǰ׺
void getnextarray()//�����������next�����
{
 if(str2.size()==1)//ƥ����ַ���ֻ��һ���ַ�
 {
 next[0]=-1;//������Ϊ�涨next[0]Ϊ-1,next[1]Ϊ0
 next[1]=0;
 return ;
 }
 next[0]=-1;
 next[1]=0;
 int i=2;//i�������next�����iλ�ã�str2�ַ���iλ��ǰ����ַ������ǰ׺��
 int cn=0;//cnʼ�մ���str2�ַ���i-1λ��ǰ����ַ������ǰ׺����һ���ַ���λ��
 while (i<str2.size())
 {
 if(str2[i-1]==str2[cn])/*���str2�ַ���i-1λ���ϵ��ַ�����str2��
 ����cnλ���ϵ��ַ��Ļ���ֱ����next[i]�Ļ����ϼ�1����*/
 next[i++]=++cn;
 else if(cn>0)//����������㣬˵��������ǰ������cn��ǰ��
 cn=next[cn];
 else
 next[i++]=0;//str2�ַ���iλ��ǰ����ַ���û��ǰ׺
 }
}
int kmp()//kmp�㷨�����ƥ��ɹ�������1�����򣬷���0
{
 int s1=0,s2=0;//��������ָ�룬s1�տ�ʼָ��str1�ַ����ĵ�һ���ַ���s2�տ�ʼָ��str2�ַ����ĵ�һ���ַ�
 while (s1<str1.size()&&s2<str2.size())//����ָ�붼û�е������һ���ַ�ʱ��ִ���������
 {
if(str1[s1]==str2[s2])//str1�ַ���s1λ���ϵ��ַ���str2�ַ���s2λ���ϵ��ַ����
 {
 s1++;//������ָ�붼�����ƶ�һλ
 s2++;
 }
 else if(next[s2]==-1)/*����������е����˵����������������㣬str1�ַ���s1λ����
 ���ַ���str2�ַ���s2λ���ϵ��ַ�����ȣ��������������㣬˵��str1�ַ�����һ���ַ���
 ����str2�ַ���ƥ�䣬��s1�����ƶ�һ��λ��*/
 s1++;
 else
 s2=next[s2];//���������kmp�㷨�ĺ������ݣ�Ҳ��kmp�㷨Ϊʲô���ԭ��
 }

  if(s2==str2.size())//�������������㣬˵��str2�ַ������Ѿ�ƥ�����ˣ�����ƥ��ɹ��ˣ�����1
    return 1;
  else
    return 0;
}
int main()
{
  cin>>str1>>str2;
  getnextarray();
  if(kmp())
    cout<<"ƥ��ɹ�"<<endl;
  else
    cout<<"ƥ��ʧ��"<<endl;
}


