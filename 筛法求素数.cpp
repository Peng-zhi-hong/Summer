//���˼·��������n��n�Ƿ�ᱻ2~n֮������������������������ô����������һ�������ˣ��Ͳ�������
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
