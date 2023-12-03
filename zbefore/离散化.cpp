#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int ,int > pii;
vector<int> alls;
vector<pii> add, query;
const int N = 300010;
int n, m;
int a[N], s[N];//a[���������ɢǰ��]s��ǰ׺��
int find(int x) {
	int l = -1; int r = alls.size();
	while (l + 1 != r) {
		int mid = r + l >> 1;
		if (alls[mid]>=x)r = mid;
		else l = mid;
	}return r + 1;//��xӳ�䵽1-alls.size,x��ʾλ��
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x, c;
		cin >> x >> c;
		alls.push_back(x);
		add.push_back({ x,c });
	}
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		query.push_back({ l,r });
		alls.push_back(l);
		alls.push_back(r);//�����ݷֱ�浽�������鵱��

	}
	//ȥ��
	sort(alls.begin(), alls.end());//����
	alls.erase(unique(alls.begin(), alls.end()), alls.end());//ȥ�أ�����ȥ����alls��ĩβλ��
	for (auto item : add) {//��add�е�ÿ��Ԫ�ؽ��е���
		int x = find(item.first);
		a[x] += item.second;

	}
	//Ԥ����ǰ׺��
	// 
	for (int i = 1; i <= alls.size(); i++)s[i] = s[i - 1] + a[i];//λ�ü�����alls�У���������a��i����
	//����ѯ��
	for (auto item : query) {
		int l = find(item.first), r = find(item.second);//��l��r��alls����ӳ��
		cout << s[r] - s[l - 1] << endl;
	}
}