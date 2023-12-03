#include<iostream>
using namespace std;
const int N = 10010;
int m,k,x;
int e[N], l[N], r[N], idx;
//类似单链表进行初始化
void init() {
	//o表示左端点，1表示右端点
	l[1] = 0;
	r[0] = 1;//r表示从左往右，l表示从右往左
	idx = 2;
}
//在下表是k的右边边插入一个点
void addk(int k, int x) {
	e[idx] = x;
	r[idx] = r[k];
	l[idx] = k;
	l[r[k]] = idx;
	r[k] = idx;
	idx++;
}
//删除第k个点
void remove(int k) {
	r[l[k]] = r[k];
	l[r[k]] = l[k];
}
int main() {
	cin >> m;
	while (m--) {
		string    op;
		cin >> op;
		if (op == "R") {
			cin >> x;
			addk(l[1], x);
		}
		else if (op == "L") {
			cin >> x;
			addk(0, x);
		}
		else if (op == "D") {
			cin >> k;
			remove(k+1);
		}
		else if (op == "IL") {
			cin >> k >> x;
			addk(l[k+1], x);
		}
		else {
			cin >> k >> x;
			addk(k + 1, x);
		}

	}
	for (int i =r[0]; i != 1; i = r[i])cout << e[i] << " ";
	return 0;

}
/*
10
R 7
D 1
L 3
IL 2 10
D 3
IL 2 7
L 8
R 9
IL 4 7
IR 2 2
*/
/*
8 7 7 3 2 9
*/