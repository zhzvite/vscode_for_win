#include<iostream>
#include<algorithm>
using namespace std;
const int N = 200010;
int p[N];
int n, m;
struct Edge {
	int a, b, w;
	bool operator< (const Edge &W)const {
		return w < W.w;
	}//在之后针对w进行排序
}edges[N];
int find(int x) {
	if (p[x] != x)p[x] = find(p[x]);
	return p[x];
}
int main() {
	cin >>n >> m;
	for (int i = 0; i <= n; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		edges[i] = { a,b,w };
	}
	sort(edges, edges + m);//按w的权重进行排序
	int res = 0, cnt = 0;
	for (int i = 1; i <= n; i++)p[i] = i;
	for (int i = 0; i <m; i++) {
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		a=find(a); 
		b = find(b);
		if (a != b) {
			p[a] = b;
			res += w;
			cnt++;
		}
	}
	if (cnt < n - 1)cout << "impossible";
	else cout << res;
}
/*
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
*/