/*题目:给你一个整数数组salary，数组里每个数都是 唯一的，其中salary[i] 是第i个员工的工资。
请你返回去掉最低工资和最高工资以后，剩下员工工资的平均值。*/
/*思路:运用快速排序，去掉两头，之后求和去平均。*/ 
#include<stdio.h>
#include<stdio.h>
void quickSort(int arr[], int low, int high);
double average(int salary[],int len);
int getIndex(int arr[], int low, int high);
int main(){
	int salary[10] = {9000,8940,3900,2000,10000,3546,8965,1356,7653,7890};
	quickSort(salary,0,9);
	int len =sizeof(salary)/sizeof(salary[0]);
	printf("去掉最低工资和最高工资以后，剩下员工工资如下:\n");
	for(int i = 1;i < len-1;i++)
	printf("%d  ",salary[i]);	
	double averages = average(salary,len);
	printf("\n剩下员工工资的平均值 = %lf",averages);
} 
double average(int salary[],int len){
	double sum = 0;
	for(int i = 1;i < len-1;i++)
	 sum+=salary[i];
	return sum/(len-2);
	
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
