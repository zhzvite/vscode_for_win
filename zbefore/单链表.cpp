//����Ŭ��д������ʵ�־�̬���������鹹������
//����Ҫ��ͼ���
#include<iostream>
using namespace std;
const int N = 100010;
//head=ͷ���
//e��i]��ʾ�ڵ�i��ֵ
//ne��i����ʾ�ڵ�i��nextָ��
//idx��ʾ����ĵ�Ĵ���
int head, e[N], ne[N], idx;//��׼�ڽӱ�
//����4��ȫ�ֱ���
void init() {
	head = -1;
	idx = 0;
}//��head��idx���г�ʼ��
//��x�嵽ͷ���
void addhead(int x) {
	//e[idx] = x;//��x�浽e��idx����
	//ne[idx] = head;//
	//head = idx;
	//idx++;	//idxÿ�ζ���Ӽ�
	e[idx] = x, ne[idx] = head, head = idx++;
}
void addk(int k,int x) {
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx;
	idx++;
}//��x�嵽k���棬��ͷ�巨ûʲô����
//���±���k�����һ����ɾ��
void remove(int k) {
	ne[k] = ne[ne[k]];//������һ���ݹ飬�������Ϊne��¼������һ�����ݵ�idx
}

int main() {
	int t;
	init();//Ҫ�Ƚ�head��idx���г�ʼ��
	int k, x;
	cin >> t;
	while (t--) {
		char op;
		cin >> op;
		if (op == 'H')
		{
			cin >> x;
			addhead(x);
		}
		else if (op == 'D')
		{
			cin >> k;
			if (!k)head = ne[head];//��k������ĵ��±���k-1
			remove(k-1);
		}
		else {
			cin >> k>>x;
			addk(k-1, x);

		}
	}for (int i = head; i != -1; i=ne[i])cout << e[i] << " ";
}
/*
10
H 9
I 1 1
D 1
D 0
H 6
I 3 6
I 4 5
I 4 5
I 3 4
D 6
*/
//��� 6 4 6 5
