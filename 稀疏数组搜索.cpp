//��Ŀ��ϡ�������������и��ź�����ַ������飬����ɢ����һЩ���ַ�������дһ�ַ������ҳ������ַ�����λ�á�
/*˼·�����ַ���������Ŀ�����������ַ��������Ѿ�����ã�ֻҪ���ַ���������в�
�ϵ������߽�ͱȽ���ֵ�Ϳ����ж�Ŀ���ַ�����λ�ã������ѯû���ҵ��򷵻�-1*/
#include<stdio.h>
#include<string.h>
int findString(char words[20][10], int wordsSize, char s[]); 
int main()
{
	char words[20][10] = {{"at"},{""},{""},{""}, {"ball"},{ ""},{""}, {"car"},{""},{""},{"dad"},{""},{""}};
	char s[10];
	int wordsSize = sizeof(words)/sizeof(words[0]);
	printf("�����ַ���s:");
	scanf("%s",s);
	int index = findString( words,  wordsSize, s);
	printf("index = %d",index);
 } 
int findString(char words[20][10], int wordsSize, char s[]){
    int left=0,right=wordsSize-1;

    while(left<=right){
        //�����߽�ֱ���߽����Ϊ��Ϊֹ
        while(strlen(words[right])==0){
            right--;
        }
        while(strlen(words[left])==0){
            left++;
        }
        int mid=(right+left)/2;
        //��midָ��һ����Ϊ�յ��ַ���
        while(strlen(words[mid])==0){
            mid++;
        }
        //ʹ���е��ַ�����Ŀ���ַ������бȽ�
        if(!strcmp(words[mid],s)){
            return mid;
        }else if(strcmp(words[mid],s) < 0){
            left = mid+1;
        }else{
            right = mid-1;
        }
    }
    
    return -1;
}
//��������ֱ����ѯ�����ַ����������ǰ�ַ�������Ŀ���ַ������򷵻��±꣬�����ѯ�겻���ڣ��򷵻�-1
//int findString(char** words, int wordsSize, char* s){
//    for(int i=0;i<wordsSize;i++){
//        //�ж��ַ����Ƿ�Ϊ��
//        if(strlen(words[i])!=0)
//            //�жϳ����Ƿ���ͬ
//            if(strlen(words[i]) == strlen(s))
//                //�ж��ַ����Ƿ���ȫ��ͬ
//                if(!strcmp(words[i],s))
//                    return i;
//    }
//
//    return -1;
//}
