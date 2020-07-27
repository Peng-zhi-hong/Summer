/*��Ŀ������N���˵ĳ�����ݺ�������ݣ���i���˵ĳ������Ϊbirth[i]���������Ϊdeath[i]��
ʵ��һ�������Լ�����������������ݡ�����Լ��������˶�������1900����2000�꣨��1900��
2000��֮�䡣���һ������ĳһ�������ʱ�ڶ���������״̬����ô����Ӧ�ñ�������һ���ͳ��
�С����磬����1908�ꡢ����1909�����Ӧ��������1908���1909��ļ���������ж���������
������ͬ�Ҿ�Ϊ���ֵ�����������С����ݡ�*/

/*˼·������һ��year�Ķ�̬���飬����1900~2000֮�������������仯��Ȼ���ͷ��ʼ�ۼӣ��ҳ����ֵ��������ꡣ*/ 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define BASE_YEAR   1900
#define MAX_LEN     102
int maxAliveYear(int* birth, int birthSize, int* death);
//���㷨˼·��������⡣ע��������ݼ��ˣ��ڵڶ��ꡣ
int main()
{
int birth[5] = {1900,1999,1930,1919,1945};
int death[5] = {1960,2000,1980,1960,1980};
int birthSize = sizeof(birth)/sizeof(birth[0]);
int max_year;
max_year = maxAliveYear(birth,  birthSize, death);
printf("������������� = %d��",max_year);

}
int maxAliveYear(int* birth, int birthSize, int* death){
    int *years = (int *)calloc(MAX_LEN, sizeof(int));

    for(int i = 0; i < birthSize; i++) {
        years[birth[i] - BASE_YEAR]++;
        years[death[i] - BASE_YEAR + 1]--;
    }

    int sum = 0;
    int max = 0;
    int max_year;
    for(int i = 0; i < MAX_LEN; i++) {
        sum += years[i];

        if(sum > max) {
            max = sum;
            max_year  = i + BASE_YEAR;
        }
    }

    return max_year;
}

