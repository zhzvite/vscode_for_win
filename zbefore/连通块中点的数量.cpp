//����Ȳ��鼯����Ҫά�����ϵ�����
#include<iostream>
using namespace std;
const int N = 10010;
int p[N],tsize[N];
int  find(int x) {
	if (p[x] != x)p[x] = find(p[x]);//ά��ÿ���㵽���ڵ�ľ���
	return p[x];
}
int main() {
	//for (int i = 0; i < N; i++)size[i] = 0;
	int m,n;
	cin >> n>>m;
	for (int i = 1; i <= n; i++) 
	{
		p[i] = i;
		tsize[i] = 1;//�����ò���size����tsize��¼һ�����ϵ�����
	}
	char op[5];
	int a, b;
	while (m--) {
		cin >> op;
		if (op[0] == 'C') {
			cin >> a >> b;
			if (find(a) == find(b))continue;
			tsize[find(b)] += tsize[find(a)];
			p[find(a)] = find(b);
		}
		else if(op[1] == '1'){
			cin >> a >> b;
         if (find(a) == find(b))cout << "Yes" << endl;
		    else cout << "No" << endl;
		}
		else {
			cin >> a;
			cout << tsize[find(a)];
		}
	}
	return 0;
}
/*
5 5
C 1 2
Q1 1 2
Q2 1 
C 2 5
Q2 5
*/