//�ݹ��㷨 
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<math.h>
using namespace std;
int n,i;//n��¼�Ƕ��ٸ��ʺ�����⣬i��¼���ǵڼ����ʺ� 
int a[101];//�����±��ʾ�кţ�����ֵ��ʾ�к� 
int sum;//��¼�ж����ֽⷨ 
bool judge(int a[],int N) //��⵱ǰλ�õĻʺ��Ƿ��ǺϷ��� 
{  
    for(int j=1;j<N;j++)  
    {  
        if(abs(a[j]-a[N])==abs(j-N) || a[j]==a[N])//������ע��  
            return false;  
    }  
    return true;  
}  
void print_ans(){//��ӡ���ÿһ�ֽ�ķ����� 
    for(int j=1;j<=n;j++)
        cout<<"��:"<<j<<",��:"<<a[j]<<"   ";
        cout<<endl; 
} 
void solve(int i){//ʹ�øú�����ʵ�ֵݹ���˻ʺ�Ϸ���
    if(i>n){//�ݹ���ڣ�ÿ����һ�Σ���ζ�ŵõ���һ�ֽ� 
        sum++; 
        cout<<"�ŷ�"<< sum <<":"; 
        print_ans();//����𰸣� 
        return ;
    } 
    for(int j=1;j<=n;j++){//ÿһ��8�ж�������һ�� 
        a[i]=j;
        if(judge(a,i)){//�жϵ�ǰ�ʺ��Ƿ�����Ҫ��������ݹ�����һ�� 
            solve(i+1);
        }            
    }
}
int main(){
    cin>>n;
    sum=0; 
    solve(1);//
    cout<<"һ���ж�����⣺"<<sum; 
}
