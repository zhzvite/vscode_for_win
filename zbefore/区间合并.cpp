#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair <int, int >  pii;
const int N = 100010;
int n;
vector<pii> segs;
void merge(vector<pii>& segs) {//解决不同的三种情况分别是无交集，有交集，在里面；
	vector<pii>  res;
	sort(segs.begin(), segs.end());
	int st = -2e9, ed = -2e9;
	for (auto seg : segs){
		if (ed < seg.first) {
			if (st != -2e9)res.push_back({ st,ed });
			st = seg.first, ed = seg.second;
		    }
		else ed = max(ed, seg.second);
}
		if (st != -2e9)res.push_back({ st,ed });//用在最后退出循环后，把st和ed的值录进数组
		segs = res;//把res的结果丢到seg里面，即最后合并后的区间数
	
}
int main() {
	cin >> n;
	while (n--) {
		int l, r;
		cin >> l >> r;
		segs.push_back({ l,r });//存放的是坐标
	}
	merge(segs);
	cout << segs.size() << endl;
}
/*测试用例
5
1 2
2 4
5 6
7 8
7 9
*/
//输出 3
