/* ԭ��: �����Ե��Y���������ε�ÿһ������бȽϣ�
**    ��õ����Ե����ڵ��������αߵ����н��㡣
**    ������Ե�����ߵ�ĸ���������������
**    ��ò��Ե��ڶ�����ڣ������ڶ�����⡣ */
#include <stdio.h>
#include <iostream>
/* ��������: �жϵ�(x, y)�Ƿ�����ploy_sides������Ķ������ */
/* ����: poly_sides    ���Զ���εĶ�����
**    poly_x    ���Զ���εĸ��������X������
**    poly_y    ���Զ���εĸ��������Y������
**    x    ���Ե��X������
**    Y ���Ե��Y������ */
/* ����ֵ: ����0 ��ʾ���ڶ�����ڲ�������1 ��ʾ�ڶ�����ڲ� */
/* ˵��: �ڶ���θ����ϵĵ�Ĭ�ϲ��ڶ�����ڲ� */
int inOrNot(int poly_sides, float *poly_X, float *poly_Y, float x, float y)
{
    int i, j;
    j = poly_sides - 1;
    int res = 0;
    for (i = 0; i<poly_sides; i++)
    {
        //��ÿһ���߽��б������ñߵ������˵㣬��һ�������ڴ�����(x,y)����ߣ�
		//���������У���һ�����y��߱�p.yС����һ�����y��p.y��
        if ((poly_Y[i]<y && poly_Y[j] >= y || poly_Y[j]<y && poly_Y[i] >= y) && (poly_X[i] <= x || poly_X[j] <= x))
        {
            //��ˮƽ��ֱ����ñ��ཻ���󽻵��x���ꡣ
            res ^= ((poly_X[i] + (y - poly_Y[i]) / (poly_Y[j] - poly_Y[i])*(poly_X[j] - poly_X[i])) < x);
        }
        j = i;
    }
    return res;
}
using namespace std;
int main(void)
{
    int poly_sides = 5;    // ����ζ�����
    float poly_X[5] = { 1, 1, 3, 4, 3 };    // ����θ������X������
    float poly_Y[5] = { 1, 2, 3, 2, 1 };    // ����θ������Y������
    float x = 1;    // ���Ե��X������
    float y = 1; // ���Ե��Y������
    int ret;
    cin>>x>>y;
    ret = inOrNot(poly_sides, poly_X, poly_Y, x, y);
    if (1 == ret)
    {
        printf("the point (%f, %f), in the poly\n", x, y);
    }
    else
    {
        printf("the point (%f, %f), not in the poly\n", x, y);
    }
    system("pause");
    return 0;
}
