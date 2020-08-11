/*题目：你总共有 n 枚硬币，你需要将它们摆成一个阶梯形状，第k行就必须正好有k枚硬币。
给定一个数字n，找出可形成完整阶梯行的总行数。n是一个非负整数，并且在32位有符号整型的范围内*/
/*思路：下限为0行，上限为n行，利用二分法，逐步找到正解。*/ 
#include<stdio.h>
int main()
{
int n;
printf("输入一共有多少枚硬币：");
scanf("%d",&n); 
    if (n == 0) {
        return 0;
    }
    int left = 0;
    // 只有 n 个硬币的情况下，最大肯定不会超过 n 行，所以这里把搜索的右侧界限定为 n
    int  right = n;
    while (left <= right) {
    	int mid = ((right + left) /2);
    
        // 形成 mid 行的阶梯一共需要 costToFinishMid 个硬币，这里是数学公式
    	int costToFinishMid = (1 + mid) * mid / 2;
    
    	if(costToFinishMid == n){
		   printf("可形成完整阶梯行的总行数 = %d",mid);
	      return 0;
			}
       else if (costToFinishMid < n) {
    		left = mid + 1;
    	} else if (costToFinishMid > n) {
    		right = mid - 1;
    	}
    }
    printf("可形成完整阶梯行的总行数 = %d",right);
    return 0;
}

/*等差数列求解：根据数学公式，k(k+1) /2 = n，可以得到其正数解为：k = sqrt(2n+1/4) - 1/2。然后求整即可。
唯一的问题是，这里2n+1/4有可能会超出sqrt函数的参数范围。
于是，我们可以变换一下， k = sqrt(2) * sqrt(n+1/8) - 1/2，这样求平方根就不会超限了。*/


