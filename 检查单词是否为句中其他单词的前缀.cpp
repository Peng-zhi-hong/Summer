/*��Ŀ������һ���ַ��� sentence ��Ϊ���Ӳ�ָ��������Ϊ searchWord �����о���
�������� �����ո� �ָ��ĵ�����ɡ������������ searchWord �Ƿ�Ϊ���� sentence
�����ⵥ�ʵ�ǰ׺�����searchWord ��ĳһ�����ʵ�ǰ׺���򷵻ؾ���sentence �иõ�
������Ӧ���±꣨�±�� 1 ��ʼ������� searchWord �Ƕ�����ʵ�ǰ׺���򷵻�ƥ���
��һ�����ʵ��±꣨��С�±꣩����� searchWord �����κε��ʵ�ǰ׺���򷵻� -1 ��
�ַ��� S �� ��ǰ׺���� S ���κ�ǰ���������ַ�����*/


/*˼·��1������strtok�ָ�
        2������strstr���ң�ע��strstr�ķ���ֵ
// ������: strstr
// ����ԭ�ͣ�
// extern char *strstr(char *str1, char *str2);
// ���ܣ��ҳ�str2�ַ�����str1�ַ����е�һ�γ��ֵ�λ�ã�������str2�Ĵ�����������
// ����ֵ�����ظ�λ�õ�ָ�룬���Ҳ��������ؿ�ָ�롣
*/

// ����һ��ʵ���ǶԷ��������Ż���ʡȥ�˶Էָ����ʵı��棬�ָ���ͬʱֱ���ж�
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
//    /* ��ȡ��һ�����ַ�����ʹ�ÿո�ָ� */
//    token = strtok(sentence, space);
//    /* ������ȡ���������ַ��� */
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
	printf("û�ҵ�");
	else
	printf("index = %d",index);
	
	
}
// ������������ָ���ĵ��ʣ�Ȼ��ͳһ�����ж�


struct word_s {
    char *word; // ���ʱ���
};
struct word_s g_words[100];

int isPrefixOfWord(char *sentence, char *searchWord)
{
    int i;
    int cnt = 0;
    char *token = NULL;
    const char space[2] = " ";

    memset(g_words, 0, sizeof(struct word_s) * 100);

    /* ��ȡ��һ�����ַ�����ʹ�ÿո�ָ� */
    token = strtok(sentence, space);
    /* ������ȡ���������ַ��� */
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
    
    // ����
    for (i = 0; i < cnt; i++) {
        if (strstr(g_words[i].word, searchWord) == g_words[i].word) {
            return i + 1;
        }
    }
    
    return -1;
}


