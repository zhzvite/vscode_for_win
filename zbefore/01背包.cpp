#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int v[N], w[N];
int f[N];//本来是二维这里对其进行优化
int n, m;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)cin >> v[i] >> w[i];//从第一个开始存放
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >=v[i]; j--) {
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	}cout << f[m];//返回的是体的最积最大为m时的最大价值
}
/*
4 5
1 2
2 4
3 4
4 5
*/
//8