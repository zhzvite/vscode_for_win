//���ر������Ż�,�ǽ���ô�����Ʒ���ж����ƻ�,
// ÿ�����������Ա�ʾΪ���2�Ĳ�ͬ���ݼ������һ��С��2^k+1��cֵ,���µļ���
//�Ž������������,��Ϊһ���µ�����
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 25000;
int n, m;
int v[N], w[N];//��v[i]��ʾ���,��һ����ʾȨ�ؼ���ֵ
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
	n = cnt;//�����µļ���
	//�������ر���ת����01����
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
