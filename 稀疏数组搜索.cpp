//题目：稀疏数组搜索。有个排好序的字符串数组，其中散布着一些空字符串，编写一种方法，找出给定字符串的位置。
/*思路：二分法，利用题目给出条件，字符串数组已经排序好，只要对字符串数组进行不
断地收缩边界和比较中值就可以判断目标字符串的位置，如果轮询没有找到则返回-1*/
#include<stdio.h>
#include<string.h>
int findString(char words[20][10], int wordsSize, char s[]); 
int main()
{
	char words[20][10] = {{"at"},{""},{""},{""}, {"ball"},{ ""},{""}, {"car"},{""},{""},{"dad"},{""},{""}};
	char s[10];
	int wordsSize = sizeof(words)/sizeof(words[0]);
	printf("输入字符串s:");
	scanf("%s",s);
	int index = findString( words,  wordsSize, s);
	printf("index = %d",index);
 } 
int findString(char words[20][10], int wordsSize, char s[]){
    int left=0,right=wordsSize-1;

    while(left<=right){
        //收缩边界直到边界均不为空为止
        while(strlen(words[right])==0){
            right--;
        }
        while(strlen(words[left])==0){
            left++;
        }
        int mid=(right+left)/2;
        //将mid指向一个不为空的字符串
        while(strlen(words[mid])==0){
            mid++;
        }
        //使用中点字符串和目标字符串进行比较
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
//暴力法，直接轮询所有字符串，如果当前字符串等于目标字符串，则返回下标，如果轮询完不存在，则返回-1
//int findString(char** words, int wordsSize, char* s){
//    for(int i=0;i<wordsSize;i++){
//        //判断字符串是否为空
//        if(strlen(words[i])!=0)
//            //判断长度是否相同
//            if(strlen(words[i]) == strlen(s))
//                //判断字符串是否完全相同
//                if(!strcmp(words[i],s))
//                    return i;
//    }
//
//    return -1;
//}
