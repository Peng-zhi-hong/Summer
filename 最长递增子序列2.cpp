/*题目：给定一个长度为N的数组，找出一个最长的单调自增子序列（不一定连续，但
是顺序不能乱）。例如：给定一个长度为6的数组A{5， 6， 7， 1， 2， 8}，
则其最长的单调递增子序列为{5，6，7，8}，长度为4.*/
//动态规划 
#include <iostream>  
using namespace std;  
#define len(a) (sizeof(a) / sizeof(a[0])) //数组长度  
int lis(int arr[], int len)  
{  
    int longest[len];  
    for (int i=0; i<len; i++)  
        longest[i] = 1;  
  
    for (int j=1; j<len; j++) {  
        for (int i=0; i<j; i++) {  
            if (arr[j]>arr[i] && longest[j]<longest[i]+1){ //注意longest[j]<longest[i]+1这个条件，不能省略。  
                longest[j] = longest[i] + 1; //计算以arr[j]结尾的序列的最长递增子序列长度  
            }  
        }  
    }  
  
    int max = 0;  
    for (int j=0; j<len; j++) {  
        cout << "longest[" << j << "]=" << longest[j] << endl;  
        if (longest[j] > max) max = longest[j];  //从longest[j]中找出最大值  
    }  
    return max;  
}  
  
int main()  
{  
    int arr[] = {1, 4, 5, 6, 2, 3, 8}; //测试数组  
    int ret = lis(arr, len(arr));  
    cout << "max increment substring len=" << ret << endl;  
    return 0;  
}  

