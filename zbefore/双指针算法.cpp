//������ָ�룬���ͱ���ö�ٵ�O(n^2)��ʱ�临�Ӷ�
//����ظ����֣�������ظ����ֵ�����
#include<iostream>
using namespace std;
const int N = 10010;

int main() {
	int a[N], s[N];
	for (int i = 0; i < N; i++)s[i] = 0;//Ҫ��s������г�ʼ���������ֵ���ܲ�Ϊ0���п��ܻᱨ��
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	int res = 0;
	for (int i = 0, j = 0; i < n; i++) {
		s[a[i]]++;
		while (s[a[i]] > 1) {
			s[a[j]]--;//��s����������¼����
			j++;
		//	cout << a[i]<<"����Ϊ" <<s[a[i]]<< endl;
		}
		res = max(res, i - j + 1);
	}cout << res << " ";
}