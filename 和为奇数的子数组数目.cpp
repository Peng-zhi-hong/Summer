/*��Ŀ�� ����һ���������� num �����㷵�غ�Ϊ ���� ����������Ŀ�����ڴ𰸿���
��ܴ����㽫����� 10^9 + 7 ȡ��󷵻�*/ 
/*˼·������������odd��even,��ʼ��Ϊ0���ж�ǰ׺��Ϊ������odd++ ��Ϊż����even++
��odd*even+odd��Ϊ��Ϊ��������������Ŀ��*/
 #include<stdio.h>
 int main()
 {
 int num[3] = {3,2,1}; 
 int odd = 0;
 int even = 0; 
 int result;    
 int size = sizeof(num)/sizeof(num[0]);
 long long res = 0;
 int sum = 0;
    for (int i = 0;i < size;i++)
        {
            sum += num[i];
            if (sum % 2 == 0)  {
			even++;
           }
            else   {       
			   odd++;
			  }
}
result = odd*even+odd;
printf("��Ϊ ���� ����������Ŀ = %d ",result%1000000007);
}

