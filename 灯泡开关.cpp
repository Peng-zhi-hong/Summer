/*题目:初始时有n个灯泡关闭。 第 1 轮，你打开所有的灯泡。 第 2 轮，每两个灯泡你关闭一次。
第 3 轮，每三个灯泡切换一次开关（如果关闭则开启，如果开启则关闭）。第 i 轮，每 
i个灯泡切换一次开关。 对于第n轮，你只切换最后一个灯泡的开关。 找出n轮后有多少个
亮着的灯泡。*/
/*思路：被操作奇数次的灯是亮的，即因数的个数是奇数个是完全平方数。判断1 ~ n之间有多少个
完全平方数。*/
#include<stdio.h>
#include<math.h>
int bulbSwitch(int n);
int main()
{
	int n;
	printf("灯泡数量:");
	scanf("%d",&n);
	printf("%d轮后有%d个亮着的灯泡",n,bulbSwitch(n));
 } 
int bulbSwitch(int n){
        return sqrt(n);
    }

