//��Ŀ������ж�2���߶��ཻ
/*˼·��
1. �����ų�ʵ�� 

��������AB��CD�������AB��CDΪ�Խ��ߵľ��β��ཻ����ôAB��CDҲ��
�������ཻ����������ཻ����ô��Ҫ��ͨ��������������жϡ�
��AB������������xֵ С�� CD����������Сxֵ
��CD������������xֵ С�� AB����������Сxֵ
��AB������������yֵ С�� CD����������Сyֵ
��CD������������yֵ С�� AB����������Сyֵ
ֻҪ�������������ֵ�����һ�֣��Ϳ�����ΪAB��CD���ཻ��

2. ����ʵ��

AB��CD�ཻ��Ȼ��A��B���߶�CD���ߣ�C��D���߶�AB���ߡ�
��������Ĺ�ʽ������������������ཻ��AB X AC��z����
ֵz1��AB X AD��z����ֵz2��Ȼ��ţ�ͬ���ģ�DC X DA��z����
ֵz3��DC X DB��z����ֵz4Ҳ��Ȼ��š�
�ر�ģ����B��CD��ʱ����õ�z����ֵ��0������ֻҪͬʱ����
z1 X z2 �� 0��z3 X z4 �� 0�����ܱ�֤��Ȼ�ཻ*/
#include <iostream>
#include <cstdio>
#include<algorithm>
using namespace std;
struct Line {
    double x1;
    double x2;
    double y1;
    double y2;
    

};
bool intersection(Line l1,  Line l2);
int main()
{
	Line l1,l2;
	cout<<"����l1��һ���˵�:";
	cin>>l1.x1>>l1.y1;
	cout<<"����l1����һ���˵�:";
	cin>>l1.x2>>l1.y2;
	cout<<"����l2��һ���˵�:";
	cin>>l2.x1>>l2.y1;
	cout<<"����l2����һ���˵�:";
	cin>>l2.x2>>l2.y2;
	if(intersection( l1,  l2))
	cout<<"�ཻ";
	else
	cout<<"���ཻ"; 
	
}

bool intersection(Line l1,  Line l2)
{
    //�����ų�ʵ��
    if (max(l1.x1,l1.x2)<min(l2.x1,l2.x2) || max(l2.x1,l2.x2)<min(l1.x1,l1.x2) ||
       max(l1.y1,l1.y2)<min(l2.y1,l2.y2) || max(l2.y1,l2.y2)<min(l1.y1,l1.y2)) 
    {
        return false;
    }
    //����ʵ��
    if ((((l1.x1 - l2.x1)*(l2.y2 - l2.y1) - (l1.y1 - l2.y1)*(l2.x2 - l2.x1))*
        ((l1.x2 - l2.x1)*(l2.y2 - l2.y1) - (l1.y2 - l2.y1)*(l2.x2 - l2.x1))) > 0 ||
        (((l2.x1 - l1.x1)*(l1.y2 - l1.y1) - (l2.y1 - l1.y1)*(l1.x2 - l1.x1))*
        ((l2.x2 - l1.x1)*(l1.y2 - l1.y1) - (l2.y2 - l1.y1)*(l1.x2 - l1.x1))) > 0)
    {
        return false;
    }
    return true;
}
