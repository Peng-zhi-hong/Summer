//编程思路：求素数n，n是否会被2~n之间的数整除，如果不整除，那么是素数，有一个整除了，就不是素数
#include<stdio.h>
int main()
{
	int i,n;
	scanf("%d",&n);
   if(n>=2){
   
	for(i=2 ; i<n ;i++)
	{
		if(n%i==0){
	
		break;
		}	
	 } 
}
	 if(i>=n)
	 printf("this is prime number."); 
	 else
	 printf("this is not prime number.");
}
