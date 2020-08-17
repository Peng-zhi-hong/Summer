/*题目：给定一点Q(a,b),和线段M的首尾两个端点P1(X1,Y1),P2(X2,Y2),要求判断点Q否在线段M上；*/ 

/*思路：如果想判断一个点是否在线段上，那么要满足以下两个条件：
（1）（Q - P1） * （P2 - P1）= 0；
（2）Q在以P1，P2为对角顶点的矩形内；
第一点通俗点理解就是要求Q、P1、P2三点共线；当第一个满足后，
就应该考虑是否会出现Q在P1P2延长线或反向延长线这种情况。此时
第二个条件就对Q点的横纵坐标进行了限制，要求横纵坐标要在P1P2
两点的最小值和最大值之间，也就是说保证了Q在P1P2之间。*/

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
    if((Q.x - Pi.x) * (Pj.y - Pi.y) == (Pj.x - Pi.x) * (Q.y - Pi.y)  //叉乘 
       //保证Q点坐标在pi,pj之间 
       && min(Pi.x , Pj.x) <= Q.x && Q.x <= max(Pi.x , Pj.x)    
       && min(Pi.y , Pj.y) <= Q.y && Q.y <= max(Pi.y , Pj.y))
        return true;
    else
        return false;
}
 
int main()
{
    point p1 , p2 , q;
    cout<<"输入第一个线段端点坐标:";
    cin >> p1.x >> p1.y;
    cout<<"输入第二个线段端点坐标:";
    cin >> p2.x >> p2.y;
    cout<<"输入一个点坐标:";
    cin >> q.x >> q.y;
    if(onSegment(p1 , p2 , q))
        cout << "Q点在线段P1P2内" << endl;
    else
        cout << "Q点不在线段P1P2内" << endl;
}

