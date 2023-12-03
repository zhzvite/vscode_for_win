#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int ,int > pii;
vector<int> alls;
vector<pii> add, query;
const int N = 300010;
int n, m;
int a[N], s[N];//a[存放数组离散前的]s算前缀和
int find(int x) {
	int l = -1; int r = alls.size();
	while (l + 1 != r) {
		int mid = r + l >> 1;
		if (alls[mid]>=x)r = mid;
		else l = mid;
	}return r + 1;//将x映射到1-alls.size,x表示位置
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
		alls.push_back(r);//将数据分别存到三个数组当中

	}
	//去重
	sort(alls.begin(), alls.end());//排序
	alls.erase(unique(alls.begin(), alls.end()), alls.end());//去重，返回去重完alls的末尾位置
	for (auto item : add) {//对add中的每个元素进行迭代
		int x = find(item.first);
		a[x] += item.second;

	}
	//预处理前缀和
	// 
	for (int i = 1; i <= alls.size(); i++)s[i] = s[i - 1] + a[i];//位置寄托在alls中，数寄托在a【i】中
	//处理询问
	for (auto item : query) {
		int l = find(item.first), r = find(item.second);//将l和r在alls里面映射
		cout << s[r] - s[l - 1] << endl;
	}
}