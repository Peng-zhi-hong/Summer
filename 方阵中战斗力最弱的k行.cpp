/*��Ŀ������һ����СΪ?m* n�ķ���?mat�����������ɾ��˺�ƽ����ɣ��ֱ���
 1 �� 0 ��ʾ�����㷵�ط�����ս����������k�е�������������������ǿ����
�����i�еľ����������ڵ�j�У��������о���������ͬ�� i С�� j����ô��
����Ϊ�� i �е�ս�����ȵ�j���������� ���� ����һ���еĿ�ǰλ�ã�Ҳ����
˵ 1 ���ǳ����� 0 ֮ǰ��*/ 

/*˼·:������� �������򷨣����в�����һ������ļ��ɣ����ǽ��±���±��Ӧ����ֵ
���кϲ�����֮���������ʱ���������±����ֵͬʱӰ�����������ǽ���ֵ�������鳤
���ټ����±�ֵ�������Ļ�����ֵ��ͬʱ����ֵ������ֵ��ͬʱ�����±����������
�����鳤��ȡ��Ϳ��Է����±꣬�����Ҫ������ֵ����ֱ�ӳ������鳤��*/
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
	printf("��������:");
	scanf("%d",&k);
	int* res=(int*)calloc(k,sizeof(int));
    int* num=(int*)calloc(matSize,sizeof(int));
    memset(num,0,sizeof(int)*matSize);
    for(int i=0;i<matSize;i++){
        for(int j=0;j<matColSize;j++){
            if(mat[i][j]==1){
                //������ֵ������ֵ����
                num[i]+=matSize;
            }else{
                break;
            }
        }
        //����ֵ�м����±�
        num[i]+=i;
    }
    qsort(num,matSize,sizeof(int),cmp);
    for(int i=0;i<k;i++){
        //����ʱ�����鳤��ȡ�෵���±�
        res[i]=num[i]%matSize;
    }
	for(int i=0;i<k;i++)
	printf("%d",res[i]);
}
int cmp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}



