/*��Ŀ�����ǰѷ����������Ե�����A����ɽ����
A.length >= 3���� 0 < i?< A.length - 1 ʹ��
A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > .
.. > A[A.length - 1]����һ��ȷ��Ϊɽ�������飬
�����κ�����?A[0] < A[1] < ... A[i-1] < A[i] 
> A[i+1] > ... > A[A.length - 1]�� i ��ֵ��*/
//˼·�� ���ֲ��ҷ� 
#include<stdio.h>
#include<string.h> 
int peakIndexInMountainArray(int MountainArray[20],int len); 
int main()
{

	int MountainArray[20] = {1,2,3,4,5,6,7,8,9,4,3,2,1};
	int len = sizeof(MountainArray)/sizeof(MountainArray[0]);
	int result = peakIndexInMountainArray( MountainArray,len );
	printf("ɽ�����±� = %d",result);
	return 0;
	
}

int peakIndexInMountainArray(int MountainArray[20],int len) {
        int l = 0, h = len - 1;
        while (l < h) {
            int mid = l + (h - l) / 2;
            if (MountainArray[mid] < MountainArray[mid + 1])
                l = mid + 1;
            else
                h = mid;
        }
        return l;
    }
//����ɨ�� 
		int i=0;
		while(A[i]<A[i+1]) i++;
		return i;


