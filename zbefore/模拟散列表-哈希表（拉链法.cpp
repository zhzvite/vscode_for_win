//拉链法
#include<iostream>
using namespace std;
const int N = 100003;//一般mol的数要选择一个质数
int h[N],e[N],ne[N],idx;
void insert(int x) {
	//将x映射到哈希函数上
	int k = (x % N + N) % N;
	e[idx] = x, ne[idx] = h[k], h[k] = idx++;//单链表的插入
}
bool find(int x) {
	int k = (x % N + N) % N;//k是映射到哈希函数上的值，使得复数mol完后变成一个整数，在c++中负数mol完会变成负数
	for (int i = h[k]; i != -1; i = ne[i]) {
		if (e[i] == x)
			return true;}
	return false;//return false 是最后的判断，若是找不到就返回false
}
int main() {
	int n;
//	cout << -10 % 3 << endl;
//  cout << 10 % -5<<endl;
	cin >> n;
	memset(h, -1, sizeof h);//所有初始化,初始化为-1,拉链法
	//for (int i = 0; i < N; i++)cout << h[i] << endl;//判断所有的初始之都是-1
	while (n--) {
		char op[2];
		int x;
		cin >> op >> x;
		if (op[0] == 'I')insert(x);
		else {
			if (find(x))cout << "yes"<<endl;
			else cout << "No"<<endl;
		}

	}
	return 0;
}
/*
5 
I 1
I 2
I 3
Q 2
Q 5
*/
