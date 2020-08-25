/*题目:给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。*/

/*思路: 遍历整个股票交易日价格列表 price，策略是所有上涨交易日都买卖（赚到所有利润），
所有下降交易日都不买卖（永不亏钱）。设 tmp 为第 i-1 日买入与第 i 日卖出赚取的利润，即
tmp = prices[i] - prices[i - 1] ；当该天利润为正 tmp > 0，则将利润加入总利润 profit；
当利润为 00 或为负，则直接跳过；遍历完成后，返回总利润 profit。*/

#include<stdio.h>
int maxProfit(int prices[],int len){ 
        int i,tmp,max_profit = 0 ;
        for (i = 1;i < len;i++){
            tmp = prices[i] - prices[i - 1];
            if (tmp > 0) max_profit += tmp;
        }
        return max_profit;
} 
int main()
{
	int prices[] = {34,45,3,4,65,43};
	int len = sizeof(prices)/sizeof(prices[0]);
	int max_profit = maxProfit(prices,len);
	printf("买卖股票的最大利润 = %d",max_profit);
}
