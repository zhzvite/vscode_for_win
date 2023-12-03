//手写堆，不是用stl
/*
1.插入一个数heap[++size]=x;up(size);
2.求集合中最小值 heap(1);heap从零开始则左右子树不一致，不太方便
3.删除最小值     heapp[1]=heap[size];size--;down(1);	
4.删除任意一个元素 heap[k]=heap[size];size--;down(k)/up(k
5.修改任意一个元素heap(k)=x；down(k)/up(k)
小根堆：每个点都满足小于等于左右两边的son
存储方式：用一个一维数组来存，一号点为根节点
down
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
int h[N], s,m,n;
void down(int u) {
	int t = u;
	if (u * 2 <= s && h[u * 2] < h[t])t = u * 2;
	if (u * 2 + 1 <= s && h[u * 2 + 1] < h[t])t = u * 2 + 1;
	if (t != u) {
		swap(h[t], h[u]);
		down(t);
	}
}
void  up(int u) {
	while (u / 2 && h[u / 2] > h[u])
	{
		swap(h[u / 2], h[u]);
		u /= 2;   
	}
}
int main() {
	cin >> n>>m;
	for (int i = 1; i <= n; i++)cin >> h[i];
	s = n;
	for (int i = n/2 ; i; i--)down(i);// 用n/2是为了因为降低时间复杂度，因为最后一层二叉树占接近全部的一半
	while (m--) {
		cout << h[1];
		h[1]=h[s];
		s--;
		down(1);
	}

	return 0;
}
