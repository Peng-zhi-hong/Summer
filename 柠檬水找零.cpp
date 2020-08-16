/*��Ŀ��������ˮ̯�ϣ�ÿһ������ˮ���ۼ�Ϊ5��Ԫ���˿��Ŷӹ�����Ĳ�Ʒ��
�����˵� bills ֧����˳��һ�ι���һ����ÿλ�˿�ֻ��һ������ˮ
��Ȼ�����㸶 5 ��Ԫ��10 ��Ԫ�� 20 ��Ԫ��������ÿ���˿���ȷ����
��Ҳ����˵��������ÿλ�˿�����֧�� 5 ��Ԫ��ע�⣬һ��ʼ����ͷû��
�κ���Ǯ��*/

/*˼·����������Ԫ��five++��
����ʮ��Ԫ��(five>0)five--��
(five = 0)����False
������ʮ��Ԫ��
1,five--,ten--;
2,five-3
�������������ַ���������false
ֱ�����һλ�˿ͽ����ˣ�����True��*/ 

#include<stdio.h>
bool lemonadeChange(int bills[],int len) {
        int five = 0, ten = 0;
        for (int i = 0;i < len;i++) {
            if (bills[i] == 5)
                five++;
            else if (bills[i] == 10) {
                if (five == 0) return false;
                five--;
                ten++;
            } else {
                if (five > 0 && ten > 0) {
                    five--;
                    ten--;
                } else if (five >= 3) {
                    five -= 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
int main()
{
	int bills[] = {5,5,5,10,10,20};
	int len = sizeof(bills)/sizeof(bills[0]);
	if(lemonadeChange( bills,len ))
		printf("������ȷ���㡣");
	else
		printf("������ȷ���㡣");
}

