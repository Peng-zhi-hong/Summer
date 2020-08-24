/*˼·:
��1���ҳ��������������������С��Ԫ��
��2��ͳ��������ÿ��ֵΪi��Ԫ�س��ֵĴ�������������C�ĵ�i��
��3�������еļ����ۼӣ���C�еĵ�һ��Ԫ�ؿ�ʼ��ÿһ���ǰһ����ӣ�
��4���������Ŀ�����飺��ÿ��Ԫ��i����������ĵ�C(i)�ÿ��һ��Ԫ�ؾͽ�C(i)��ȥ1*/
/*������:
1.�����������Сֵ������ʱ�����������ڼ�������
�������20�������������Χ��0��1��֮�䣬��ʱ���ʹ�ü�������Ļ�������Ҫ��������Ϊ1�ڵ����飬���������˷��˿ռ䣬����ʱ�临�Ӷ�Ҳ��֮���ߡ�
2.������Ԫ�ز�������ʱ�����������ڼ�������
��������е�Ԫ�ض���С��������3.1415������0.00000001�����ӣ����޷�������Ӧ��ͳ�����飬������Ȼ�޷����м�������
������������������ԣ���ʹ�ü���������������򡢹鲢�������������ǹ㷺���á�*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_arr(int *arr, int n) {
        int i;
        printf("%d", arr[0]);
        for (i = 1; i < n; i++)
                printf(" %d", arr[i]);
        printf("\n");
}

void counting_sort(int *ini_arr, int *sorted_arr, int n) {
        int *count_arr = (int *) malloc(sizeof(int) * 100);
        int i, j, k;
        for (k = 0; k < 100; k++)
                count_arr[k] = 0;
        for (i = 0; i < n; i++)
                count_arr[ini_arr[i]]++;
        for (k = 1; k < 100; k++)
                count_arr[k] += count_arr[k - 1];
        for (j = n-1; j >= 0; j--)
                sorted_arr[--count_arr[ini_arr[j ]]] = ini_arr[j];
        free(count_arr);
}

int main(int argc, char **argv) {
        int n = 10;
        int i;
        int *arr = (int *) malloc(sizeof(int) * n);
        int *sorted_arr = (int *) malloc(sizeof(int) * n);
        srand(time(0));
        for (i = 0; i < n; i++)
                arr[i] = rand() % 100;
        printf("ini_array: ");
        print_arr(arr, n);
        counting_sort(arr, sorted_arr, n);
        printf("sorted_array: ");
        print_arr(sorted_arr, n);
        free(arr);
        free(sorted_arr);
        return 0;
}
