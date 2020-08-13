#include<stdio.h>
void swap (int arr[6] ,int j);          
int main(){
	int arr[6] = {1,3,4,2,4,2};
	int len = sizeof(arr)/sizeof(arr[0]);
    int i,j,temp;  
    for (i = 0; i < len - 1; i++)          //外层循环控制趟数，总趟数为len-1
        for (j = 0; j < len - 1 - i; j++)  //内层循环为当前i趟数 所需要比较的次数
            if (arr[j] > arr[j + 1]) 
            swap(arr,j);
	for (i = 0; i < len - 1; i++)
	{
		printf("%d",arr[i]);
		}	}
                
void swap (int arr[6] ,int j){
int temp;
temp = arr[j];
arr[j] = arr[j+1];
arr[j+1] = temp; 
}         

