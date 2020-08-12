/*题目：给定一整型数列{a1,a2...,an}，找出连续非空子串{ax,ax+1,...,ay}，使得该子序列的和最大，其中，1<=x<=y<=n。
输入
第一行是一个整数N(N<=10)表示测试数据的组数）
每组测试数据的第一行是一个整数n表示序列中共有n个整数，随后的一行里有n个整数I(-100=<I<=100)，
表示数列中的所有元素。(0<n<=1000000)
输出
对于每组测试数据输出和最大的连续子串的和。*/
/*思路：对于每组数据加和result，保存最大值在maxresult，如果result为负置为0，返回maxresult。*/ 

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
      cout<<"请输入测试数据的组数:";
      cin>>n;
      int *groups = new int[n];
      for(int i=0;i<n;i++){
      	cout<<"请输入第"<<i<<"组测试数据的序列中共有个多少整数:" ; 
            cin>> group;
            int *num = new int[group];
            for(int j=0;j<group;j++){
            	cout<<"请输入第"<<i<< "组测试数据的序列的第"<<j<<"个整数:";
                  cin>>num[j];
            }
            groups[i] = maxSum(num,group);
            delete []num;
      }
      for(int i = 0;i<n;i++)
            cout<<"第"<<i<< "组测试数据的序列的最大的连续子串的和为"<< groups[i]<<endl;
      delete []groups;
      return -1; 
}

