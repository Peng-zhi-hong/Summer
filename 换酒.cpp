/*��Ŀ��С�����������ڴ������� numExchange ���վ�ƿ���Զһ�һƿ�¾ơ�
�㹺���� numBottles ƿ�ơ�����ȵ��˾�ƿ�еľƣ���ô��ƿ�ͻ�
��ɿյġ������������ܺȵ�����ƿ�ơ�*/

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
	    printf("���޺ȣ�");
	
}
//��ѧ���� (�����ޣ���) 
int numWaterBottles(int numBottles, int numExchange){
return numBottles + numBottles/(numExchange - 1);
   }
//�����ޣ��� 
int numWaterBottles(int numBottles, int numExchange){
	return (numBottles * numExchange-1)/(numExchange-1);
}
//�ݹ�
int numWaterBottles(int numBottles, int numExchange){
if(numBottles < numExchange) return numBottles;
return numExchange + numWaterBottles(numBottles - numExchange +1, numExchange);
} 
//̰���㷨 
int numWaterBottles(int numBottles, int numExchange){
   int emp=0; 
   int  drk=0;
        while (emp >= numExchange || numBottles>0) {
		//��ƿ���ܻ� �� ���о�û�� 
            drk+=numBottles; // �ȵ�
            emp+=numBottles; //��ƿ������
            numBottles=emp/numExchange; // ����
            emp=emp%numExchange; // ʣ���ٿ�ƿ��
    }
	return drk;
} 
