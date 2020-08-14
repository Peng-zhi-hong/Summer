#include<stdio.h>
void insertionSort(int arr[],int len);
void swap (int arr[] ,int j);
int main(){
	int arr[] = {1,4,2,5,6};
	int len = sizeof(arr)/sizeof(arr[0]); 
insertionSort(arr, len) ;
	for (int i = 0; i < len; i++)
	printf("%d",arr[i]);
} 
void insertionSort(int arr[],int len) {
        for (int i = 1; i < len; i++) {
            int j = i;
            while (j > 0 && arr[j] < arr[j - 1]) {
                swap(arr,j);
                j--;
            }
        }
    }
void swap (int arr[] ,int j){
		int temp;
		temp = arr[j];
		arr[j] = arr[j-1];
		arr[j-1] = temp; 
}         
