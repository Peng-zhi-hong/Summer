
/*********************************/
// �����������ֱ�ߵĴ��㣬���������߶��ϣ���ȡ���߶εľ���
// ����ȡ���߶����˵�������Сֵ
//
// ������
// point:  �洢���xy����
// p1, p2: �߶ε�����
//
// return: �㵽�߶ε���С����
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
 
    // ��ֱ�ߴ�ֱ��������ʾ����ת����ʾ
    float k = -((p1[0] - point[0])*dx + (p1[1] - point[1])*dy) / ( dx*dx + dy*dy);
    float footX = k*dx + p1[0];
    float footY = k*dy + p1[1];
 
    //if�����Ƿ������߶���
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
