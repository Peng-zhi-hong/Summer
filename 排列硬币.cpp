/*��Ŀ�����ܹ��� n öӲ�ң�����Ҫ�����ǰڳ�һ��������״����k�оͱ���������köӲ�ҡ�
����һ������n���ҳ����γ����������е���������n��һ���Ǹ�������������32λ�з������͵ķ�Χ��*/
/*˼·������Ϊ0�У�����Ϊn�У����ö��ַ������ҵ����⡣*/ 
#include<stdio.h>
int main()
{
int n;
printf("����һ���ж���öӲ�ң�");
scanf("%d",&n); 
    if (n == 0) {
        return 0;
    }
    int left = 0;
    // ֻ�� n ��Ӳ�ҵ�����£����϶����ᳬ�� n �У�����������������Ҳ���޶�Ϊ n
    int  right = n;
    while (left <= right) {
    	int mid = ((right + left) /2);
    
        // �γ� mid �еĽ���һ����Ҫ costToFinishMid ��Ӳ�ң���������ѧ��ʽ
    	int costToFinishMid = (1 + mid) * mid / 2;
    
    	if(costToFinishMid == n){
		   printf("���γ����������е������� = %d",mid);
	      return 0;
			}
       else if (costToFinishMid < n) {
    		left = mid + 1;
    	} else if (costToFinishMid > n) {
    		right = mid - 1;
    	}
    }
    printf("���γ����������е������� = %d",right);
    return 0;
}

/*�Ȳ�������⣺������ѧ��ʽ��k(k+1) /2 = n�����Եõ���������Ϊ��k = sqrt(2n+1/4) - 1/2��Ȼ���������ɡ�
Ψһ�������ǣ�����2n+1/4�п��ܻᳬ��sqrt�����Ĳ�����Χ��
���ǣ����ǿ��Ա任һ�£� k = sqrt(2) * sqrt(n+1/8) - 1/2��������ƽ�����Ͳ��ᳬ���ˡ�*/


