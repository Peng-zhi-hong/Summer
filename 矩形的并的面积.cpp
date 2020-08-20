/*思路：离散化，将组成的图形 按照给定点的横纵坐标划线，这
样就可以将整个要求的图形的面积分成几个小块，然后依次求每
个小块的面积。注意，首先要判断方块在不在包含的范围内。具
体做法就是 先将 横纵坐标从小到大排序，去掉空白的方块，最
后将各小方块相加，求出总面积。*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
 
#define MAXN 210
int flag[MAXN][MAXN];
double x[MAXN];   //保留所有x的坐标
double y[MAXN];   //保留所有y的坐标
 
struct rectangle{
    double a,b;
    double u,v;
}rec[MAXN];
 
int main(){
    int n;
    int i=0,j=0,k;
    double x1,y1,x2,y2;
    cin>>n;
    memset(flag,0,sizeof(flag));
    for(k=0;k<n;k++){
    	cout<<"输入矩形的一对对角坐标:"; 
        cin>>x1>>y1>>x2>>y2;
        rec[j].a = x1;
        rec[j].b = y1;
        rec[j].u = x2;
        rec[j].v = y2;
        j++;
        x[i] = x1;
        y[i] = y1;
        i++;
        x[i] = x2;
        y[i] = y2;
        i++;
    }
    sort(x,x+2*n);
    sort(y,y+2*n);
    for(int h=0;h<n;h++){    //求包含的小矩形
        for(i=0;i<2*n;i++){
            if(x[i]>=rec[h].u)
                break;
            for(j=0;j<2*n;j++){
                if(y[j]>=rec[h].v)
                    break;
                if(x[i]>=rec[h].a && y[j]>=rec[h].b){
                    flag[i][j] = 1;
					}
            }
        }
    }
    double sum = 0;
    for(i=0;i<2*n-1;i++){
        for(j=0;j<2*n-1;j++){
            sum += flag[i][j]*(x[i+1]-x[i])*(y[j+1]-y[j]);
        }
    }
    cout<<"矩形并的面积为:"<<sum<<endl;
    return 0;
}
