//дһ�����ֲ���
//˼·���������С����������ҵ���һ�����ڻ��ߵ���������
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
int a[N],k;
//�����ݹ�ʵ�ֶ���

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n, less<int>());//������������
	sort(a, a + n, greater<int>());//��������
	//	for (int i = 0; i < n; i++)cout << a[i] << " ";
	cin >> k;
	int i = -1, j = n;//�����ص�,����������������
	if (i + 1 == j){
		cout << " false" << endl; return 0;
      }

	if (k<a[0] || k>a[n - 1]) {
		cout << " out" << endl;
		return 0;//�жϼ������
	}
	while (i+1!=j) {
		int x = (i + j) / 2;
		//	cout << i << " " << j;
		if (k <= a[x])j = x;//��Щ���ȹ�ϵҪ��������,���ݺ�������������
		if (k > a[x])i = x;
	}
	cout << j;
}