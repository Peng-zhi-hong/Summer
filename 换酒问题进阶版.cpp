/*��Ŀ��ơ��ÿƿpԪ��cap��ƿ�ǻ���bottle���վ�ƿ���Ի�һƿơ�ƣ���ƿ�ǻ��߿վ�
ƿ�����Ի�ȡһƿƿ��ʱ�������̼ҽ�����ƿ�ǻ��߿վ�ƿ��ֻҪ�ܹ���
���ϣ����ʸ���bԪ�������Ժȶ���ƿƿ�ƣ�*/
/*˼·�����������������ܹ��ȵ�Nƿơ�ƣ���ôƿ��N�͸�����Ǯ��M����ƿ�Ƶ���P
���ɻ�ƿ�Ƶĸ�����cap�Ϳ�ƿ��bottle��������Ĺ�ϵ��N=N/cap+N/bottle+M/p.
����ʽ�ӻ���ģ�N=M/P*cap*bottle/(cap*bottle-cap-bottle)��*/ 
#include<stdio.h>
int  SumBeer(int m, int p, int cap, int bottle); 
int main() {
        int m , p , cap , bottle ;
        printf("����Ǯ����ơ�Ƶ��ۣ��ɻ�ơ�Ƶ�ƿ������ƿ������");
        scanf("%d%d%d%d",&m,&p,&cap,&bottle);
        if(m >= p){
        if(cap > 1&&bottle >1){
        int drink_sum = SumBeer(m, p, cap, bottle);
        printf("�ܹ����Ժ�%dƿ",drink_sum);
    }
        else
        printf("�������޺ȣ�");
    }
    else
    printf("һƿ��Ҳ���𣬱�����ˡ�");
	}

int  SumBeer(int m, int p, int cap, int bottle) {
        if (m >= p) {
            return (m / p) * cap * bottle / (cap * bottle - cap - bottle);
            
        } else {

            return 0;
        }
    }
