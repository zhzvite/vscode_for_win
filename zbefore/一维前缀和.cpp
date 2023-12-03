//先从简单的入手，复习昨天写的，一维前缀和，
//目的，利用较低的时间复杂度，求出一段连续区间内的求和
//有点像高中的数组，sn与an的关系
//代码实现
//保证s0为0；
#include<iostream>
using namespace std;
const int N = 100010;
int main() {
	int a[N], s[N];
	int n,l,r;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	cin >> l >> r;
	for (int i = 1; i <= n; i++)s[i] = s[i - 1] + a[i];
	cout << s[r] - s[l - 1];
}