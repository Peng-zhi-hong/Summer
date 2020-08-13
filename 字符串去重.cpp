/*题目:输入一个字符串，重复元素只保留一个，然后输出*/
/*思路，把输入的字符串不同的元素保留在一个新字符中*/ 
#include<iostream>
#include<cstring> 
using namespace std;
int main(){
    string s1;
    cin>>s1;
    string s2;
    for(size_t i=0;i<s1.size();i++){
        size_t j=0;
        for(;j<s2.size();j++){//
            if(s2[j]==s1[i]){//找到有重复的
                break;
            }
        }
        if(j==s2.size()){//看循环是否正常结束判断s2中是否含s1[i]
            s2+=s1[i];
        }
    }
    cout<<s2<<endl;
    system("pause");
    return 0;
}
