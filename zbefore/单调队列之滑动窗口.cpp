//和单调队列一致
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int n, k;//n表示数的个数,k表示窗口内能存放个数
int a[N], q[N];//a[N]表示数的存放集合,q[N]表示数的下标的集合
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)cin >> a[i];
	int hh = 0;//hh判断队列长度，hh是队尾
	int tt = -1;//tt表示次序，tt是对头
	for (int i = 0; i < n; i++) {
		//判断对头是否已经滑出窗口
		while (hh <= tt && i - k + 1 > q[hh])hh++;//while肯定行,但一次肯定是一个出,所以用if也行
		while (hh <= tt && a[q[tt]] >= a[i])tt--;//要构造一个单调递增数列
		q[++tt] = i;//把下标该放的位置
		if (i >= k - 1)cout << a[q[hh]] <<" ";
	}
	cout << endl;
	hh = 0;
	 tt = -1;
	for (int i = 0; i < n; i++) {
		if (hh <= tt && i - k + 1 > q[hh])hh++;//判断对头是否已经滑出窗口
		while (hh <= tt && a[q[tt]] <= a[i])tt--;//(仅改变正负号,构建一个单调递减数列
		q[++tt] = i;
		if (i >= k - 1)cout << a[q[hh]] << " ";//if条件限制数列
	}
}
/*
8 3
1 3 -1 -3 5 3 6 7
*/
/*
-1 -3 -3 -3 3 3
3 3 5 5 6 7
*/