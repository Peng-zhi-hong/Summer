//��Ŀ�������æ���һ�����������ҳ��� n �������������ǿ��Ա� a �� b �� c ������ ��������
//1.����ֻ�ܱ�a���� (����һ����a ��������)

 /*˼·�����ֲ���
 ������ȷ��С�ڵ��� K �ĳ�������
 x1 : �ܱ� a �����ĸ���
 x2 : �ܱ� b �����ĸ���
 x3 : �ܱ� c �����ĸ���
 x12 : �ܱ� a �� b �����ĸ���
 x13 : �ܱ� a �� c �����ĸ���
 x23 : �ܱ� b �� c �����ĸ���
 x123 : �ܱ� a �� b �� c �����ĸ���
 �漰֪ʶ��:
 ���Լ��: շת�����
 ��С������: m * n / (m �� n �����Լ��)
 ���С�ڵ��� K �ĳ������� = x1 + x2 + x3 - x12 - x13 - x23 + x123 */
 
#include<stdio.h>
#define min(x,y) x<y?x:y
    // �����Լ�� --  շת�����
	long long int getGCD(long long int a, long long int b){
        if(a == 0 || b == 0){
            return 0;
        }
        if(a < b){
            return getGCD(b, a);
        }
        while(b != 0){
            long long int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    // ����С������
    long long int getLCD(long long int a, long long int b){
        if(a == 0 || b == 0){
            return 0;
        }
        return a /  getGCD(a, b) * b;
    }
    int nthUglyNumber(int n, int a, int b, int c) {
        // ��������˳����Ķ���
        // ���� = a * i / b * j / c * k  i, j, k�ֱ�Ϊ������
        // ��ָ�뷨
        /*
        long long int p1 = 1, p2 = 1, p3 = 1;
        long long int num;
        long long int i = 1;
        while(i <= n){
            long long int n1 = p1 * a;
            long long int n2 = p2 * b;
            long long int n3 = p3 * c;
            long long int maxVal = 0;
            num = min(n1, min(n2, n3));
            if(num == n1){
                // floor ������ȡ��, ceil ������ȡ��
                // ���� a, b, c֮����ܴ��ڽϴ�Ĳ��, ���Կ��ܺܳ�һ��ʱ�䶼��ֻ�ƶ�һ��ָ��, ��ô�������� n1, n2, n3 �Ĳ��ֱ��ǰ��
                long long int dis = floor((double)min(n2 - n1, n3 - n1) / a);
                // ע��: ǰ���������, �п��ܳ����˵� n ����
                // ���: n - i �п���Ϊ 0, ����Ҫ�����������
                if(dis > (n - i)){
                    dis = n - i;
                }
                // Ϊ�˱��� dis = 0, �����ѭ��
                if(dis < 1){
                    dis = 1;
                }
                // ����ͬʱ�ж��ֵ���� num, ���ֱ��д�� if ��, ���п������ i �������
                maxVal = maxVal > dis ? maxVal: dis;
                p1 += dis;
            }
            if(num == n2){
                long long int dis = floor((double)min(n1 - n2, n3 - n2) / b);
                if(dis > (n - i)){
                    dis = n - i;
                }
                if(dis < 1){
                    dis = 1;
                }
                p2 += dis;
                maxVal = maxVal > dis ? maxVal: dis;
            }
            if(num == n3){
                long long int dis = floor((double)min(n1 - n3, n2 - n3) / c);
                if(dis > (n - i)){
                    dis = n - i;
                }
                if(dis < 1){
                    dis = 1;
                }
                maxVal = maxVal > dis ? maxVal: dis;
                p3 += dis;
            }
            i += maxVal;
        }
        return num;
        */
        int min = min(a,b);
		int min_ = min(min,c); 
        long long int left = min_, right = min_*n; 
        long long int ab = getLCD(a, b);
        long long int ac = getLCD(a, c);
        long long int bc = getLCD(b, c);
        long long int abc = getLCD(ab, c);
        while(left < right){
            int mid = left + (right - left) / 2;
            int x1 = mid / a;
            int x2 = mid / b;
            int x3 = mid / c;
            int x12 = mid / ab;
            int x13 = mid / ac;
            int x23 = mid / bc;
            int x123 = mid / abc;
            int num = x1 + x2 + x3 - x12 - x13 - x23 + x123;
            if(num < n) {
                left = mid + 1;
            }else{
                right = mid;
            }
        }
       return left;
    }
int main()
{
	int a,b,c,n;
	printf("����n,a,b,c:");
	scanf("%d%d%d%d",&n,&a,&b,&c);
	int result = nthUglyNumber(n, a, b, c);
	printf("�� n ������ = %d",result);
	return 0;
}

