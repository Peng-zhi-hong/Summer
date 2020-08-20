/*˼·: �����������ε����,���㰴��˳ʱ�������ʱ�뷽������
��O��Ϊԭ��ʱ�����������Ĳ�����㹫ʽ�����������ε�����������£�
  s += points[i].x * points[(i+1)%point_num].y - points[i].y * points[(i+1)%point_num].x;
���㷨�������Ż�һ�£��������ʽ�Ӻϲ�һ��ͬ����
  s += points[i].y * (points[i-1].x - points[(i+1)%point_num].x);
���ȡ������2 fabs(s/2.0) */
#include<stdio.h>
#include<math.h>
struct Point
{
    double x;
    double y;
};
//�����������ε����,���㰴��˳ʱ�������ʱ�뷽������
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
	printf("�������εı���:");
	scanf("%d",&points_size);
	//ע��:����ζ��㰴��˳ʱ�������ʱ�뷽�����к�����
	for(i = 0;i < points_size;i ++)
	scanf("%lf%lf",&points[i].x,&points[i].y);
	double result = ComputePolygonArea(points, points_size);
	printf("����ε���� = %lf",result);

 } 
