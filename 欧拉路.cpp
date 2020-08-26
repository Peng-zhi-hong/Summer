/*样例输入:
第一行n，m，有n个点，m条边，以下m行描述每条边连接的两点。
    5 5
    1 2
    2 3
    3 4
    4 5
    5 1
样例输出:欧拉路或欧拉回路
    1 5 4 3 2 1
*/
#include<iostream>
#include<cstring>
using namespace std;
#define maxn 100
int g[maxn][maxn];               //储存矩阵
int du[maxn];                    //记录一个点连了几条边
int circuit[maxn];               //记录欧拉回路
int n,m,circuitpos,i,j,x,y,start;
void find_circuit(int i)         //记录其中一个点的欧拉回路
{
    int j;
    for(j=1;j<=n;j++)
    if(g[i][j]==1)
    {
        g[i][j] = g[j][i] = 0;           //记录两个联通点后把他们的之间路径清空
        find_circuit(j);
    }
    circuit[++circuitpos] = i;
}
int main()
{
	int i;
    memset(g,0,sizeof(g));
    cout<<"有n个点，m条边:";
    cin>>n>>m;
    cout<<"输入每条边的两个顶点:";
    for ( i=1 ;i<=m ;i++)
    {
        cin>>x>>y;
        g[x][y] = g[y][x] =1;
        du[x]++;
        du[y]++;
    }
    start = 1;
    for(i =1 ; i<=n ;i++)
    if(du[i]%2==1)                      //偶数点无法判断此路径是否被记录，因此从奇数点
       start = i;                      //开始找，找到奇数点后代入函数做记录。					
    circuitpos = 0;
    find_circuit(start);
    for(i=1;i<=circuitpos;i++)
    cout<<circuit[i]<<endl;
}
