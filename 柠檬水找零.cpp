/*题目：在柠檬水摊上，每一杯柠檬水的售价为5美元。顾客排队购买你的产品，
（按账单 bills 支付的顺序）一次购买一杯。每位顾客只买一杯柠檬水
，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零
，也就是说净交易是每位顾客向你支付 5 美元。注意，一开始你手头没有
任何零钱。*/

/*思路：遇到五美元，five++，
遇到十美元，(five>0)five--，
(five = 0)返回False
遇到二十美元，
1,five--,ten--;
2,five-3
不满足以上两种方案，返回false
直到最后一位顾客结清账，返回True。*/ 

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
		printf("可以正确找零。");
	else
		printf("不能正确找零。");
}

