/*��Ŀ:����һ���ַ��� s ��һ�� ������ͬ ���������� indices ��������������
�ַ��� s �����е� i ���ַ���Ҫ�ƶ��� indices[i] ָʾ��λ�á�������
�����к���ַ�����*/
#include<vector>
#include<iostream>
#include<cstring>
using namespace std;
string restoreString(string s, vector<int>& indices);
int main(){
	int a[11] = {2,1,4,3,0,6,5,9,8,7,10}; 
	vector<int>indices(a,a+11);	
	string s = "hello world";
	string str = restoreString(s, indices);
	cout<<str;
}
string restoreString(string s, vector<int>& indices) {
        int length = s.length();
        string result(length, 0);
        for(int i = 0; i < length; i++) {
            result[indices[i]] = s[i];
        }
        return result;
    }


