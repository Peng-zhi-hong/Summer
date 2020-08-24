/*思路：
(1)遍历序列找出最大的数(为的是确定最大的数是几位数)；

(2)开辟一个与数组大小相同的临时数组tmp；

(3)用一个count数组统计原数组中某一位(从低位向高位统计)相同的数据出现的次数；

(4)用一个start数组计算原数组中某一位(从最低位向最高位计算)相同数据出现的位置；

(5)将桶中数据从小到大用tmp数组收集起来；

(6)重复(3)(4)(5)直到所有位都被统计并计算过，用tmp收集起来；

(7)将tmp数组拷回到原数组中；
*/
#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;

int GetMaxDigit(int* arr, size_t n)
{
	assert(arr);
	int digit = 1;
	int base = 10;
	for (size_t i = 0; i < n; i++)
	{
		while (arr[i] >= base)
		{
			++digit;
			base *= 10;
		}
	}
	return digit;
}
 
void LSDSort(int* arr,size_t n)
{
	assert(arr);
	int base = 1;
	int digit = GetMaxDigit(arr, n);
	int* tmp = new int[n];
	while (digit--)
	{
		int count[10] = { 0 };
		//统计某一位出现相同数字的个数
		for (size_t i = 0; i < n; i++)
		{
			int index = arr[i] / base % 10;
			count[index]++;
		}
		int start[10] = { 0 };
		//统计个位相同的数在数组arr中出现的位置
		for (size_t i = 1; i < n; i++)
		{
			start[i] = count[i - 1] + start[i - 1];
		}
		//初始化tmp数组
		memset(tmp, 0, n*sizeof(int));
		//从桶中重新排序数据
		for (size_t i = 0; i < n; ++i)
		{
			int index = arr[i] / base % 10;
			tmp[start[index]++] = arr[i];
		}
		//将tmp数组中的元素拷回原数组
		memcpy(arr, tmp, n*sizeof(int));
		base *= 10;
	}
	delete[] tmp;
}
void Print(int* arr, size_t n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int main()
{
	int arr[] = {2342,342,342, 543, 324, 568, 975, 547, 672, 783, 239 };
	LSDSort(arr, sizeof(arr) / sizeof(arr[0]));
	Print(arr, sizeof(arr) / sizeof(arr[0]));
}


