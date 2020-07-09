//ͬ�ඨ����������ͬʱ����һ�������õ���������ͬ���������ͬ�ࡣ����a �� b(mod m)��
/*ͬ�ඨ��ļӷ��˷�Ӧ��

(a + b) % m = (a % m + b % m) % m

�� a = k1 * m + r1��b = k2 * m + r2
�� (a + b) % m = ((k1 * m + r1) + (k2 * m + r2)) % m
               = ((k1 + k2) * m + (r1 + r2)) % m
               = (r1 + r2) % m
               = (a % m + b % m) % m
���� (a + b) % m = (a % m + b % m) % m

(a * b) % m = ((a % m) * (b % m)) % m

�� a = k1 * m + r1��b = k2 * m + r2
�� (a * b) % m = ((k1 * m + r1) * (k2 * m + r2)) % m
               = (k1 * k2 * m^2 + (k1 * r2 + k2 * r1) * m + r1 * r2) % m
               = (r1 * r2) % m
               = ((a % m) * (b % m)) % m
���� (a * b) % m = ((a % m) * (b % m)) % m  */
//ͬ�ඨ���Ӧ�� 
//�߾���ȡģ

/*#include<iostream>
#include<string>
using namespace std;
 
int main(){
    string a;
    int b;
    cin >> a >> b;
    int len = a.length();
    int ans = 0;
    for(int i = 0; i < len; i++){
        ans = (ans * 10 + a[i] - '0') % b;
    }
    cout << ans << endl;
    return 0;}*/
    
//������ȡģ
#include<iostream>
using namespace std;
 
int PowerMod(int a, int b, int c){
    int ans = 1;
    a = a % c;
    while(b > 0){
        if(b&1){
            ans *= (a % c);
        }
        b >>= 1;
        a = (a * a) % c;
    }
    ans %= c;
    return ans;
}
 
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << PowerMod(a, b, c) << endl;
    return 0;
}
