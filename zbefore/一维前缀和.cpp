//�ȴӼ򵥵����֣���ϰ����д�ģ�һάǰ׺�ͣ�
//Ŀ�ģ����ýϵ͵�ʱ�临�Ӷȣ����һ�����������ڵ����
//�е�����е����飬sn��an�Ĺ�ϵ
//����ʵ��
//��֤s0Ϊ0��
#include<iostream>
using namespace std;
const int N = 100010;
int main() {
	int a[N], s[N];
	int n,l,r;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i];
	cin >> l >> r;
	for (int i = 1; i <= n; i++)s[i] = s[i - 1] + a[i];
	cout << s[r] - s[l - 1];
}