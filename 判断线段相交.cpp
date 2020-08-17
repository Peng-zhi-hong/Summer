//题目：如何判断2个线段相交
/*思路：
1. 快速排斥实验 

给出线条AB、CD，如果以AB、CD为对角线的矩形不相交，那么AB、CD也必
不可能相交；如果矩形相交，那么需要再通过跨立计算进行判断。
①AB两坐标中最大的x值 小于 CD两坐标中最小x值
②CD两坐标中最大的x值 小于 AB两坐标中最小x值
③AB两坐标中最大的y值 小于 CD两坐标中最小y值
④CD两坐标中最大的y值 小于 AB两坐标中最小y值
只要满足了以上四种的其中一种，就可以认为AB与CD不相交。

2. 跨立实验

AB与CD相交必然有A、B在线段CD两边，C、D在线段AB两边。
根据上面的公式和右手螺旋法则，如果相交，AB X AC的z坐标
值z1与AB X AD的z坐标值z2必然异号；同样的，DC X DA的z坐标
值z3与DC X DB的z坐标值z4也必然异号。
特别的，如果B在CD上时，求得的z坐标值是0。所以只要同时满足
z1 X z2 ≤ 0，z3 X z4 ≤ 0，就能保证必然相交*/
#include <iostream>
#include <cstdio>
#include<algorithm>
using namespace std;
struct Line {
    double x1;
    double x2;
    double y1;
    double y2;
    

};
bool intersection(Line l1,  Line l2);
int main()
{
	Line l1,l2;
	cout<<"输入l1的一个端点:";
	cin>>l1.x1>>l1.y1;
	cout<<"输入l1的另一个端点:";
	cin>>l1.x2>>l1.y2;
	cout<<"输入l2的一个端点:";
	cin>>l2.x1>>l2.y1;
	cout<<"输入l2的另一个端点:";
	cin>>l2.x2>>l2.y2;
	if(intersection( l1,  l2))
	cout<<"相交";
	else
	cout<<"不相交"; 
	
}

bool intersection(Line l1,  Line l2)
{
    //快速排斥实验
    if (max(l1.x1,l1.x2)<min(l2.x1,l2.x2) || max(l2.x1,l2.x2)<min(l1.x1,l1.x2) ||
       max(l1.y1,l1.y2)<min(l2.y1,l2.y2) || max(l2.y1,l2.y2)<min(l1.y1,l1.y2)) 
    {
        return false;
    }
    //跨立实验
    if ((((l1.x1 - l2.x1)*(l2.y2 - l2.y1) - (l1.y1 - l2.y1)*(l2.x2 - l2.x1))*
        ((l1.x2 - l2.x1)*(l2.y2 - l2.y1) - (l1.y2 - l2.y1)*(l2.x2 - l2.x1))) > 0 ||
        (((l2.x1 - l1.x1)*(l1.y2 - l1.y1) - (l2.y1 - l1.y1)*(l1.x2 - l1.x1))*
        ((l2.x2 - l1.x1)*(l1.y2 - l1.y1) - (l2.y2 - l1.y1)*(l1.x2 - l1.x1))) > 0)
    {
        return false;
    }
    return true;
}
