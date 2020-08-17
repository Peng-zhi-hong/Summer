 /*题目：已知一个矩形和一个点，判断这个点是否在矩形内*/
  
 /*思路：只需要判断该点是否在上下两条边和左右两条边之间就
 行，判断一个点是否在两条线段之间夹着，就转化成，判
 断一个点是否在某条线段的一边上，就可以利用叉乘的方向\
 性，来判断夹角是否超过了180度  只要判断
 (p1 p2 X p1 p )* (p3 p4 X p3 p1)  >= 0 
 就说明p在p1p2,p3p4中间夹着，同理计算另两边就可以了 */
 
#include <cstdio>
#include "iostream"
//#include<algorithm>
using namespace std;
struct Point
{
	float x;
	float y;
	Point(float x,float y)
	{
		this->x = x;
		this->y = y;
	}
};
// 计算 |p1 p2| X |p1 p|
float GetCross(Point& p1, Point& p2,Point& p)
{
	return (p2.x - p1.x) * (p.y - p1.y) -(p.x - p1.x) * (p2.y - p1.y);
}
//判断点是否在5X5 以原点为左下角的正方形内（便于测试）
bool IsPointInMatrix(Point& p)
{
	//定义一个矩形的四个端点 
	Point p1(0,5);
	Point p2(0,0);
	Point p3(5,0);
	Point p4(5,5);
 
	return GetCross(p1,p2,p) * GetCross(p3,p4,p) >= 0 && GetCross(p2,p3,p) * GetCross(p4,p1,p) >= 0;
	//return false;
}

int main()
{
 
	while(true)
	{
		Point testPoint(0,0);
		cout << "enter  the point :" << endl;
 
		cin >> testPoint.x >> testPoint.y;
 
		cout << "the point is  : "<< testPoint.x << " "<< testPoint.y << endl;
 
		cout << "the point is " << (IsPointInMatrix(testPoint)? "in the Matrix .": "not in the matrix ." )<< endl;
	}
	 
	return 0;
}
 
