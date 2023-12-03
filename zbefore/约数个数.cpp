//给定n个正整数，输出这些数字乘积的约数个数，答案对1e9+7取模
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
int main() {
	int n;
	cin >> n;
	unordered_map<int, int > primes;
	while (n--) {
		int x;
		cin >> x;
		for (int i = 2; i <= x / i; i++) {
			while (x % i == 0) {
				primes[i]++;
				x /= i;
			}
		}
		if (x > 1)primes[x]++;
	}
	ll res = 1;
	//for (auto tt : primes)res = res * (tt.second + 1) % mod;//求约数的个数
	//求约数之和
	for (auto tt : primes) {
		int p = tt.first, a = tt.second;
		ll t = 1;
		while (a--)t = (t * p + 1) % mod;
		res = res * t % mod;
	}
	cout << res << endl;
}
