/*��Ŀ�� �ж�Բ�κ;����Ƿ��ཻ*/ 
//ֻҪ����������ˮƽ�ʹ�ֱ�����ϵ�ͶӰ֮��ľ��룬���ֱ�С�ڵ���edge/2+R������ཻ
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
    printf("������������:");
    scanf("%d",&t);
    point temp;
    while(t--)
    {
    	printf("����Բ�����꣬�뾶�����ε�һ�ԶԽ�����:");
        scanf("%lf%lf%lf%lf%lf%lf%lf",&circle.x,&circle.y,&r,&a.x,&a.y,&b.x,&b.y);
        if(a.x > b.x)
        temp=a,a=b,b=temp;
       // if(((circle.x >= min(a.x,b.x)) && (circle.x <=max(a.x,b.x))) && ((circle.y <=max(a.y,b.y)) && (circle.y>=min(a.y,b.y))))
      //  { printf("YES\n");continue;}
        c.x=a.x,c.y=b.y;
        d.x=b.x,d.y=a.y;
        if(dis(a,circle)<r && dis(b,circle) <r && dis(c,circle)<r && dis(d,circle) <r)//���κ���Բ 
        {printf("NO\n");continue;}
         if(dis(a,circle)>r && dis(b,circle) >r && dis(c,circle)>r && dis(d,circle) >r)//���ΰ���Բ 
        {printf("NO\n");continue;}
        
        //ѹ�� 
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
