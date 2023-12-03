#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e4 + 10;
int p[N], cnt;
bool st[N];
void get_primes(int n) {//埃氏筛
	for (int i = 2; i <= n; i++) {
		if (!st[i]) {
			p[cnt++] = n;
		//	cout << i << endl;
		//	cout << cnt << endl;
			for (int j = i + i; i <= n; j +=i)st[j] = true;
		}
	}
	//return cnt;
}
void get_primes1(int n) {//线性筛
	for ( int i = 2; i <= n; i++) {
		if (!st[i])p[cnt++] = i;
		for (int j = 0; p[j] <= n / i; j++) {
			st[p[j] * i] = true;
			if (i % p[j] == 0)break;//p[j]一定是i的最小质因子

		}

	}
}
int main() {
	int n;
	cin >> n;
	//cout << n << endl;
	//get_primes(n);
	get_primes1(n);
	cout << cnt;
	return 0;
}