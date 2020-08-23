/*题目:给你一个字符串 s 和一个 长度相同 的整数数组 indices 。请你重新排列
字符串 s ，其中第 i 个字符需要移动到 indices[i] 指示的位置。返回重
新排列后的字符串。*/
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


