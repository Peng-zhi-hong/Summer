/*��̬�滮��״̬�ռ�dp�Ƕ�ά״̬�ռ����飬��word1��word2�ſ����ʼ��һλ���ַ�����

dp[i][j] ����word1��ǰi - 1���ַ����Ӵ���word2��ǰj - 1���ַ����Ӵ��ı༭���롣

����򵥽����ǣ���Ӧ�ַ���ͬ���ñ༭���ַ���ͬ����Ҫ�༭��״̬ת��Ϊ��

�����ұߵ��ַ���ͬ�����ñ༭�ַ����˻���������һ���ַ���״̬��

dp[i][j] = dp[i - 1][j - 1]

�����ұߵ��ַ���ͬ����ͨ��һ����ɾ���滻��������ϵ������״̬��

dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1])

����dp[i-1][j] ��ɾ��������dp[i][j-1] �ǲ��������dp[i-1][j-1] ���滻������*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

static inline int min(int a, int b, int c)
{
    int d = a < b ? a : b;
    return d < c ? d : c;
}

int minDistance(char * word1, char * word2){
    /*
     * ״̬���̣�case1:word1��word2��Ȼ��� => dp[i][j] = dp[i - 1][j - 1]
     *          case2:word1�ɲ��롢ɾ�����滻���word2 => dp[i][j] = 1 + 
	 MIN{dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}
     * �߽�������dp[0][j] = j, dp[i][0] = i
     * ��ʼ������dp[0][0] = 0 ���ճ�һ��
     */

    int row = 0;
    int col = 0;
    int lenOfWord1Row = strlen(word1);
    int lenOfWord2Col = strlen(word2);

    // ÿ�����Ϊһά�����˳���
    int** dp = (int**)malloc((lenOfWord1Row + 1) * sizeof(int*));
    for (row = 0; row <= lenOfWord1Row; row++)
    {
        dp[row] = (int*)malloc((lenOfWord2Col + 1) * sizeof(int));
    }

    // ��ʼ�������߽�����
    for (row = 0; row <= lenOfWord1Row; row++)  
    {
        dp[row][0] = row;
    }

    for (col = 1; col <= lenOfWord2Col; col++)
    {
        dp[0][col] = col;
    }

    // ״̬ת�Ʒ���
    for (row = 1; row <= lenOfWord1Row; row++ )
    {
        for (col = 1; col <= lenOfWord2Col; col++ )
        {
            if (word1[row - 1] == word2[col - 1])
            {
                dp[row][col] = dp[row - 1][col - 1];
            }
            else
            {
                dp[row][col] = 1 + min(dp[row][col - 1], dp[row - 1][col], dp[row - 1][col - 1]);
            }
        }
    }

    return dp[lenOfWord1Row][lenOfWord2Col];
}
int main()
{
	char * word1 = "hello everyone!";
	char * word2 = "hello everybody!";
	int mindistance = minDistance(word1,word2);
	printf("%d",mindistance);
}
 

