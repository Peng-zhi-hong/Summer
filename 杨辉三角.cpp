/*题目：给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。*/
/*利用malloc（）函数，动态规划出所需的二维数组空间，并把每行的首尾元素赋值为1
，当numRows大于等于2时，满足 ret[i][j]=ret[i-1][j-1]+ret[i-1][j]（其中 
2<=i<numRows，1<=j<i )，最后遍历打印即可*/ 
#include<stdio.h>
#include<stdlib.h> 
int main(){
    int i,j,m;
    int numRows;
    printf("输入一个非负整数：");
    scanf("%d",&numRows);
    while(numRows < 0){
    	printf("请再次输入:");
    	 scanf("%d",&numRows);
	}
//初始化 
    int**ret=(int**)malloc(sizeof(int*)*numRows);//声明
    for(i=0;i<numRows;++i){
        ret[i]=(int*)malloc((i+1)*sizeof(int));
        ret[i][0]=1;
        ret[i][i]=1;
    }
//赋值 
    for(i=2;i<numRows;++i)
        for(j=1;j<i;++j)
            ret[i][j]=ret[i-1][j-1]+ret[i-1][j];
//打印          
    for (i=0;i<numRows;i++){
	    for(m=0;m<=(numRows-i-1)/2;m++){
		        printf(" ");
				}
        for(j=0;j<=i;j++){
           printf("%4d",ret[i][j]);
       }
           printf("\n");}
       
}


