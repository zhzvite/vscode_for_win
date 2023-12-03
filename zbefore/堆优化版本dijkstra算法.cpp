//有向图求最短路
//dijkstra算法
#include<iostream>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
const int N = 510;
int n, m;
int w[N], h[N], e[N], ne[N], idx;
int dist[N];
bool st[N];
typedef pair<int, int> pii;
priority_queue<pii, vector<pii>, greater<pii>> heap;
void add(int a,int b,int c) {
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}
int dijkstra() {
	memset(st, false, sizeof st);
	heap.push({ 0,1 });//0表示dist【】，
	while (heap.size()) {
     auto t = heap.top();
	 heap.pop();
	 int distance = t.first, val = t.second;
	 if (st[val])continue;
	 st[val] = true;
       for (int i = h[val]; ~i; i = ne[i]) {
	      int j = e[i];
		   if (dist[j] > distance+w[i])
				  { 
					  dist[j] = distance + w[i];
					  if (!st[j]) {
                        heap.push({ dist[j],j });//前一项表示到1的距离，后一项表示这个点
					}
					 
				  }   
		      }
	     }
     if (dist[n] == 0x3f3f3f3f)return -1;
	 else return dist[n];
	}
	

int main() {
	cin >> n >> m;
	memset(dist, 0x3f, sizeof dist);
	memset(h, -1, sizeof h);
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	int t = dijkstra();
	cout << t;
}

/*
3 3
1 2 2
2 3 1
1 3 4
*/
