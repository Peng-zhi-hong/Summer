#include <string.h>
#include<iostream>
using namespace std;
int main(){
int board[10]={1,1,2,6,24,120,720,5040,40320,362880};//0-9的阶乘 
bool book[10];//标记数是否已经出现过
	int num;
	cin>>num;
	int N;
	cin>>N;	N--;
	for(int i=num ; i>=1 ; i--){
		int mid = N/board[i-1]+1;
		for(int j=1 ; j<=mid ; j++){
	
			if(book[j])mid++;
		}
		book[mid] = true;
		cout<<mid;
		N %= board[i-1];
	}
return 0;
    }

