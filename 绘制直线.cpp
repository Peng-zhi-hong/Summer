/*length����ʾint��������һ��int32λ�����仰˵�����ܹ���length*32λ��������
w: ��ʾһ�ж�����λ������Ŀ˵��w�ܱ�32������Ҳ����һ����w/32��int
y: ��ʾ����һ�л�ֱ��
x1����ʾ����y��ʼ�±�Ϊx1�Ķ����ƿ�ʼ��
x2����ʾ������y�±�Ϊx2�Ķ����ƽ����� 
x1��x2Ϊ1������Ϊ0�������ʾ��ʮ���Ƶ�����*/

#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
int main()
{
int length,  w,  x1,  x2,  y;
printf("���� length�� w���Ա���Ϊ��λ����ֱ�߿�ʼλ�� x1������Ϊ��λ��\
��ֱ�߽���λ�� x2������Ϊ��λ����ֱ���������� y");
scanf("%d%d%d%d%d" , &length, &w , &x1 , &x2 , &y) ;
int *ret = (int *)malloc(sizeof(int) * length);
memset(ret, 0, sizeof(int) * length);

  int startIndex = y * (w / 32);
  int bitIndexAtY = 0;
  for(int i = startIndex; i < startIndex + length; i++)
  {
    unsigned int n = (unsigned int)1 << 31;

    do{
      if(bitIndexAtY >= x1 && bitIndexAtY <= x2)
        *(ret + i) |= n;
      bitIndexAtY++;
    }while(n = n >> 1);
  }
for(int i = startIndex; i < startIndex + length; i++)
 printf("%d",*(ret + i));
}


