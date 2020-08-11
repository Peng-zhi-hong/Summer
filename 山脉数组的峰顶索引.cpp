/*题目：我们把符合下列属性的数组A称作山脉：
A.length >= 3存在 0 < i?< A.length - 1 使得
A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > .
.. > A[A.length - 1]给定一个确定为山脉的数组，
返回任何满足?A[0] < A[1] < ... A[i-1] < A[i] 
> A[i+1] > ... > A[A.length - 1]的 i 的值。*/
//思路： 二分查找法 
#include<stdio.h>
#include<string.h> 
int peakIndexInMountainArray(int MountainArray[20],int len); 
int main()
{

	int MountainArray[20] = {1,2,3,4,5,6,7,8,9,4,3,2,1};
	int len = sizeof(MountainArray)/sizeof(MountainArray[0]);
	int result = peakIndexInMountainArray( MountainArray,len );
	printf("山顶的下标 = %d",result);
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
//线性扫描 
		int i=0;
		while(A[i]<A[i+1]) i++;
		return i;


