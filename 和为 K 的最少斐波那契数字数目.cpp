/*�������� k?�����㷵�غ�Ϊ?k?��쳲��������ֵ�������Ŀ�����У�ÿ��쳲��������ֶ����Ա�ʹ�ö�Ρ�

쳲��������ֶ���Ϊ��
F1 = 1
F2 = 1
Fn = Fn-1 + Fn-2�� ���� n > 2 ��
���ݱ�֤���ڸ����� k��һ�����ҵ����н⡣*/
#include<stdio.h>
#define N 10000
int Fibon(int n);
int main()
{   int k,n,i=1;
    int count = 0;
	printf("����k:");
	scanf("%d",&k);
	while(1)
	{
	if( k <= Fibon(i)){
		n=i;
		break;
	}
	i++;
	}
for(i = n; i>=1; i--){
	if(k >= Fibon(i)){
		k = k - Fibon(i);
		count++;
	}

}
	printf("��Ϊk��쳲��������ֵ�������ĿΪ:%d",count);	 


}

int Fibon(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return Fibon(n - 1) + Fibon(n - 2);
	}
}
