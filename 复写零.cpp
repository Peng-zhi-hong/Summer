//题目：给你一个长度固定的整数数组 arr，请你将该数组中出现的每个零都复写一遍，并将其余的元素向右平移。
//遍历数组，遇到零，重写一个零，不是零，保留下来 
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
