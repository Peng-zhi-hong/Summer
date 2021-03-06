/*思路：
利用矢量叉积判断是逆时针还是顺时针。
设A(x1,y1),B(x2,y2),C(x3,y3),则三角形两边的矢量分别是：
AB=(x2-x1,y2-y1), AC=(x3-x1,y3-y1)
则AB和AC的叉积为：(2*2的行列式)
|x2-x1, y2-y1|
|x3-x1, y3-y1|
值为：(x2-x1)(y3-y1) - (y2-y1)(x3-x1)
利用右手法则进行判断：
如果ABxAC>0，则三角形ABC是逆时针的；
如果ABxAC<0，则三角形ABC是顺时针的；
如果ABxAC=0，则说明三点共线。*/

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int x1,y1,x2,y2,x3,y3;
    while(~scanf("%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3)&&(x1+y1+x2+y2+x3+y3))
    {
        if((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1)>0)
            printf("0\n"); //逆时针 
        else 
            printf("1\n");//顺时针 
    }
    return 0;
}

