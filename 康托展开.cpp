#include<stdio.h>
#include<string.h>
  
int f(int x)
  {
      if(x==0)return 0;
      int a=1;
      while(x)
          a*=x--;
     return a;
 }
 
int contor(char *s,int len)
 {
     int ans=0;
     for(int i=0; i<len; i++)
     {
         int num=0;
         for(int j=i+1; j<len; j++)             
		 
		 if(s[i]>s[j])
                 num++;
         ans+=num*f(len-i-1);
     }
     return ans;
 }
 
 int main()
 {
    char s[10]= {0};
    scanf("%s",s);
    printf("%d\n",contor(&s[0],strlen(s))+1);
     return 0;
 }
/*思路：X=a[n]*(n-1)!+a[n-1]*(n-2)!+...+a[i]*(i-1)!+...+a*0!其中
，a为整数，并且0<=a[i]<i(1<=i<=n)公式中，n表示在排列中的位数（注意这里从
右侧开始，并且右侧第一位位数为0）a[n]代表比在第n位的数字小并且没有在第n位
之前出现过的数字的个数。即a[n]代表着第n个数列在以第n个元素为开头的子数列中
是“第几大”。*/


