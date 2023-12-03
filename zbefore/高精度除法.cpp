#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int>div(vector<int>& A,  long long int b) {
	vector<int> C;
	   long long int r = 0;
	for (int i = A.size()-1; i >= 0; i--) {
       r = r * 10 + A[i];
	   C.push_back(r / b);
	   r %= b;
	}
	reverse(C.begin(), C.end());
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	return C;
}
int main()
{
	long long int b;
    string a;
	vector<int>A;
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');
	auto C = div(A, b);
	for (int i = C.size() - 1; i >= 0; i--) {
		cout << C[i];
	}
}