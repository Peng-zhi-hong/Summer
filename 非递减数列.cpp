/*����һ������Ϊ?n?���������飬�����ж��� ��� �ı�?1 ��Ԫ�ص�����£��������ܷ���һ���ǵݼ����С�
��������������һ���ǵݼ����еģ�?�������������е�?i (0 <= i <= n-2)�������� nums[i] <= nums[i + 1]��
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
        printf("������");
        else
        printf("����");}
   


