#include<iostream>
using namespace std;
int a, b;
int qpow(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) 
			ans = ans * a;
	    a *= a;
		b >>= 1;	
	}
	return ans;
}
int main() {
	cin >> a >> b;
	cout << qpow(a, b);
}