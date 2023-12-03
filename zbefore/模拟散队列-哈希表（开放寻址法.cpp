#include<iostream>
using namespace std;
const int N = 200003, null = 0x3f3f3f3f;//null是数据取不到的，开了两倍的坑位
int h[N];
int find(int x) {//上厕所法，返回要存放的位置或者是他在的地方
	int k = (x % N + N) % N;   
	while (h[k] != null && h[k] != x) {
		k++;
		if (k == N)k = 0;
	}
	return k;
}
int main() {
	int n;
	cin >> n;
	memset(h, 0x3f, sizeof h);//memset是针对字节memset，h数组有四个字节，每个字节都是ox3f 
	while (n--) {
		char op[2];
		int x;
		cin >> op>>x;
		int k = find(x);
		if (op[0] == 'I')h[k] = x;
		else {
			if (h[k] != null)cout << "yes" << endl;
			else cout << "No" << endl;
		}
	}
}