/*题目：一个整数数组，每次操作会从中选择一个元素并 将该元素的值减少1。
如果符合下列情况之一，则数组就是 锯齿数组：
每个偶数索引对应的元素都大于相邻的元素，即?A[0] > A[1] < A[2] > A[3] < A[4] > ...
或者，每个奇数索引对应的元素都大于相邻的元素，即?A[0] < A[1] > A[2] < A[3] > A[4] < ...
返回将数组nums转换为锯齿数组所需的最小操作次数。
*/
/* 思路:根据题意，遍历数组，分两种情况讨论，要么将奇数位置的元素减少到刚好比相邻的偶数位置元素小，
要么将偶数位置的元素减少到刚好比相邻的奇数位置元素小。返回两种情况操作较少的作为答案。
*/
#include<stdio.h>
#define max(x,y) (x)>(y)?(x):(y) 
#define min(x,y) (x)>(y)?(y):(x) 
 int main(){
 	int N;
 	printf("输入整数数组的长度:");
 	scanf("%d",&N);
 	int nums[N]={0};
printf("输入%d个整数:\n",N);
 for(int i=0;i<N;i++){
 	scanf("%d",&nums[i]);
 }
 int d1=0,d2=0;
 int s1=0,s2=0;
 for(int i=0;i<N;i++){
 //奇数位置
            if (i % 2 == 0){

            	if ((i > 0 )&& (nums[i] >= nums[i - 1]))
                d1 = nums[i] - nums[i - 1] + 1 ;
				else 
				d1 = 0;
				if ((i < N - 1) && (nums[i] >= nums[i + 1]))
                d2 = nums[i] - nums[i + 1] + 1 ;
			    else 
				d2 = 0;
                s1 += max(d1, d2);//加减的最多的 
				}
//偶数位置
            else{
			
            	if (nums[i] >= nums[i - 1])
                d1 = nums[i] - nums[i - 1] + 1 ;
			    else 
			    d1 = 0 ;
			    
			    if ((i < N - 1 )&& (nums[i] >= nums[i + 1])) 
                d2 = nums[i] - nums[i + 1] + 1 ; 
			    else 
			    d2 = 0 ; 
                s2 += max(d1, d2) ; 
				}

 }
 printf("%d",min(s1,s2));

 }
