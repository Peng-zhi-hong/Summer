/*��Ŀ������һ��������{a1,a2...,an}���ҳ������ǿ��Ӵ�{ax,ax+1,...,ay}��ʹ�ø������еĺ�������У�1<=x<=y<=n��
����
��һ����һ������N(N<=10)��ʾ�������ݵ�������
ÿ��������ݵĵ�һ����һ������n��ʾ�����й���n������������һ������n������I(-100=<I<=100)��
��ʾ�����е�����Ԫ�ء�(0<n<=1000000)
���
����ÿ�����������������������Ӵ��ĺ͡�*/
/*˼·������ÿ�����ݼӺ�result���������ֵ��maxresult�����resultΪ����Ϊ0������maxresult��*/ 

#include <iostream>
using namespace std;

int maxSum(int *num,int size){
    int result = num[0];
    int maxResult = num[0];
    for (int i = 1; i < size; i++) {
        result += num[i];
        if (result > maxResult) {
             maxResult = result;
        }else {
           if(result < 0){
               result = 0;         
            }
        }
     }
      return maxResult;
}

int main(){
      int n,group;
      cout<<"������������ݵ�����:";
      cin>>n;
      int *groups = new int[n];
      for(int i=0;i<n;i++){
      	cout<<"�������"<<i<<"��������ݵ������й��и���������:" ; 
            cin>> group;
            int *num = new int[group];
            for(int j=0;j<group;j++){
            	cout<<"�������"<<i<< "��������ݵ����еĵ�"<<j<<"������:";
                  cin>>num[j];
            }
            groups[i] = maxSum(num,group);
            delete []num;
      }
      for(int i = 0;i<n;i++)
            cout<<"��"<<i<< "��������ݵ����е����������Ӵ��ĺ�Ϊ"<< groups[i]<<endl;
      delete []groups;
      return -1; 
}

