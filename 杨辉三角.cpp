/*��Ŀ������һ���Ǹ����� numRows������������ǵ�ǰ numRows �С�*/
/*����malloc������������̬�滮������Ķ�ά����ռ䣬����ÿ�е���βԪ�ظ�ֵΪ1
����numRows���ڵ���2ʱ������ ret[i][j]=ret[i-1][j-1]+ret[i-1][j]������ 
2<=i<numRows��1<=j<i )����������ӡ����*/ 
#include<stdio.h>
#include<stdlib.h> 
int main(){
    int i,j,m;
    int numRows;
    printf("����һ���Ǹ�������");
    scanf("%d",&numRows);
    while(numRows < 0){
    	printf("���ٴ�����:");
    	 scanf("%d",&numRows);
	}
//��ʼ�� 
    int**ret=(int**)malloc(sizeof(int*)*numRows);//����
    for(i=0;i<numRows;++i){
        ret[i]=(int*)malloc((i+1)*sizeof(int));
        ret[i][0]=1;
        ret[i][i]=1;
    }
//��ֵ 
    for(i=2;i<numRows;++i)
        for(j=1;j<i;++j)
            ret[i][j]=ret[i-1][j-1]+ret[i-1][j];
//��ӡ          
    for (i=0;i<numRows;i++){
	    for(m=0;m<=(numRows-i-1)/2;m++){
		        printf(" ");
				}
        for(j=0;j<=i;j++){
           printf("%4d",ret[i][j]);
       }
           printf("\n");}
       
}


