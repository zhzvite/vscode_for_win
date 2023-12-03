//字符串前缀哈希法、
//将字符串变成哈希值处理
//思路。存放str，同时进行m次询问，
//利用前缀和预处理，进行p进制转换
#include<iostream>

using namespace std;
const int N = 100010,t=131;//将字母转化为t进制的数，将字符串的哈希值进行比较
typedef unsigned long long ull;//用ull则溢出的话就认为是取模于2的64次方
int n, m;
char str[N];
ull h[N], p[N];
ull get(int l, int r) {
	return h[r] - h[l - 1] * p[r - l + 1];//求l和r之间字符串的哈希值
}
int main() {
	cin >> n >> m >> str+1;//str+1表示第0位不放数据
	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		p[i] = p[i - 1] * t;//表示次方
		h[i] = h[i - 1] * t + str[i];//将他变为数字
	//	cout << str[1] << " " << h[1];
	}
	while (m--) {
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if (get(l1, r1) == get(l2, r2)) cout << "yes" << endl;
		else cout << "No" << endl;	
	}
}