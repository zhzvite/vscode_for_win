//���鼯����������˵ݹ飬ÿ�θ��º󶼻��γ��µļ��ϣ�ͬʱ�õݹ��·�ɽ�����ѹ��
#include<iostream>
using namespace std;
const int N = 100010;
int n, m;//
int p[N];
int find(int x) {//����x�����ڽڵ�,ͬʱ��·������ѹ��
	if (p[x] != x)p[x] = find(p[x]);//���õݹ�,�ҵ����ĸ��ڵ�,ͬʱ������·��ѹ��
	                                //�����Ż�����ļ���
	return p[x];//���������ڽڵ�
 }
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)p[i]=i;//��ʼ������p,ʹ��ÿ�������丸�ڵ�,��i����1��ʼ
	while (m--) {
		char op[2];
		int a, b;
		cin >> op >> a >> b;
		if (op[0] == 'M')p[find(a)] = find(b);//���ڽڵ�ĸ��ڵ�Ϊb�����ڽڵ�,ʹ��a�����ڽڵ����b�����ڽڵ���
		//�ﵽ�ϲ����ϵ�Ч��
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