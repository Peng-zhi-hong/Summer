/*动态规划的状态空间dp是二维状态空间数组，由word1与word2张开（最开始补一位空字符）。

dp[i][j] 代表word1的前i - 1个字符的子串与word2的前j - 1个字符的子串的编辑距离。

题意简单讲就是：对应字符相同则不用编辑，字符不同则需要编辑。状态转移为：

若最右边的字符相同，则不用编辑字符，退化到均减少一个字符的状态：

dp[i][j] = dp[i - 1][j - 1]

若最右边的字符不同，则通过一次增删或替换操作，联系到其它状态：

dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1])

其中dp[i-1][j] 是删除操作，dp[i][j-1] 是插入操作，dp[i-1][j-1] 是替换操作。*/
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
     * 状态方程：case1:word1和word2天然相等 => dp[i][j] = dp[i - 1][j - 1]
     *          case2:word1由插入、删除和替换变成word2 => dp[i][j] = 1 + 
	 MIN{dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}
     * 边界条件：dp[0][j] = j, dp[i][0] = i
     * 初始条件：dp[0][0] = 0 （空出一格）
     */

    int row = 0;
    int col = 0;
    int lenOfWord1Row = strlen(word1);
    int lenOfWord2Col = strlen(word2);

    // 每个结点为一维数组的顺序表
    int** dp = (int**)malloc((lenOfWord1Row + 1) * sizeof(int*));
    for (row = 0; row <= lenOfWord1Row; row++)
    {
        dp[row] = (int*)malloc((lenOfWord2Col + 1) * sizeof(int));
    }

    // 初始条件、边界条件
    for (row = 0; row <= lenOfWord1Row; row++)  
    {
        dp[row][0] = row;
    }

    for (col = 1; col <= lenOfWord2Col; col++)
    {
        dp[0][col] = col;
    }

    // 状态转移方程
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
 

