/* 思路: 
排序：按照x由小到大排序，如果x相同，按照y由小到大排序。
排序之后第一个点必为凸包上的点（有x最大、x最小、y最小、y最大的点都必在凸包上）。
选最近两个刚入凸包的点，再在排序中依次选点，根据上面所提及到的原理，判断该点在
凸包那两点的顺时针还是逆时针方向。如果在顺时针方向，将该点加入凸包，否则判定出
之前进入凸包的点不合格，删除该凸包点，重复第三步，直到该点加入凸包（也就是说每
个点都曾进过凸包，只是后来有些被删了）。以上就是上凸包的构成步骤，下凸包参考上
凸包，基本没有什么差别，因为在判断时是判断是否为顺时针，别误以为是在判段该点在
向量的上方，下凸包就不可用了，对于顺时针而言都是一样的。这种方法求出来的点是凸
包沿着顺时针方向找出来的，首位相接且第一个点重复两次，所以除了点只有一个的情况
下，记得点的个数减一。输入的点坐标不要重复，本方法不适用于输入的点坐标刚好是一
条直线上的点，否则影响结果。*/


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int MaxN=10010;

 int n,tot;//n为点的个数，tot为凸点的个数
 struct point
 {
     double x,y;
 };
 point p[MaxN],CHP[MaxN];//CHP为凸包最后所构成的点
 
 bool cmp(point a,point b)//水平排序，按x从大到小排，如果x相同，按y从大到小排序
 {
     return (a.x>b.x||(a.x==b.x&&a.y>b.y));
 }
 
 double xmul(point a,point b,point c)//叉积
 {
     return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
 }
 
void Andrew()
 {
     sort(p,p+n,cmp);
	      tot=0;
 
     for(int i=0;i<n;++i)//计算上半个凸包
     {
         while(tot>1&&xmul(CHP[tot-2],CHP[tot-1],p[i])>0)
             --tot;
        CHP[tot++]=p[i];
     }
 
 
     int k=tot;
     for(int i=n-2;i>=0;--i)//计算下半个凸包
     {
         while(tot>k&&xmul(CHP[tot-2],CHP[tot-1],p[i])>0)
             --tot;
         CHP[tot++]=p[i];
     }
 
     if(n>1)//对于只有一个点的包再单独判断
        --tot;
 }
 
 
 int main()
 {
 	printf("输入坐标点的数量:");
     scanf("%d",&n);
     for(int i=0;i<n;++i)
     {
     	printf("请输入第%d个点坐标(点坐标不能重复):",i+1);
         scanf("%lf%lf",&p[i].x,&p[i].y);
     }
     Andrew();
     printf("凸包的个数 = %d\n",tot);
     for(int i=0;i<tot;++i)
     {
         printf("第%d个凸包顶点坐标:（ %.2lf , %.2lf）\n",i+1,CHP[i].x,CHP[i].y);
     }
     return 0;
 }
