//��Ŀ������һ���������� arr���������Ƿ������������ N �� M������ N �� M ������������N = 2 * M����
//˼·������ѭ��Ƕ�ף�������Ϊ�㣬����ȥ,����Ϊ2���� arr[i]/arr[j] == 2 && arr[i]%arr[j] == 0�� 
#include<stdio.h>
int main()
{   int i,j;
    int flag = 0;
	int arr[5]={1,0,2,5,9};
	for( i = 0; i < 5;i++)
	for( j = 0; j < 5;j++)
	{
	if(arr[j] == 0)
	  continue;
	  if(arr[i]/arr[j] == 2 && arr[i]%arr[j] == 0)
	   flag = 1;
	   }
	if(flag)
	printf("True");
	else
	printf("False");
}
