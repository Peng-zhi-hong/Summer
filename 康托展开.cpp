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


