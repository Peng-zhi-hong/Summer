/*题目：小区便利店正在促销，用 numExchange 个空酒瓶可以兑换一瓶新酒。
你购入了 numBottles 瓶酒。如果喝掉了酒瓶中的酒，那么酒瓶就会
变成空的。请你计算最多能喝到多少瓶酒。*/

#include<stdio.h>
int numWaterBottles(int numBottles, int numExchange);
int main()
{
	int numBottles, numExchange;
	scanf("%d%d",&numBottles,&numExchange);
	if(numExchange != 1){
		int drink_wink = numWaterBottles(numBottles, numExchange);
		printf("drink_wink = %d",drink_wink);}
	else
	    printf("无限喝！");
	
}
//数学方法 (可以赊，借) 
int numWaterBottles(int numBottles, int numExchange){
return numBottles + numBottles/(numExchange - 1);
   }
//不能赊，借 
int numWaterBottles(int numBottles, int numExchange){
	return (numBottles * numExchange-1)/(numExchange-1);
}
//递归
int numWaterBottles(int numBottles, int numExchange){
if(numBottles < numExchange) return numBottles;
return numExchange + numWaterBottles(numBottles - numExchange +1, numExchange);
} 
//贪心算法 
int numWaterBottles(int numBottles, int numExchange){
   int emp=0; 
   int  drk=0;
        while (emp >= numExchange || numBottles>0) {
		//空瓶还能换 或 还有酒没喝 
            drk+=numBottles; // 喝掉
            emp+=numBottles; //空瓶加起来
            numBottles=emp/numExchange; // 换酒
            emp=emp%numExchange; // 剩多少空瓶？
    }
	return drk;
} 
