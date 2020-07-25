/*题目：给你一个大小为?m* n的方阵?mat，方阵由若干军人和平民组成，分别用
 1 和 0 表示。请你返回方阵中战斗力最弱的k行的索引，按从最弱到最强排序。
如果第i行的军人数量少于第j行，或者两行军人数量相同但 i 小于 j，那么我
们认为第 i 行的战斗力比第j行弱。军人 总是 排在一行中的靠前位置，也就是
说 1 总是出现在 0 之前。*/ 

/*思路:本题采用 快速排序法，其中采用了一个特殊的技巧，就是将下标和下标对应的数值
进行合并，再之后快速排序时，可以让下标和数值同时影响结果，方法是将数值乘以数组长
度再加上下标值，这样的话，数值不同时按数值排序，数值相同时按照下标排序，最后结果
对数组长度取余就可以返回下标，如果需要返回数值可以直接除以数组长度*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*a,const void*b);
int main()
{
	int *returnSize,k,matColSize,matSize;
	int mat[5][5] = {{1,1,0,0,0},{1,1,1,1,0},{1,0,0,0,0},{1,1,0,0,0},{1,1,1,1,1}};
	matSize = sizeof(mat)/sizeof(mat[0]);
	matColSize = sizeof(mat[0])/sizeof(mat[0][0]);
	printf("输入行数:");
	scanf("%d",&k);
	int* res=(int*)calloc(k,sizeof(int));
    int* num=(int*)calloc(matSize,sizeof(int));
    memset(num,0,sizeof(int)*matSize);
    for(int i=0;i<matSize;i++){
        for(int j=0;j<matColSize;j++){
            if(mat[i][j]==1){
                //数组数值乘以数值长度
                num[i]+=matSize;
            }else{
                break;
            }
        }
        //在数值中加上下标
        num[i]+=i;
    }
    qsort(num,matSize,sizeof(int),cmp);
    for(int i=0;i<k;i++){
        //返回时对数组长度取余返回下标
        res[i]=num[i]%matSize;
    }
	for(int i=0;i<k;i++)
	printf("%d",res[i]);
}
int cmp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}



