#include<iostream>
using namespace std;
int gcd(int a, int b) {
	return b ? (b, a % b) : a;//如果b不是0，返回(b, a % b)，如果b是0，返回a
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		int a, b;
		cin >> a >> b;
		cout << gcd(a, b) << endl;
	}
}