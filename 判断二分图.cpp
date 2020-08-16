#include<bits/stdc++.h>
using namespace std;

const int M = 10050;
int color[M], line[M][M];

//0为白，1为黑
bool bfs(int s, int n){
    int i, beg;
    queue <int> q;
    q.push(s);
    color[s] = 1;
    while(!q.empty()){
        beg = q.front();
        q.pop();
        for(i = 1; i <= n; i++){
            if(line[beg][i] && color[i] == 0){
                q.push(i);
                color[i] = !color[beg];//染成不同颜色
            }
            if(line[beg][i] && color[beg] == color[i]){//颜色相同则不是二分图
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    int i, j, n, m, a, b;//n表示有多少个点，m表示有多少条边
    bool flag = 1;//初始化无向图是二分图
    memset(color, 0, sizeof(color));
    scanf("%d%d", &n, &m);
    for(i = 1; i <= m; i++) {
        cin >> a >> b;
        line[a][b] = line[b][a] = 1;//存储无向图的边
    }
    for(i = 1; i <= n; i++)
        if(color[i] == 0 && !bfs(i, n)) {//对每个连通分支染色，如果两个相邻的点颜色相同，则不是二分图。
            flag = 0;
            break;
        }
    if(flag)
        cout << "YES" <<endl;
    else
        cout << "NO" <<endl;
    return 0;
}
