/*题目：一个岛屿是由一些相邻的1(代表土地) 构成的组合，这里的「相邻」要求两个 
1 必须在水平或者竖直方向上相邻。你可以假设grid 的四个边缘都被 0（代表水）包围着。
找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)
*/
/*思路：如果grid为空，就返回零，不为空，遍历其元素，如果元素为1，递归调用，判断这个元素上下左右元素是否为1,
（不能溢出）如果为0，返回0，每找到返回的岛屿面积要与ans比较，较大值赋值给ans，遍历结束，输出ans，即最大岛屿面积*/ 
#include<stdio.h>
int dfs(int i,int j,int grid[2][2],int m,int n);
#define max(x,y) x>y ? x:y
int main(){ 

	int grid[2][2]={1,0,1,0};
        int m = sizeof(grid)/sizeof(grid[0]);
        if (m == 0)
        int ans = 0; 
        int n = sizeof(grid[0])/sizeof(grid[0][0]);
        int ans = 0;
        int i,j;
		for(i =0 ;i < m; i++)
			for(j = 0;j <n;j++){
  int q = dfs(i,j,grid,m,n);
   ans = max(ans,q);}//如果直接ans=max(ans,dfs(i,j,grid,m,n)结果会出错，当用q来接收函数dfs调用的值，再来用max（ans，q）结果就正确了
   printf("岛屿的最大面积=%d\n",ans);
	   return 0;
} 
int dfs(int i,int j,int grid[2][2],int m,int n){

if ((0<=i<m) && (0<=j<n) && (grid[i][j] == 1)){
                grid[i][j] = 0; 
          return 1+dfs(i + 1, j,grid,m,n) + dfs(i - 1, j,grid,m,n) + dfs(i, j - 1,grid,m,n) + dfs(i, j + 1,grid,m,n);}   
else  
		   return 0; 
        }

