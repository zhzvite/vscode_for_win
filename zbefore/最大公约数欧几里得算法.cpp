#include<iostream>
using namespace std;
int gcd(int a, int b) {
	return b ? (b, a % b) : a;//���b����0������(b, a % b)�����b��0������a
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