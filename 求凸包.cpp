/* ˼·: 
���򣺰���x��С�����������x��ͬ������y��С��������
����֮���һ�����Ϊ͹���ϵĵ㣨��x���x��С��y��С��y���ĵ㶼����͹���ϣ���
ѡ�����������͹���ĵ㣬��������������ѡ�㣬�����������ἰ����ԭ���жϸõ���
͹���������˳ʱ�뻹����ʱ�뷽�������˳ʱ�뷽�򣬽��õ����͹���������ж���
֮ǰ����͹���ĵ㲻�ϸ�ɾ����͹���㣬�ظ���������ֱ���õ����͹����Ҳ����˵ÿ
���㶼������͹����ֻ�Ǻ�����Щ��ɾ�ˣ������Ͼ�����͹���Ĺ��ɲ��裬��͹���ο���
͹��������û��ʲô�����Ϊ���ж�ʱ���ж��Ƿ�Ϊ˳ʱ�룬������Ϊ�����жθõ���
�������Ϸ�����͹���Ͳ������ˣ�����˳ʱ����Զ���һ���ġ����ַ���������ĵ���͹
������˳ʱ�뷽���ҳ����ģ���λ����ҵ�һ�����ظ����Σ����Գ��˵�ֻ��һ�������
�£��ǵõ�ĸ�����һ������ĵ����겻Ҫ�ظ���������������������ĵ�����պ���һ
��ֱ���ϵĵ㣬����Ӱ������*/


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int MaxN=10010;

 int n,tot;//nΪ��ĸ�����totΪ͹��ĸ���
 struct point
 {
     double x,y;
 };
 point p[MaxN],CHP[MaxN];//CHPΪ͹����������ɵĵ�
 
 bool cmp(point a,point b)//ˮƽ���򣬰�x�Ӵ�С�ţ����x��ͬ����y�Ӵ�С����
 {
     return (a.x>b.x||(a.x==b.x&&a.y>b.y));
 }
 
 double xmul(point a,point b,point c)//���
 {
     return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
 }
 
void Andrew()
 {
     sort(p,p+n,cmp);
	      tot=0;
 
     for(int i=0;i<n;++i)//�����ϰ��͹��
     {
         while(tot>1&&xmul(CHP[tot-2],CHP[tot-1],p[i])>0)
             --tot;
        CHP[tot++]=p[i];
     }
 
 
     int k=tot;
     for(int i=n-2;i>=0;--i)//�����°��͹��
     {
         while(tot>k&&xmul(CHP[tot-2],CHP[tot-1],p[i])>0)
             --tot;
         CHP[tot++]=p[i];
     }
 
     if(n>1)//����ֻ��һ����İ��ٵ����ж�
        --tot;
 }
 
 
 int main()
 {
 	printf("��������������:");
     scanf("%d",&n);
     for(int i=0;i<n;++i)
     {
     	printf("�������%d��������(�����겻���ظ�):",i+1);
         scanf("%lf%lf",&p[i].x,&p[i].y);
     }
     Andrew();
     printf("͹���ĸ��� = %d\n",tot);
     for(int i=0;i<tot;++i)
     {
         printf("��%d��͹����������:�� %.2lf , %.2lf��\n",i+1,CHP[i].x,CHP[i].y);
     }
     return 0;
 }
