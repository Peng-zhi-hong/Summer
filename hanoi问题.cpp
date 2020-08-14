
#include <iostream>
#include <cstdio>
using namespace std;
 
int cnt;
 
void move(int id, char from, char to) // 打印移动方式：编号，从哪个盘子移动到哪个盘子
{
    printf ("step %d: move %d from %c->%c\n", ++cnt, id, from, to);
}
 
void hanoi(int n, char x, char y, char z)
{
    if (n == 0)
        return;
    hanoi(n - 1, x, z, y);
    move(n, x, z);
    hanoi(n - 1, y, x, z);
}
 
int main()
{
    int n;
    cnt = 0;
    scanf ("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
 
