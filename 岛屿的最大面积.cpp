/*��Ŀ��һ����������һЩ���ڵ�1(��������) ���ɵ���ϣ�����ġ����ڡ�Ҫ������ 
1 ������ˮƽ������ֱ���������ڡ�����Լ���grid ���ĸ���Ե���� 0������ˮ����Χ�š�
�ҵ������Ķ�ά���������ĵ��������(���û�е��죬�򷵻����Ϊ 0 ��)
*/
/*˼·�����gridΪ�գ��ͷ����㣬��Ϊ�գ�������Ԫ�أ����Ԫ��Ϊ1���ݹ���ã��ж����Ԫ����������Ԫ���Ƿ�Ϊ1,
��������������Ϊ0������0��ÿ�ҵ����صĵ������Ҫ��ans�Ƚϣ��ϴ�ֵ��ֵ��ans���������������ans������������*/ 
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
   ans = max(ans,q);}//���ֱ��ans=max(ans,dfs(i,j,grid,m,n)������������q�����պ���dfs���õ�ֵ��������max��ans��q���������ȷ��
   printf("�����������=%d\n",ans);
	   return 0;
} 
int dfs(int i,int j,int grid[2][2],int m,int n){

if ((0<=i<m) && (0<=j<n) && (grid[i][j] == 1)){
                grid[i][j] = 0; 
          return 1+dfs(i + 1, j,grid,m,n) + dfs(i - 1, j,grid,m,n) + dfs(i, j - 1,grid,m,n) + dfs(i, j + 1,grid,m,n);}   
else  
		   return 0; 
        }

