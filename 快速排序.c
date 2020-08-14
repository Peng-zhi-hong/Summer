/*˼·��1���ȴӶ�β��ʼ��ǰɨ���ҵ�low < highʱ,���a[high] > tmp,��high�C,����
��a[high] < tmp,��high��ֵ��ֵ��low,��arr[low] = a[high],ͬʱҪת��
����ɨ��ķ�ʽ,����Ҫ�Ӷ��׿�ʼ���β����ɨ����
2��ͬ��,���Ӷ��׿�ʼ���β����ɨ��ʱ,���a[low] < tmp,��low++,�����
a[low] > tmp��,�����Ҫ��lowλ�õ�ֵ��ֵ��highλ��,��arr[low] = arr[high],
ͬʱ������ɨ�跽ʽ��Ϊ�ɶ�β����׽���ɨ��.
3�������ظ��ٺ͢�,ֱ��low>=highʱ(��ʵ��low=high),low��high��λ�þ���
�û�׼�����������е���ȷ����λ��.*/
#include<stdio.h>
void quickSort(int arr[], int low, int high);
int getIndex(int arr[], int low, int high);
int main() {
	int i,n;
	int a[20];
    //��������
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
    quickSort(a , 0, n-1); //�����������
    //��������Ľ��
    for(i = 0; i < n; i++)
    	printf("%d ", a[i]);
//    printf("%d\n", a[n]);
    return 0;
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
