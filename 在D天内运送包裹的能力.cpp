/*��Ŀ�����ʹ��ϵİ��������� D ���ڴ�һ���ۿ����͵���һ���ۿڡ�
���ʹ��ϵĵ� i������������Ϊweights[i]��ÿһ�죬���Ƕ���
������������˳�������ʹ���װ�ذ���������װ�ص��������ᳬ�������������������
�������� D ���ڽ����ʹ��ϵ����а����ʹ�Ĵ����������������*/

/*˼·����������������������¼��ޣ��ϼ���Ϊ���л�����ܺͣ��¼���Ϊ��������
�ص���һ����������Ȼ����ö��ֲ��ҵķ��������ҵ�������������С�ڵ�����Ҫ��
�����������������*/ 

#include<stdio.h>
int jg(int *weights,int mid,int length);
int main()
{
	int D,mid;
	int weights[5] = {1,2,4,7,8};
	int length = sizeof(weights)/sizeof(weights[0]);
	int b = 0,a = 0;//aΪ�������������ޣ�bΪ�������������� 
	printf("��������Ҫ��");
	scanf("%d",&D);
	for (int i = 0;i < length;i++)
	{
	if(a < weights[i]) a = weights[i];
	b += weights[i];
}

while (a < b)
        {
            mid = (a + b) / 2;
            int day = jg(weights,mid,length);
		
            if (day <= D)
                b = mid;
            else
                a = mid + 1;
        }
printf("����������� = %d\n",a);
    }

int jg(int *weights,int mid,int length){//midΪ��������
    int s = 0,day = 0;
    int i;
    for ( i = 0;i < length;i++){
		if ((s+weights[i])>mid)//��ǰ������ + ������İ������� > ��ǰ�����������tar���������������һ�������أ��ᳬ��
        {
		   day++;
           s = weights[i];
				 } //����+1��s��ǰ�����ͱ�Ϊ����İ�������
        else//��֮����ǰ����+�����������
            s += weights[i];
        
           }
	     return (day+1) ;
			}
       


