//��Ŀ������һ�����ȹ̶����������� arr�����㽫�������г��ֵ�ÿ���㶼��дһ�飬���������Ԫ������ƽ�ơ�
//�������飬�����㣬��дһ���㣬�����㣬�������� 
#include<stdio.h>
int main(){
int arry[9]={0,1,0,7,0,4,0,2,3};
int destination[9];
int d = 0;
for(int i = 0; i < 9; i++)
{

    if (arry[i] == 0)
      {// Copy zero twice.
      destination[d] = 0;
      d += 1;
      destination[d] = 0;}
    else
      destination[d] = arry[i];

    d += 1;
    if(d >= sizeof(arry))
    break;
}
for(int i = 0;i < 9;i++)
   printf("%d\n",destination[i]);
  
  
}
