/*˼·:����һ�����������鵱����Ͱ�ӡ�Ѱ�����У����Ұ���Ŀһ��һ���ŵ���Ӧ��Ͱ��ȥ��
�����Ӳ��ǿյ�Ͱ�������ȡ�� */
#include<stdio.h>
// ��ӡ���
void Show(int  arr[], int n)
{
    int i;
    for ( i=0; i<n; i++ )
        printf("%d  ", arr[i]);
    printf("\n");
}
 
//���δ��������������һ��Ԫ��ֵ
int GettmpArrLen ( int arr[], int len)
{
    
    int maxVal = arr[0]; //�������Ϊarr[0]
 
    
    for(int i = 1; i < len; i++)  //�����Ƚϣ��ҵ���ľ͸�ֵ��maxVal
    {
        if(arr[i] > maxVal)
            maxVal = arr[i];
      
    }
    
    return maxVal ;  //�������ֵ
}
 
//Ͱ����
void BucketSort(int arr[] , int len)
{
    int tmpArrLen = GettmpArrLen (arr , len) + 1;
    int tmpArr[tmpArrLen];  //��ÿ�Ͱ��С
    int i, j;

    for( i = 0; i < tmpArrLen; i++)  //��Ͱ��ʼ��
        tmpArr[i] = 0;
    
    for(i = 0; i < len; i++)   //Ѱ�����У����Ұ���Ŀһ��һ���ŵ���Ӧ��Ͱ��ȥ��
        tmpArr[ arr[i] ]++;
    
    for(i = 0, j = 0; i < tmpArrLen; i ++)
    {
        while( tmpArr[ i ] != 0) //��ÿ�����ǿյ�Ͱ�ӽ�������
        {
            arr[j ] = i;  //�Ӳ��ǿյ�Ͱ�����Ԫ���ٷŻ�ԭ���������С�
            j++;
            tmpArr[i]--;
        }
    }
}
 
int main()
{   //��������
    int arr_test[] = {45,2,1,14,13,45,63,76,567,576,5756,3};
    int Max_len = sizeof(arr_test)/sizeof(arr_test[0]); 
    //����ǰ��������
    Show( arr_test, Max_len );
    //����
    BucketSort( arr_test,  Max_len);
    //�������������
    Show( arr_test, Max_len );
    
    return 0;
}

