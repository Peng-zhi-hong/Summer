/*题目：给定一个长度为N的数组，找出一个最长的单调自增子序列（不一定连续，但
是顺序不能乱）。例如：给定一个长度为6的数组A{5， 6， 7， 1， 2， 8}，
则其最长的单调递增子序列为{5，6，7，8}，长度为4.*/
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
#define N 10//数组元素个数  
int array[N] = {9,9,8,7,6,5,4,3,2,9}; //原数组  
int B[N]; //在动态规划中使用的数组,用于记录中间结果,其含义三言两语说不清,请参见博文的解释  
int len; //用于标示B数组中的元素个数  
  
int LIS(int *array, int n); //计算最长递增子序列的长度,计算B数组的元素,array[]循环完一遍后,B的长度len即为所求  
int BiSearch(int *b, int len, int w); //做了修改的二分搜索算法  
  
int main()  
{  
    printf("LIS: %d\n", LIS(array, N));  
  
    int i;  
    for(i=0; i<len; ++i)  
    {  
        printf("B[%d]=%d\n", i, B[i]);  
    }  
  
    return 0;  
}  
  
int LIS(int *array, int n)  
{  
    len = 1;  
    B[0] = array[0];  
    int i, pos = 0;  
  
    for(i=1; i<n; ++i)  
    {  
        if(array[i] > B[len-1]) //如果大于B中最大的元素，则直接插入到B数组末尾  
        {  
            B[len] = array[i];  
          
            ++len;  
        }  
        else  
        {  
            pos = BiSearch(B, len, array[i]); //二分查找需要插入的位置  
        
            B[pos] = array[i]; 

        }  
    }  
  
    return len;  
}  
  
//修改的二分查找算法，返回数组元素需要插入的位置。  
int BiSearch(int *b, int len, int w)  
{  
    int left = 0, right = len - 1;  
    int mid;  
    while (left <= right)  
    {  
        mid = left + (right-left)/2;  
        if (b[mid] > w)  
            right = mid - 1;  
        else if (b[mid] < w)  
            left = mid + 1;  
        else    //找到了该元素，则直接返回  
            return mid;  
    }  
    return left;//数组b中不存在该元素，则返回该元素应该插入的位置  
}  
