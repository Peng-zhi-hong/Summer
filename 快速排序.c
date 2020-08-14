/*思路：1，先从队尾开始向前扫描且当low < high时,如果a[high] > tmp,则high–,但如
果a[high] < tmp,则将high的值赋值给low,即arr[low] = a[high],同时要转换
数组扫描的方式,即需要从队首开始向队尾进行扫描了
2，同理,当从队首开始向队尾进行扫描时,如果a[low] < tmp,则low++,但如果
a[low] > tmp了,则就需要将low位置的值赋值给high位置,即arr[low] = arr[high],
同时将数组扫描方式换为由队尾向队首进行扫描.
3，不断重复①和②,直到low>=high时(其实是low=high),low或high的位置就是
该基准数据在数组中的正确索引位置.*/
#include<stdio.h>
void quickSort(int arr[], int low, int high);
int getIndex(int arr[], int low, int high);
int main() {
	int i,n;
	int a[20];
    //读入数据
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
    quickSort(a , 0, n-1); //快速排序调用
    //输出排序后的结果
    for(i = 0; i < n; i++)
    	printf("%d ", a[i]);
//    printf("%d\n", a[n]);
    return 0;
}
void quickSort(int arr[], int low, int high) {

		if (low < high) {
			// 找寻基准数据的正确索引
			int index = getIndex(arr, low, high);

			// 进行迭代对index之前和之后的数组进行相同的操作使整个数组变成有序
			//quickSort(arr, 0, index - 1); 之前的版本，这种姿势有很大的性能问题，谢谢大家的建议
			quickSort(arr, low, index - 1);
			quickSort(arr, index + 1, high);
		}

	}

 int getIndex(int arr[], int low, int high) {
		// 基准数据
		int tmp = arr[low];
		while (low < high) {
			// 当队尾的元素大于等于基准数据时,向前挪动high指针
			while (low < high && arr[high] >= tmp) {
				high--;
			}
			// 如果队尾元素小于tmp了,需要将其赋值给low
			arr[low] = arr[high];
			// 当队首元素小于等于tmp时,向前挪动low指针
			while (low < high && arr[low] <= tmp) {
				low++;
			}
			// 当队首元素大于tmp时,需要将其赋值给high
			arr[high] = arr[low];

		}
		// 跳出循环时low和high相等,此时的low或high就是tmp的正确索引位置
		// 由原理部分可以很清楚的知道low位置的值并不是tmp,所以需要将tmp赋值给arr[low]
		arr[low] = tmp;
		return low; // 返回tmp的正确位置
	
}
