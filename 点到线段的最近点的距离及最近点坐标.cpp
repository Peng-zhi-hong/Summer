/*思路：向量矢量算法*/
#include<iostream>
#include<cmath>
#include<cstdio> 
using namespace std;
double PointToSegDist(double x, double y, double x1, double y1, double x2, double y2,struct Point *point);
struct Point{
	double x;
	double y;
}point;
int main()
{
double *px;
double *py;
	double x,y,x1,y1,x2,y2; 
	cout<<"输入线段的第一个端点的坐标:";
	cin>>x1>>y1;
	cout<<"输入线段的另一个端点的坐标:";
	cin>>x2>>y2;
	cout<<"输入点的坐标:";
	cin>>x>>y;
	double result; 
	result = PointToSegDist(x,  y,  x1,  y1,  x2,  y2, &point);
	cout<<"点到线段的最近点的距离:";
	cout<<result<<endl;
	cout<<"输出最近点的坐标:";
	cout<<"("<<point.x<< ","<<point.y<<")";

}
double PointToSegDist(double x, double y, double x1, double y1, double x2, double y2,struct Point *point)
{
//点积 
double cross = (x2 - x1) * (x - x1) + (y2 - y1) * (y - y1);
//第一个点最近 ;
if (cross <= 0) 
{
point->x = x1;
point->y = y1;
return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
}
double d2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
//第二个点最近 
if (cross >= d2)
{	
point->x = x2;
point->y = y2;
 return sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
}
double r = cross / d2;
//求垂足 
double x3 = x1 + (x2 - x1) * r;
double y3 = y1 + (y2 - y1) * r;
//垂足到点的距离 
point->x = x3;
point->y = y3;
return sqrt((x - x3) * (x - x3) + (y3 - y) * (y3 - y));
}
