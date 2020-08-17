/*��Ŀ������һ��Q(a,b),���߶�M����β�����˵�P1(X1,Y1),P2(X2,Y2),Ҫ���жϵ�Q�����߶�M�ϣ�*/ 

/*˼·��������ж�һ�����Ƿ����߶��ϣ���ôҪ������������������
��1����Q - P1�� * ��P2 - P1��= 0��
��2��Q����P1��P2Ϊ�ԽǶ���ľ����ڣ�
��һ��ͨ�׵�������Ҫ��Q��P1��P2���㹲�ߣ�����һ�������
��Ӧ�ÿ����Ƿ�����Q��P1P2�ӳ��߻����ӳ��������������ʱ
�ڶ��������Ͷ�Q��ĺ���������������ƣ�Ҫ���������Ҫ��P1P2
�������Сֵ�����ֵ֮�䣬Ҳ����˵��֤��Q��P1P2֮�䡣*/

#include <iostream>
#include <cstdio>
#include<algorithm>
using namespace std;
 
struct point
{
    double x;
    double y;
};
 
bool onSegment(point Pi , point Pj , point Q)
{
    if((Q.x - Pi.x) * (Pj.y - Pi.y) == (Pj.x - Pi.x) * (Q.y - Pi.y)  //��� 
       //��֤Q��������pi,pj֮�� 
       && min(Pi.x , Pj.x) <= Q.x && Q.x <= max(Pi.x , Pj.x)    
       && min(Pi.y , Pj.y) <= Q.y && Q.y <= max(Pi.y , Pj.y))
        return true;
    else
        return false;
}
 
int main()
{
    point p1 , p2 , q;
    cout<<"�����һ���߶ζ˵�����:";
    cin >> p1.x >> p1.y;
    cout<<"����ڶ����߶ζ˵�����:";
    cin >> p2.x >> p2.y;
    cout<<"����һ��������:";
    cin >> q.x >> q.y;
    if(onSegment(p1 , p2 , q))
        cout << "Q�����߶�P1P2��" << endl;
    else
        cout << "Q�㲻���߶�P1P2��" << endl;
}

