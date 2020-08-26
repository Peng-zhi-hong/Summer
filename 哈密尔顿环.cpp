#include<cstdio>
#include<iostream>
#define MAXN 1005
using namespace std;
int n, m, x, lenth, g[MAXN][MAXN], num[MAXN], ans[MAXN];
bool val[MAXN], visit[MAXN];
void print(){
    for(int i=1;i<lenth;i++) printf("%d ",ans[i]);
    printf("%d\n",ans[lenth]);
}
void dfs(int last, int cur){
    visit[cur] = true;
    ans[++lenth] = cur;
    for(int i=1;i<=n;i++){
        if(g[cur][i] && i==x&&x!=last){
            ans[++lenth] = i;
            print();
            lenth--; 
            //break;
        }
        if(!visit[i]&&g[cur][i]&&(i>cur)) dfs(cur,i);
    }
    lenth--;//???Y 
    visit[cur] = false;//???Y 
}
 
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int u, v;
        scanf("%d%d",&u,&v);
        g[u][v]++;
        g[v][u]++;
    }
    for(x=1;x<=n;x++)
        {
		lenth=0;dfs(0,x);
	    }
    return 0;
}
