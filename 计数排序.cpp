/*思路:
（1）找出待排序的数组中最大和最小的元素
（2）统计数组中每个值为i的元素出现的次数，存入数组C的第i项
（3）对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）
（4）反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1*/
/*局限性:
1.当数列最大最小值差距过大时，并不适用于计数排序
比如给定20个随机整数，范围在0到1亿之间，此时如果使用计数排序的话，就需要创建长度为1亿的数组，不但严重浪费了空间，而且时间复杂度也随之升高。
2.当数列元素不是整数时，并不适用于计数排序
如果数列中的元素都是小数，比如3.1415，或是0.00000001这样子，则无法创建对应的统计数组，这样显然无法进行计数排序。
正是由于这两大局限性，才使得计数排序不像快速排序、归并排序那样被人们广泛适用。*/
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
