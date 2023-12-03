//����n���������������Щ���ֳ˻���Լ���������𰸶�1e9+7ȡģ
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
	//for (auto tt : primes)res = res * (tt.second + 1) % mod;//��Լ���ĸ���
	//��Լ��֮��
	for (auto tt : primes) {
		int p = tt.first, a = tt.second;
		ll t = 1;
		while (a--)t = (t * p + 1) % mod;
		res = res * t % mod;
	}
	cout << res << endl;
}
