/*��Ŀ������һ���������飬������������֮��ĵ� k ����С���롣һ�� (A, B) �ľ��뱻����Ϊ A �� B ֮��ľ��Բ�ֵ��*/ 
/*�ȶ�ԭ������������β�����Ϊ����ֵ��ʼֵhigh����С��ֵ��ʼֵΪlow��
ÿ��ȡ����ֵ����С��ֵ����ֵmid���ж�С����ֵ�ĸ���count:
��countС��k����mid = (mid + 1 + r) / 2;
��count����k����mid = (l + mid) / 2;
����ȡ��ֵ���Ƚ�k��n��ֱ��l<=r
*/
#include<stdio.h>
#include<math.h>

int main()
{
int k;
int temp;
int nums[3]={1,3,1};
int len = sizeof(nums);
//���� 
	for(int i = 0;i < len-1;i++)
	for(int j = 0;j < len-i;j++)
	if(nums[j] > nums[j+1])
	{
	   temp = nums[j];
	   nums[j] = nums[j+1];
	   nums[j+1] = temp;
	   }
//���ֲ��� 
	   int low=nums[1]-nums[0];
        int high=nums[len-1]-nums[0];

        while(low<high){
            int mid=(low+high)/2;
            int count=0;
            int r= len-1;
           
    for (int i = len - 2; i >= 0; i--) {
        while (r > i && nums[r] - nums[i] > mid) {
            r--;
        }
        count += r - i;
    }


            if(count>=k){
                high=mid;
            }else{
                low=mid+1;
            }
			} 
		

	scanf("%d",&k);
	printf("%d",low);
	

} 


