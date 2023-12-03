#include<iostream>
#include<vector>
using namespace std;
bool cmp(vector<int>& A, vector<int>& B) {//判断a是不是大于b，大于等于1，小于—1
	if (A.size() !=B.size())return A.size()>B.size();
else { 
		for (int i = A.size() - 1; i >= 0; i--) {
			if (A[i] != B[i])return A[i] > B[i];
		}return true;
		
	}//此模块判断a与b的大小，先从第一位开始判断，是bool类型
}
vector<int> sub(vector<int>& A, vector<int>& B) {
	vector<int> C;
	for (int i = 0, t = 0; i < A.size() ; i++) {
		t = A[i] - t;
		if (i < B.size())t -= B[i];
		C.push_back((t + 10) % 10);
		if (t < 0)t = 1;
		else	t =0;
	}while (C.size() > 1 && C.back() == 0) C.pop_back();//注意这里的while
	return C;
}
int main() {
	string a, b;
	vector<int>A, B;
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--)A.push_back(a[i] - '0');//注意因等于号导致的数组越界1问题
	for (int i = b.size() - 1; i >= 0; i--)B.push_back(b[i] - '0');//注意大小写a，一开始要读入a，这些错了是逻辑错误
	if (cmp(A, B)) {
		auto C=sub(A, B);
		for (int i = C.size() - 1; i >= 0; i--)cout << C[i];
	}
	else {
		auto C = sub(B, A);
		cout << "-";
		for (int i = C.size() - 1; i >= 0; i--)cout << C[i];
	}

}