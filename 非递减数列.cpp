/*给你一个长度为?n?的整数数组，请你判断在 最多 改变?1 个元素的情况下，该数组能否变成一个非递减数列。
我们是这样定义一个非递减数列的：?对于数组中所有的?i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。
*/  
#include<stdio.h>
int main(){
int nums[5] = {1,2,0,4,0};
int count = 0;
        for(int i=0;i<sizeof(nums)/sizeof(nums[0])-1;i++){
            if(nums[i] > nums[i+1]){
                count++;
                if(count > 1){
                    break;
                }
                 //if (nums[i+1] < nums[i-1] && nums[i-2] > nums[i])
                if(i == 0){
				if(nums[0] > nums[1])
				nums[0] = nums[1]; }
                if(i>0&&nums[i-1] > nums[i+1]){
                    nums[i+1] = nums[i];
                }else{
                    nums[i] = nums[i+1];
                }
            }
        }
        if(count > 1)
        printf("不满足");
        else
        printf("满足");}
   


