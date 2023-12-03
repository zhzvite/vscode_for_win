#include<iostream>
using namespace std;
const int N = 10010;
int a[N][N], s[N][N];//大数组放外面作全局变量，放里面会爆，无输出
int main() {
	
	int n, m, x1, x2, y1, y2;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	}
	cin >> x1 >> y1 >> x2 >> y2;
	cout << s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y2 - 1] << endl;

}