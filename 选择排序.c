#include<stdio.h>
void swap (int arr[] ,int min,int i);
void selectSort(int arr[],int len) {
	int i,j; 
        for ( i = 0; i < len - 1; i++) {
            int min = i;//ÿһ��ѭ���Ƚ�ʱ��min���ڴ�Ž�СԪ�ص������±꣬������ǰ���αȽ�������մ�ŵľ��Ǵ�������С��Ԫ�ص��±꣬����ÿ��������СԪ�ض�Ҫ���н�����
            for ( j = i + 1; j < len; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            //���н��������min�����仯������н���
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
