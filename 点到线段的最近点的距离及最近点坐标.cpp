/*˼·������ʸ���㷨*/
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
	cout<<"�����߶εĵ�һ���˵������:";
	cin>>x1>>y1;
	cout<<"�����߶ε���һ���˵������:";
	cin>>x2>>y2;
	cout<<"����������:";
	cin>>x>>y;
	double result; 
	result = PointToSegDist(x,  y,  x1,  y1,  x2,  y2, &point);
	cout<<"�㵽�߶ε������ľ���:";
	cout<<result<<endl;
	cout<<"�������������:";
	cout<<"("<<point.x<< ","<<point.y<<")";

}
double PointToSegDist(double x, double y, double x1, double y1, double x2, double y2,struct Point *point)
{
//��� 
double cross = (x2 - x1) * (x - x1) + (y2 - y1) * (y - y1);
//��һ������� ;
if (cross <= 0) 
{
point->x = x1;
point->y = y1;
return sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));
}
double d2 = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
//�ڶ�������� 
if (cross >= d2)
{	
point->x = x2;
point->y = y2;
 return sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
}
double r = cross / d2;
//���� 
double x3 = x1 + (x2 - x1) * r;
double y3 = y1 + (y2 - y1) * r;
//���㵽��ľ��� 
point->x = x3;
point->y = y3;
return sqrt((x - x3) * (x - x3) + (y3 - y) * (y3 - y));
}
