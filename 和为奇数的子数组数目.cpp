/*题目： 给你一个整数数组 num 。请你返回和为 奇数 的子数组数目。由于答案可能
会很大，请你将结果对 10^9 + 7 取余后返回*/ 
/*思路：两个计数器odd，even,初始化为0，判断前缀和为奇数的odd++ ，为偶数的even++
，odd*even+odd即为和为奇数的子数组数目。*/
 #include<stdio.h>
 int main()
 {
 int num[3] = {3,2,1}; 
 int odd = 0;
 int even = 0; 
 int result;    
 int size = sizeof(num)/sizeof(num[0]);
 long long res = 0;
 int sum = 0;
    for (int i = 0;i < size;i++)
        {
            sum += num[i];
            if (sum % 2 == 0)  {
			even++;
           }
            else   {       
			   odd++;
			  }
}
result = odd*even+odd;
printf("和为 奇数 的子数组数目 = %d ",result%1000000007);
}

