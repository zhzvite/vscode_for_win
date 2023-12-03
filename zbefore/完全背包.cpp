/*#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];
int dp[N][N];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> v[i];

	}
	for (int i = 0; i <= n; i++)dp[0][i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			
		//	for (int k = 0;k*w[i]<=j; k++)
			//{
				if (k * w[i] <= k)dp[i][j] = max(dp[i][j], dp[i - 1][j - k * w[i]] + k * v[i]);
		//	}
		//	
			//优化
			dp[i][j] = dp[i - 1][j];
			if(j>=w[i])dp[i][j] = max(dp[i - 1][j], dp[i ][j - w[i]] + v[i]);//数学上的化简
		}
	}
	cout << dp[n][m] << endl;
}*/
//一维优化
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 1010;
int n, m;
int v[N], w[N];
int dp[N];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> v[i];

	}
	for (int i = 0; i <= n; i++)dp[i] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = w[i]; j <= m; j++) {
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);//数学上的化简
		}
	}
	cout << dp[m] << endl;
}
/*
4 5
1 2
2 4
3 4
4 5
*/