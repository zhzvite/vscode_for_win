//������
#include<iostream>
using namespace std;
const int N = 100003;//һ��mol����Ҫѡ��һ������
int h[N],e[N],ne[N],idx;
void insert(int x) {
	//��xӳ�䵽��ϣ������
	int k = (x % N + N) % N;
	e[idx] = x, ne[idx] = h[k], h[k] = idx++;//������Ĳ���
}
bool find(int x) {
	int k = (x % N + N) % N;//k��ӳ�䵽��ϣ�����ϵ�ֵ��ʹ�ø���mol�����һ����������c++�и���mol����ɸ���
	for (int i = h[k]; i != -1; i = ne[i]) {
		if (e[i] == x)
			return true;}
	return false;//return false �������жϣ������Ҳ����ͷ���false
}
int main() {
	int n;
//	cout << -10 % 3 << endl;
//  cout << 10 % -5<<endl;
	cin >> n;
	memset(h, -1, sizeof h);//���г�ʼ��,��ʼ��Ϊ-1,������
	//for (int i = 0; i < N; i++)cout << h[i] << endl;//�ж����еĳ�ʼ֮����-1
	while (n--) {
		char op[2];
		int x;
		cin >> op >> x;
		if (op[0] == 'I')insert(x);
		else {
			if (find(x))cout << "yes"<<endl;
			else cout << "No"<<endl;
		}

	}
	return 0;
}
/*
5 
I 1
I 2
I 3
Q 2
Q 5
*/
