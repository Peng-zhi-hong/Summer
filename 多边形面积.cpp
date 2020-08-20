/*思路: 计算任意多边形的面积,顶点按照顺时针或者逆时针方向排列
当O点为原点时，根据向量的叉积计算公式，各个三角形的面积计算如下：
  s += points[i].x * points[(i+1)%point_num].y - points[i].y * points[(i+1)%point_num].x;
该算法还可以优化一下，对上面的式子合并一下同类项
  s += points[i].y * (points[i-1].x - points[(i+1)%point_num].x);
结果取正除以2 fabs(s/2.0) */
#include<stdio.h>
#include<math.h>
struct Point
{
    double x;
    double y;
};
//计算任意多边形的面积,顶点按照顺时针或者逆时针方向排列
double ComputePolygonArea(struct Point *points,int points_size)
{
    int point_num = points_size;
    if(point_num < 3)return 0.0;
    double s = points[0].y * (points[point_num-1].x - points[1].x);
    for(int i = 1; i < point_num; ++i)
        s += points[i].y * (points[i-1].x - points[(i+1)%point_num].x);
    return fabs(s/2.0);
}
int main()
{
	int points_size,i;
	struct Point points[20];
	printf("输入多边形的边数:");
	scanf("%d",&points_size);
	//注意:多边形顶点按照顺时针或者逆时针方向排列后输入
	for(i = 0;i < points_size;i ++)
	scanf("%lf%lf",&points[i].x,&points[i].y);
	double result = ComputePolygonArea(points, points_size);
	printf("多边形的面积 = %lf",result);

 } 
