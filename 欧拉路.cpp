/*��������:
��һ��n��m����n���㣬m���ߣ�����m������ÿ�������ӵ����㡣
    5 5
    1 2
    2 3
    3 4
    4 5
    5 1
�������:ŷ��·��ŷ����·
    1 5 4 3 2 1
*/
#include<iostream>
#include<cstring>
using namespace std;
#define maxn 100
int g[maxn][maxn];               //�������
int du[maxn];                    //��¼һ�������˼�����
int circuit[maxn];               //��¼ŷ����·
int n,m,circuitpos,i,j,x,y,start;
void find_circuit(int i)         //��¼����һ�����ŷ����·
{
    int j;
    for(j=1;j<=n;j++)
    if(g[i][j]==1)
    {
        g[i][j] = g[j][i] = 0;           //��¼������ͨ�������ǵ�֮��·�����
        find_circuit(j);
    }
    circuit[++circuitpos] = i;
}
int main()
{
	int i;
    memset(g,0,sizeof(g));
    cout<<"��n���㣬m����:";
    cin>>n>>m;
    cout<<"����ÿ���ߵ���������:";
    for ( i=1 ;i<=m ;i++)
    {
        cin>>x>>y;
        g[x][y] = g[y][x] =1;
        du[x]++;
        du[y]++;
    }
    start = 1;
    for(i =1 ; i<=n ;i++)
    if(du[i]%2==1)                      //ż�����޷��жϴ�·���Ƿ񱻼�¼����˴�������
       start = i;                      //��ʼ�ң��ҵ����������뺯������¼��					
    circuitpos = 0;
    find_circuit(start);
    for(i=1;i<=circuitpos;i++)
    cout<<circuit[i]<<endl;
}
