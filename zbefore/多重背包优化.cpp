//多重背包的优化,是将这么多件商品进行二进制化,
// 每个件数都可以表示为多个2的不同次幂加上最后一个小于2^k+1的c值,将新的件数
//放进质量和体积中,成为一个新的整体
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 25000;
int n, m;
int v[N], w[N];//以v[i]表示体积,另一个表示权重即价值
int dp[N];
int main() {
	cin >> n >> m;
	int cnt=0;
	for (int i = 1; i <= n; i++) {
		int a, b, s;
		cin >> a>>b>>s; 
		int k = 1;
		if (k <= s) {
			cnt++;
			v[cnt] = k * a;
			w[cnt] = k * b;
			s -= k;
			k *= 2;

		}
		if (s > 0) {
			cnt++;
			v[cnt] = s*a;
			w[cnt] = s * b;
		}
	}
	n = cnt;//更换新的件数
	//即将多重背包转化成01背包
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= v[i]; j--)
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
	int maxn=0;
	for (int i = 1; i <= m; i++) {
		maxn = max(maxn, dp[m]);
	}
	cout << maxn;
	return 0;
} 
/*
4 5
1 2 3
2 4 1
3 4 3
4 5 2
*/
