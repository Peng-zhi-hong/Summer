/*题目：给定一个整数数组，返回所有数对之间的第 k 个最小距离。一对 (A, B) 的距离被定义为 A 和 B 之间的绝对差值。*/ 
/*先对原数组排序，则收尾相减即为最大差值初始值high，最小差值初始值为low；
每次取最大差值和最小差值的中值mid，判断小于中值的个数count:
若count小于k，则mid = (mid + 1 + r) / 2;
若count大于k，则mid = (l + mid) / 2;
依次取中值，比较k和n，直到l<=r
*/
#include<stdio.h>
#include<math.h>

int main()
{
int k;
int temp;
int nums[3]={1,3,1};
int len = sizeof(nums);
//排序 
	for(int i = 0;i < len-1;i++)
	for(int j = 0;j < len-i;j++)
	if(nums[j] > nums[j+1])
	{
	   temp = nums[j];
	   nums[j] = nums[j+1];
	   nums[j+1] = temp;
	   }
//二分查找 
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


