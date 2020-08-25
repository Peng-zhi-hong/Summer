#include<stdio.h>
//Î»ÔËËã£ºA*B=(A*2)(B/2)=(A*2)(B//2)+A*(B%2)
int multiply1(int A,int B){
       if (B == 1) return A;
        if (B == 0)return 0;
        if (B & 1)
            return multiply1(A<<1, B>>1) + A ;
        else
            return multiply1(A<<1, B>>1);
}

//µİ¹é 
long int multiply2(long int A,long int B){
   if(B==0){
      return 0;
 }
      return A + multiply2(A,B-1);
    }
int main()
{
	long int A,B,temp;
	scanf("%ld%ld",&A,&B);
	if(A > B){
    temp = A ;
    A = B;
    B = temp;
	}
   long int result1 = multiply1( A, B);
   long int result2 = multiply2( A, B);
    printf("result1 = %d\n",result1);
    printf("result2 = %ld",result2);

 }
