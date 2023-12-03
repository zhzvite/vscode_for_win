//数组越界了则什么错误都有可能发生
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
const int N = 1e5 + 10;
int n1,n2 ,m,res;
int h[N], e[N], ne[N], idx;
int match[N];
bool st[N];
void add(int a, int b) {
	e[idx] = a, ne[idx] = h[a], h[a] = idx++;
}
bool find(int x) {
	for (int i = h[x]; ~i; i = ne[i]) {
		int j = e[i];
		if (!st[j]) {
			st[j] = true;
			if (match[j] == 0 || find(match[j])) {
				match[j] = x;
				return true;
			}
		}
	}
	return false;
}
int main() {
	cin >> n1 >> n2 >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	for (int i = 1; i <= n1; i++) {
		memset(st, false, sizeof st);
		if (find(i))res++;
	}
	cout << res;
	return 0;
}
/*
2 2 4
1 1
1 2
2 1
2 2
*/
// 2


