#include<bits/stdc++.h>
using namespace std;

const int M = 10050;
int color[M], line[M][M];

//0Ϊ�ף�1Ϊ��
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
                color[i] = !color[beg];//Ⱦ�ɲ�ͬ��ɫ
            }
            if(line[beg][i] && color[beg] == color[i]){//��ɫ��ͬ���Ƕ���ͼ
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    int i, j, n, m, a, b;//n��ʾ�ж��ٸ��㣬m��ʾ�ж�������
    bool flag = 1;//��ʼ������ͼ�Ƕ���ͼ
    memset(color, 0, sizeof(color));
    scanf("%d%d", &n, &m);
    for(i = 1; i <= m; i++) {
        cin >> a >> b;
        line[a][b] = line[b][a] = 1;//�洢����ͼ�ı�
    }
    for(i = 1; i <= n; i++)
        if(color[i] == 0 && !bfs(i, n)) {//��ÿ����ͨ��֧Ⱦɫ������������ڵĵ���ɫ��ͬ�����Ƕ���ͼ��
            flag = 0;
            break;
        }
    if(flag)
        cout << "YES" <<endl;
    else
        cout << "NO" <<endl;
    return 0;
}
