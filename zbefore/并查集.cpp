//并查集巧妙地利用了递归，每次更新后都会形成新的集合，同时用递归对路迳进行了压缩
#include<iostream>
using namespace std;
const int N = 100010;
int n, m;//
int p[N];
int find(int x) {//返回x的祖宗节点,同时对路径进行压缩
	if (p[x] != x)p[x] = find(p[x]);//采用递归,找到他的父节点,同时进行了路径压缩
	                                //便于优化后面的检索
	return p[x];//最后求出祖宗节点
 }
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)p[i]=i;//初始化数组p,使得每个都是其父节点,从i等于1开始
	while (m--) {
		char op[2];
		int a, b;
		cin >> op >> a >> b;
		if (op[0] == 'M')p[find(a)] = find(b);//祖宗节点的父节点为b的祖宗节点,使得a的祖宗节点放在b的祖宗节点下
		//达到合并集合的效果
		else {
			if (find(a) == find(b))cout << "Yes";
			else cout << "No";
		}
	}
	return 0;
}
/*
4 5
M 1 2
M 3 4
Q 1 2
Q 1 3
Q 3 4
*/