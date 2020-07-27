/*题目：给定N个人的出生年份和死亡年份，第i个人的出生年份为birth[i]，死亡年份为death[i]，
实现一个方法以计算生存人数最多的年份。你可以假设所有人都出生于1900年至2000年（含1900和
2000）之间。如果一个人在某一年的任意时期都处于生存状态，那么他们应该被纳入那一年的统计
中。例如，生于1908年、死于1909年的人应当被列入1908年和1909年的计数。如果有多个年份生存
人数相同且均为最大值，输出其中最小的年份。*/

/*思路：定义一个year的动态数组，保存1900~2000之间人数的增减变化，然后从头开始累加，找出最大值，输出该年。*/ 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define BASE_YEAR   1900
#define MAX_LEN     102
int maxAliveYear(int* birth, int birthSize, int* death);
//【算法思路】差分问题。注意死亡年份减人，在第二年。
int main()
{
int birth[5] = {1900,1999,1930,1919,1945};
int death[5] = {1960,2000,1980,1960,1980};
int birthSize = sizeof(birth)/sizeof(birth[0]);
int max_year;
max_year = maxAliveYear(birth,  birthSize, death);
printf("存活人数最多的年 = %d年",max_year);

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

