/*��Ŀ:����һ�����飬���ĵ� i ��Ԫ����һ֧������Ʊ�� i ��ļ۸�
���һ���㷨�����������ܻ�ȡ�������������Ծ����ܵ���ɸ���Ľ��ף��������һ֧��Ʊ����
ע�⣺�㲻��ͬʱ�����ʽ��ף���������ٴι���ǰ���۵�֮ǰ�Ĺ�Ʊ����*/

/*˼·: ����������Ʊ�����ռ۸��б� price���������������ǽ����ն�������׬���������󣩣�
�����½������ն���������������Ǯ������ tmp Ϊ�� i-1 ��������� i ������׬ȡ�����󣬼�
tmp = prices[i] - prices[i - 1] ������������Ϊ�� tmp > 0����������������� profit��
������Ϊ 00 ��Ϊ������ֱ��������������ɺ󣬷��������� profit��*/

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
	printf("������Ʊ��������� = %d",max_profit);
}
