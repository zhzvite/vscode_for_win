//��д�ѣ�������stl
/*
1.����һ����heap[++size]=x;up(size);
2.�󼯺�����Сֵ heap(1);heap���㿪ʼ������������һ�£���̫����
3.ɾ����Сֵ     heapp[1]=heap[size];size--;down(1);	
4.ɾ������һ��Ԫ�� heap[k]=heap[size];size--;down(k)/up(k
5.�޸�����һ��Ԫ��heap(k)=x��down(k)/up(k)
С���ѣ�ÿ���㶼����С�ڵ����������ߵ�son
�洢��ʽ����һ��һά�������棬һ�ŵ�Ϊ���ڵ�
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
	for (int i = n/2 ; i; i--)down(i);// ��n/2��Ϊ����Ϊ����ʱ�临�Ӷȣ���Ϊ���һ�������ռ�ӽ�ȫ����һ��
	while (m--) {
		cout << h[1];
		h[1]=h[s];
		s--;
		down(1);
	}

	return 0;
}
