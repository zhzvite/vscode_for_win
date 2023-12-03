//用两个指针，降低暴力枚举的O(n^2)的时间复杂度
//解决重复数字，输出不重复数字的总数
#include<iostream>
using namespace std;
const int N = 10010;

int main() {
	int a[N], s[N];
	for (int i = 0; i < N; i++)s[i] = 0;//要对s数组进行初始化，里面的值可能不为0，有可能会报错
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	int res = 0;
	for (int i = 0, j = 0; i < n; i++) {
		s[a[i]]++;
		while (s[a[i]] > 1) {
			s[a[j]]--;//以s的数组来记录次数
			j++;
		//	cout << a[i]<<"次数为" <<s[a[i]]<< endl;
		}
		res = max(res, i - j + 1);
	}cout << res << " ";
}