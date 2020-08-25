/*思路:设置一个定量的数组当作空桶子。寻访序列，并且把项目一个一个放到对应的桶子去。
遍历从不是空的桶子里把项取出 */
#include<stdio.h>
// 打印结果
void Show(int  arr[], int n)
{
    int i;
    for ( i=0; i<n; i++ )
        printf("%d  ", arr[i]);
    printf("\n");
}
 
//获得未排序数组中最大的一个元素值
int GettmpArrLen ( int arr[], int len)
{
    
    int maxVal = arr[0]; //假设最大为arr[0]
 
    
    for(int i = 1; i < len; i++)  //遍历比较，找到大的就赋值给maxVal
    {
        if(arr[i] > maxVal)
            maxVal = arr[i];
      
    }
    
    return maxVal ;  //返回最大值
}
 
//桶排序
void BucketSort(int arr[] , int len)
{
    int tmpArrLen = GettmpArrLen (arr , len) + 1;
    int tmpArr[tmpArrLen];  //获得空桶大小
    int i, j;

    for( i = 0; i < tmpArrLen; i++)  //空桶初始化
        tmpArr[i] = 0;
    
    for(i = 0; i < len; i++)   //寻访序列，并且把项目一个一个放到对应的桶子去。
        tmpArr[ arr[i] ]++;
    
    for(i = 0, j = 0; i < tmpArrLen; i ++)
    {
        while( tmpArr[ i ] != 0) //对每个不是空的桶子进行排序。
        {
            arr[j ] = i;  //从不是空的桶子里把元素再放回原来的序列中。
            j++;
            tmpArr[i]--;
        }
    }
}
 
int main()
{   //测试数据
    int arr_test[] = {45,2,1,14,13,45,63,76,567,576,5756,3};
    int Max_len = sizeof(arr_test)/sizeof(arr_test[0]); 
    //排序前数组序列
    Show( arr_test, Max_len );
    //排序
    BucketSort( arr_test,  Max_len);
    //排序后数组序列
    Show( arr_test, Max_len );
    
    return 0;
}

