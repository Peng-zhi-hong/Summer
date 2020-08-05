/*题目：给你一个字符串 sentence 作为句子并指定检索词为 searchWord ，其中句子
由若干用 单个空格 分隔的单词组成。请你检查检索词 searchWord 是否为句子 sentence
中任意单词的前缀。如果searchWord 是某一个单词的前缀，则返回句子sentence 中该单
词所对应的下标（下标从 1 开始）。如果 searchWord 是多个单词的前缀，则返回匹配的
第一个单词的下标（最小下标）。如果 searchWord 不是任何单词的前缀，则返回 -1 。
字符串 S 的 「前缀」是 S 的任何前导连续子字符串。*/


/*思路：1、先用strtok分隔
        2、再用strstr查找：注意strstr的返回值
// 函数名: strstr
// 函数原型：
// extern char *strstr(char *str1, char *str2);
// 功能：找出str2字符串在str1字符串中第一次出现的位置（不包括str2的串结束符）。
// 返回值：返回该位置的指针，如找不到，返回空指针。
*/

// 方法一：实际是对方法二的优化，省去了对分隔单词的保存，分隔的同时直接判断
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
int isPrefixOfWord(char *sentence, char *searchWord);
//int isPrefixOfWord(char *sentence, char *searchWord)
//{
//    int cnt = 1;
//    char *token = NULL;
//    const char space[2] = " ";
//
//    /* 获取第一个子字符串，使用空格分隔 */
//    token = strtok(sentence, space);
//    /* 继续获取其他的子字符串 */
//    while (token != NULL ) {
//        if (strstr(token, searchWord) == token) {
//            return cnt;
//        }
//        cnt++;
//        token = strtok(NULL, space);
//    }
//
//    return -1;
//}
int main()
{
	char sentence[40],searchWord[10];
	gets(sentence);
	gets(searchWord);
	int index =isPrefixOfWord(sentence, searchWord);
	if(index == -1)
	printf("没找到");
	else
	printf("index = %d",index);
	
	
}
// 方法二：保存分隔后的单词，然后统一遍历判断


struct word_s {
    char *word; // 单词本身
};
struct word_s g_words[100];

int isPrefixOfWord(char *sentence, char *searchWord)
{
    int i;
    int cnt = 0;
    char *token = NULL;
    const char space[2] = " ";

    memset(g_words, 0, sizeof(struct word_s) * 100);

    /* 获取第一个子字符串，使用空格分隔 */
    token = strtok(sentence, space);
    /* 继续获取其他的子字符串 */
    while (token != NULL ) {
        // printf("%s\n", token);
        g_words[cnt].word =(char*) malloc(sizeof(char) * (strlen(token) + 1));
        if (g_words[cnt].word == NULL) {
            return NULL;
        }
        memset(g_words[cnt].word, 0, sizeof(char) * (strlen(token) + 1));
        strcpy(g_words[cnt].word, token);
        cnt++;
        token = strtok(NULL, space);
    }
    
    // 查找
    for (i = 0; i < cnt; i++) {
        if (strstr(g_words[i].word, searchWord) == g_words[i].word) {
            return i + 1;
        }
    }
    
    return -1;
}


