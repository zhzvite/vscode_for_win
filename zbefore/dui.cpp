#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
int  m;
int h[N], ph[N], hp[N], s;
void hswap(int a, int b) {
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);
}
void down(int u) {
	int t = u;
	if (u * 2 <= s && h[u * 2] < h[t])t == u * 2;
	if (u * 2 + 1 <= s && h[u * 2 + 1] < h[t])t == u * 2 + 1;
	if (u != t) {
		hswap(t, u);
		down(t);
	}
}
void up(int u) {
	while (u / 2 && h[u / 2] > h[u])
	{
		hswap(u / 2, u);
		u /= 2;
	}
}
int main() {
	int n;
	cin >> n;
	while (n--) {
		int k, x;
		char op[3];
		cin >> op;
	//	for (int i = 0; i < 2; i++)cout << op[i];
		if (op[0] == 'I') {
			cin >> x;
			s++;//在堆中的位置
			m++;//在次序中的位置
			ph[m] = s;
			hp[s] = m;//两者类似反函数，互相映射
			h[s] = x;
			up(s);//最末尾往上up
		}
		else if (op[0] == 'P' && op[1] == 'M') cout << h[1];//输出集合中最小值
		else if (op[0] == 'D' && op[1] == 'M') {//删除集合中最小值
			hswap(1, s);
			s--;
			down(1);
		}
		else if (op[0] == 'D') {//删除第k个插入的数
			cin >> k;
			k = ph[k];//新的位置
			hswap(k, s);
			s--;
			down(k), up(k);
		}
		else {// C  修改第k个插入的数
			cin >> k >> x;
			k = ph[k];
			h[k] = x;
			down(k), up(k);
		}
	}
}
/*
10
I -10
PM
I -10
D 1
C 2 8
I 6
PM
DM
*/
//-10
//6