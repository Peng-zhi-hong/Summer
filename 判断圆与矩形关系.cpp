/*题目： 判断圆形和矩形是否相交*/ 
//只要两个中心在水平和垂直方向上的投影之间的距离，都分别小于等于edge/2+R，便可相交
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
struct point
{
    double x;
    double y;
}circle,a,b,c,d;
double r;
double dis(point &a,point &b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    int t;
    printf("输入数据组数:");
    scanf("%d",&t);
    point temp;
    while(t--)
    {
    	printf("输入圆形坐标，半径，矩形的一对对角坐标:");
        scanf("%lf%lf%lf%lf%lf%lf%lf",&circle.x,&circle.y,&r,&a.x,&a.y,&b.x,&b.y);
        if(a.x > b.x)
        temp=a,a=b,b=temp;
       // if(((circle.x >= min(a.x,b.x)) && (circle.x <=max(a.x,b.x))) && ((circle.y <=max(a.y,b.y)) && (circle.y>=min(a.y,b.y))))
      //  { printf("YES\n");continue;}
        c.x=a.x,c.y=b.y;
        d.x=b.x,d.y=a.y;
        if(dis(a,circle)<r && dis(b,circle) <r && dis(c,circle)<r && dis(d,circle) <r)//矩形含于圆 
        {printf("NO\n");continue;}
         if(dis(a,circle)>r && dis(b,circle) >r && dis(c,circle)>r && dis(d,circle) >r)//矩形包含圆 
        {printf("NO\n");continue;}
        
        //压边 
        if(circle.x>=a.x && circle.x<=b.x)
        {
            if(fabs(circle.y-a.y) <= r || fabs(circle.y-b.y) <= r)
           {printf("YES\n");continue;}
        }
        
        if((circle.y >= a.y && circle.y <=b.y) || (circle.y>=b.y && circle.y<=a.y))
        {
            if(fabs(circle.x-a.x) <=r || fabs(circle.x-b.x) <=r)
            {printf("YES\n");continue;}
        }
        if(dis(a,circle)<=r || dis(b,circle) <=r || dis(c,circle)<=r || dis(d,circle) <=r)
        {printf("YES\n");continue;}
        printf("NO\n");
    }
    return 0;
}
