/*��Ŀ:����һ����������salary��������ÿ�������� Ψһ�ģ�����salary[i] �ǵ�i��Ա���Ĺ��ʡ�
���㷵��ȥ����͹��ʺ���߹����Ժ�ʣ��Ա�����ʵ�ƽ��ֵ��*/
/*˼·:���ÿ�������ȥ����ͷ��֮�����ȥƽ����*/ 
#include<stdio.h>
#include<stdio.h>
void quickSort(int arr[], int low, int high);
double average(int salary[],int len);
int getIndex(int arr[], int low, int high);
int main(){
	int salary[10] = {9000,8940,3900,2000,10000,3546,8965,1356,7653,7890};
	quickSort(salary,0,9);
	int len =sizeof(salary)/sizeof(salary[0]);
	printf("ȥ����͹��ʺ���߹����Ժ�ʣ��Ա����������:\n");
	for(int i = 1;i < len-1;i++)
	printf("%d  ",salary[i]);	
	double averages = average(salary,len);
	printf("\nʣ��Ա�����ʵ�ƽ��ֵ = %lf",averages);
} 
double average(int salary[],int len){
	double sum = 0;
	for(int i = 1;i < len-1;i++)
	 sum+=salary[i];
	return sum/(len-2);
	
}
void quickSort(int arr[], int low, int high) {

		if (low < high) {
			// ��Ѱ��׼���ݵ���ȷ����
			int index = getIndex(arr, low, high);

			// ���е�����index֮ǰ��֮������������ͬ�Ĳ���ʹ��������������
			//quickSort(arr, 0, index - 1); ֮ǰ�İ汾�����������кܴ���������⣬лл��ҵĽ���
			quickSort(arr, low, index - 1);
			quickSort(arr, index + 1, high);
		}

	}

 int getIndex(int arr[], int low, int high) {
		// ��׼����
		int tmp = arr[low];
		while (low < high) {
			// ����β��Ԫ�ش��ڵ��ڻ�׼����ʱ,��ǰŲ��highָ��
			while (low < high && arr[high] >= tmp) {
				high--;
			}
			// �����βԪ��С��tmp��,��Ҫ���丳ֵ��low
			arr[low] = arr[high];
			// ������Ԫ��С�ڵ���tmpʱ,��ǰŲ��lowָ��
			while (low < high && arr[low] <= tmp) {
				low++;
			}
			// ������Ԫ�ش���tmpʱ,��Ҫ���丳ֵ��high
			arr[high] = arr[low];

		}
		// ����ѭ��ʱlow��high���,��ʱ��low��high����tmp����ȷ����λ��
		// ��ԭ���ֿ��Ժ������֪��lowλ�õ�ֵ������tmp,������Ҫ��tmp��ֵ��arr[low]
		arr[low] = tmp;
		return low; // ����tmp����ȷλ��
	
}
