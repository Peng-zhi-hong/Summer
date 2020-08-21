/*��Ŀ��÷ɭ����Mersenne Prime��ָ��������2n-1��������������ָ��n��������
��ΪMn�����һ��÷ɭ���������������Ϊ÷ɭ����������22-1=3��23-1
=7����÷ɭ������*/

#include <math.h>
#include <stdio.h>
int prime(long long n)
{
    int i;
    long k;
    k=sqrt(n)+1;
    for(i=2; i<=k; i++)
        if(n%i == 0)
            return 0;
    return 1;
}
int main()
{
    int n=0, i;
    long long mp;
    printf("Mersenne Prime:\n");
    for(i=2; i<=100; i++)
    {
        mp=pow(2,i)-1;
        if(mp < 0)return 0;
        if( prime(mp) )
        {
            n++;
            printf("M(%d)=%lld", i, mp);
            printf("\n");
        }
    }
    printf("the number of Mersenne Prime less than 20 is:%d\n", n);
   
    return 0;
}
