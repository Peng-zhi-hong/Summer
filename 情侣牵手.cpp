/*题目：N 对情侣坐在连续排列的 2N 个座位上，想要牵到对方的手。 计算最少交换座位的次数，
以便每对情侣可以并肩坐在一起。 一次交换可选择任意两人，让他们站起来交换座位。
人和座位用0到2N-1的整数表示，情侣们按顺序编号，第一对是(0, 1)，第二对是(2, 3)，
以此类推，最后一对是(2N-2, 2N-1)。这些情侣的初始座位row[i]是由最初始坐在第 
i 个座位上的人决定的*/
/*思路：从第一个人开始判断其下一个人是不是他的情侣，是就continue跳过，不是就在
其后面的人里找其情侣，找到后交换其后面一人与其情侣的座位，计数器ans+1，接着跳到
第三个人，判断第四个人，依次类推，直到最后一个人为止。*/ 

#include<stdio.h> 
int minSwapsCouples(int row[],int length) {
        int ans = 0;
        for (int i = 0; i < length; i += 2) {
            int x = row[i];
            if (row[i+1] == (x ^ 1)) continue;
            ans++;
            for (int j = i+2; j < length; ++j) {
                if (row[j] == (x^1)) {
                    row[j] = row[i+1];
                    row[i+1] = x^1;
                    break;
                }
            }
        }
        return ans;
    }
int main()
{
	int row[] = {0,2,4,3,1,5};
	int length = sizeof(row)/sizeof(row[0]);
	int min = minSwapsCouples(row,length); 
	printf("最少交换座位的次数:%d",min);
}


