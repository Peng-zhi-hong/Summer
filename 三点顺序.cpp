/*˼·��
����ʸ������ж�����ʱ�뻹��˳ʱ�롣
��A(x1,y1),B(x2,y2),C(x3,y3),�����������ߵ�ʸ���ֱ��ǣ�
AB=(x2-x1,y2-y1), AC=(x3-x1,y3-y1)
��AB��AC�Ĳ��Ϊ��(2*2������ʽ)
|x2-x1, y2-y1|
|x3-x1, y3-y1|
ֵΪ��(x2-x1)(y3-y1) - (y2-y1)(x3-x1)
�������ַ�������жϣ�
���ABxAC>0����������ABC����ʱ��ģ�
���ABxAC<0����������ABC��˳ʱ��ģ�
���ABxAC=0����˵�����㹲�ߡ�*/

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int x1,y1,x2,y2,x3,y3;
    while(~scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3)&&(x1+y1+x2+y2+x3+y3))
    {
        if((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1)>0)
            printf("0\n"); //��ʱ�� 
        else 
            printf("1\n");//˳ʱ�� 
    }
    return 0;
}

