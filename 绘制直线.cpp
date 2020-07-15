/*题目：绘制直线。有个单色屏幕存储在一个一维数组中，使得32个连续像素可以存放在一个 int 里。
屏幕宽度为w，且w可被32整除（即一个 int 不会分布在两行上），屏幕高度可由数组长度及屏
幕宽度推算得出。请实现一个函数，绘制从点(x1, y)到点(x2, y)的水平线。
给出数组的长度 length，宽度 w（以比特为单位）、直线开始位置 x1（比特为单位）、
直线结束位置 x2（比特为单位）、直线所在行数?y。返回绘制过后的数组。*/


/*length：表示int的总数，一个int32位，换句话说就是总共有length*32位二进制数
w: 表示一行二进制位数，题目说了w能被32整除，也就是一行有w/32个int
y: 表示在哪一行画直线
x1：表示从行y开始下标为x1的二进制开始画
x2：表示画到行y下标为x2的二进制结束画 
x1到x2为1，其余为0，输出表示的十进制的数组*/

#include<iostream>
#include<stdlib.h>
#include<cstring>
using namespace std;
int main()
{
int length,  w,  x1,  x2,  y;
printf("长度 length、 w（以比特为单位）、直线开始位置 x1（比特为单位）\
、直线结束位置 x2（比特为单位）、直线所在行数 y");
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


