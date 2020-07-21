/*题目：传送带上的包裹必须在 D 天内从一个港口运送到另一个港口。
传送带上的第 i个包裹的重量为weights[i]。每一天，我们都会
按给出重量的顺序往传送带上装载包裹。我们装载的重量不会超过船的最大运载重量。
返回能在 D 天内将传送带上的所有包裹送达的船的最低运载能力。*/

/*思路：首先求出运载能力的上下极限，上极限为所有货物的总和，下极限为货物中最
重的那一个的重量，然后采用二分查找的方法，逐步找到满足所需天数小于等于所要求
天数的最低运载能力*/ 

#include<stdio.h>
int jg(int *weights,int mid,int length);
int main()
{
	int D,mid;
	int weights[5] = {1,2,4,7,8};
	int length = sizeof(weights)/sizeof(weights[0]);
	int b = 0,a = 0;//a为运载能力的下限，b为运载能力的下限 
	printf("输入天数要求：");
	scanf("%d",&D);
	for (int i = 0;i < length;i++)
	{
	if(a < weights[i]) a = weights[i];
	b += weights[i];
}

while (a < b)
        {
            mid = (a + b) / 2;
            int day = jg(weights,mid,length);
		
            if (day <= D)
                b = mid;
            else
                a = mid + 1;
        }
printf("最低运载能力 = %d\n",a);
    }

int jg(int *weights,int mid,int length){//mid为运载能力
    int s = 0,day = 0;
    int i;
    for ( i = 0;i < length;i++){
		if ((s+weights[i])>mid)//当前的重量 + 当该天的包裹重量 > 当前最大运载能力tar；当天包裹重量就一起不能运载，会超重
        {
		   day++;
           s = weights[i];
				 } //天数+1，s当前重量就变为该天的包裹重量
        else//反之，当前重量+该天包裹重量
            s += weights[i];
        
           }
	     return (day+1) ;
			}
       


