/*题目：小Q是一个非常聪明的孩子，除了国际象棋，他还很喜欢玩一个电脑益智游戏――矩阵游戏。
矩阵游戏在一个 [公式] 黑白方阵进行（如同国际象棋一般，只是颜色是随意的）。每次可以对该矩阵
进行两种操作：行交换操作：选择矩阵的任意两行，交换这两行（即交换对应格子的颜色）列交换操作：
选择矩阵的任意两列，交换这两列（即交换对应格子的颜色）游戏的目标，即通过若干次操作，使得方阵
的主对角线(左上角到右下角的连线)上的格子均为黑色。对于某些关卡，小Q百思不得其解，以致他开始怀
疑这些关卡是不是根本就是无解的！于是小Q决定写一个程序来判断这些关卡是否有解。*/
#include <cstdio>
#include <cstring>
int Map[205][205], p[205], vis[205], N, T;
bool match(int i)
{
    for (int j = 1; j <= N; ++j)
    {
        if (Map[i][j] && !vis[j])
        {
            vis[j] = 1;
            if (p[j] == 0 || match(p[j]))
            {
                p[j] = i;
                return true;
            }
        }
    }
    return false;
}
int Hungarian()
{
    int cnt = 0;
    for (int i = 1; i <= N; ++i)
    {
        memset(vis, 0, sizeof(vis));
        if (match(i))
            cnt++;
    }
    return cnt;
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &N);
        memset(p, 0, sizeof(p));
        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= N; ++j)
                scanf("%d", &Map[i][j]);
        puts(Hungarian() == N ? "Yes" : "No");
    }
    return 0;
}
