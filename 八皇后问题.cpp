/*题目:八皇后问题是一个古老而著名的问题。该问题是19世纪著名的数学家高斯1850年提出：
在一个8*8国际象棋盘上，有8个皇后，每个皇后占一格；要求皇后之间不会出现相互“
攻击”的现象，即不能有两个皇后处在同一行、同一列或同一对角线上。问共有多少种
不同的方法？*/
/*思路:八皇后问题的回溯法算法，可以采用一维数组来进行处理。数组的下标i表示棋盘
上的第i列，a[i]的值表示皇后在第i列所放的位置。例如，a[1]=5，表示在棋盘的第例的
第五行放一个皇后。程序中首先假定a[1]=1，表示第一个皇后放在棋盘的第一列的第一行
的位置上，然后试探第二列中皇后可能的位置，找到合适的位置后，再处理后续的各列，
这样通过各列的反复试探，可以最终找出皇后的全部摆放方法。*/
#include<stdio.h>
#define Queens 8  //定义结果数组的大小，也就是皇后的数目
int a[Queens+1];    //八皇后问题的皇后所在的行列位置，从1幵始算起，所以加1
int main(){
    int i, k, flag, not_finish=1, count=0;
    //正在处理的元素下标，表示前i-1个元素已符合要求，正在处理第i个元素
    i=1;
    a[1]=1;  //为数组的第一个元素赋初值
    printf("The possible configuration of 8 queens are:\n");
    while(not_finish){  //not_finish=l:处理尚未结束
        while(not_finish && i<=Queens){  //处理尚未结束且还没处理到第Queens个元素
            for(flag=1,k=1; flag && k<i; k++) //判断是否有多个皇后在同一行
                if(a[k]==a[i])
                    flag=0;
            for (k=1; flag&&k<i; k++)  //判断是否有多个皇后在同一对角线
                if( (a[i]==a[k]-(k-i)) || (a[i]==a[k]+(k-i)) )
                    flag=0;
            if(!flag){  //若存在矛盾不满足要求，需要重新设置第i个元素
                if(a[i]==a[i-1]){  //若a[i]的值已经经过一圈追上a[i-1]的值
                    i--;  //退回一步，重新试探处理前一个元素
                    if(i>1 && a[i]==Queens)
                        a[i]=1;  //当a[i]为Queens时将a[i]的值置1
                    else
                        if(i==1 && a[i]==Queens)
                            not_finish=0;  //当第一位的值达到Queens时结束
                        else
                            a[i]++;  //将a[il的值取下一个值
                }else if(a[i] == Queens)
                    a[i]=1;
                else
                    a[i]++;  //将a[i]的值取下一个值
            }else if(++i<=Queens)
                if(a[i-1] == Queens )
                    a[i]=1;  //若前一个元素的值为Queens则a[i]=l
                else
                    a[i] = a[i-1]+1;  //否则元素的值为前一个元素的下一个值
        }
        if(not_finish){
            ++count;
            printf((count-1)%3 ? "\t[%2d]:" : "\n[%2d]:", count);
            for(k=1; k<=Queens; k++) //输出结果
                printf(" %d", a[k]);
            
            if(a[Queens-1]<Queens )
                a[Queens-1]++;  //修改倒数第二位的值
            else
                a[Queens-1]=1;
            i=Queens -1;    //开始寻找下一个满足条件的解
        }
    }
}
