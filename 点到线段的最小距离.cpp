
/*********************************/
// 如果经过点做直线的垂足，垂足落在线段上，则取垂线段的距离
// 否则取到线段两端点距离的最小值
//
// 参数：
// point:  存储点的xy坐标
// p1, p2: 线段的两点
//
// return: 点到线段的最小距离
/*********************************/
 #include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <cmath>
using namespace std;
float CalculatePointToLineDistance(float point[2], const float p1[2], const float p2[2])
{
    float dis = 0.f;
 
    float dx = p2[0] - p1[0];
    float dy = p2[1] - p1[1];
 
    // 两直线垂直，向量表示法，转换后公示
    float k = -((p1[0] - point[0])*dx + (p1[1] - point[1])*dy) / ( dx*dx + dy*dy);
    float footX = k*dx + p1[0];
    float footY = k*dy + p1[1];
 
    //if垂足是否落在线段上
    if( footY >= min(p1[1], p2[1]) && footY <=max(p1[1], p2[1])
        && footX >= min(p1[0], p2[0]) && footX <=max(p1[0], p2[0] ) )
    {
        dis = sqrtf((footX-point[0])*(footX-point[0]) + (footY-point[1])*(footY-point[1]));
    }
    else 
    {
        float dis1 = sqrtf((p1[0]-point[0])*(p1[0]-point[0]) + (p1[1]-point[1])*(p1[1]-point[1]));
        float dis2 = sqrtf((p2[0]-point[0])*(p2[0]-point[0]) + (p2[1]-point[1])*(p2[1]-point[1]));
 
        dis = ( dis1 < dis2 ? dis1 : dis2 );
    }
 
    return dis;
}
