/*��Ŀ:����һ���ַ������ظ�Ԫ��ֻ����һ����Ȼ�����*/
/*˼·����������ַ�����ͬ��Ԫ�ر�����һ�����ַ���*/ 
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
            if(s2[j]==s1[i]){//�ҵ����ظ���
                break;
            }
        }
        if(j==s2.size()){//��ѭ���Ƿ����������ж�s2���Ƿ�s1[i]
            s2+=s1[i];
        }
    }
    cout<<s2<<endl;
    system("pause");
    return 0;
}
