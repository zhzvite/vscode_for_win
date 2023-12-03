#include<iostream>
#include<algorithm>
using namespace std;
const int N = 500010;
int n, m, k,mid,ans;
int a[N];
bool judge(int x) {
	int res = 0;
	int now = 0;
	int i = 0;
	while (i < n + 1) {
		i++;
		if (a[i] - a[now] < x)
			res++;
		else now = i;
	 }
	if (res > k)return false;
	else return true;
}
int main() {
	cin >> m >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a[n + 1] = m;
	int i = 0, j = m + 1;
	while (i+1!=j) {
	//	cout << i << " " << j;
		int mid = (i + j) / 2;
		if (judge(mid)) {
			i = mid;
			ans = mid;
		}
		else j = mid;
	}
	cout << ans << endl;
	return 0;


}
