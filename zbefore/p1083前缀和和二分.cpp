#include<iostream>
#include<algorithm>
#include<cstring>
const int  N = 1e7 + 10;
using namespace std;
long long int a[N], n, m,b[N],ss[N],hh;
long long int d[N], s[N], t[N];
void insert(int x) {
	for (int i = 1; i <= x; i++) {
		b[s[i]] += d[i];
		b[t[i] + 1] -= d[i];
	}
}
bool check(int x) {
	memset(b, 0, sizeof b);
	insert(x);
	for (int i = 1; i <= n; i++) {
		ss[i] = ss[i - 1] + b[i];
		if (ss[i] > a[i])return false;
	}
	return true;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= m; i++)
		cin >> d[i] >> s[i] >> t[i];
	long long int l = 0, r = m + 1;
	if (l + 1 == r)return 0;
	if (check(m)||m==0) {
		cout << 0;
		return 0;
	}
	while (l+1!=r) {
		int mid = (l + r) / 2;
		//cout << l << " " << r << endl;
		if (check(mid)) {
			l = mid;		
		}
		else r = mid;
		hh = r;
	}	
	cout << -1<<endl;
	cout << hh;
	return 0;
}