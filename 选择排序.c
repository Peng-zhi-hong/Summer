#include<stdio.h>
void swap (int arr[] ,int min,int i);
void selectSort(int arr[],int len) {
	int i,j; 
        for ( i = 0; i < len - 1; i++) {
            int min = i;//每一趟循环比较时，min用于存放较小元素的数组下标，这样当前批次比较完毕最终存放的就是此趟内最小的元素的下标，避免每次遇到较小元素都要进行交换。
            for ( j = i + 1; j < len; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            //进行交换，如果min发生变化，则进行交换
            if (min != i) {
                swap(arr,min,i);
            }
        }
    } 
void swap (int arr[] ,int min,int i){
		int temp;
		temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp; 
}    
 int main(){
	int arr[] = {1,4,2,5,6};
	int i;
	int len = sizeof(arr)/sizeof(arr[0]); 
selectSort(arr, len) ;
	for ( i = 0; i < len; i++)
	printf("%d",arr[i]);
}     
