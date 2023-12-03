#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair <int, int >  pii;
const int N = 100010;
int n;
vector<pii> segs;
void merge(vector<pii>& segs) {//�����ͬ����������ֱ����޽������н����������棻
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
		if (st != -2e9)res.push_back({ st,ed });//��������˳�ѭ���󣬰�st��ed��ֵ¼������
		segs = res;//��res�Ľ������seg���棬�����ϲ����������
	
}
int main() {
	cin >> n;
	while (n--) {
		int l, r;
		cin >> l >> r;
		segs.push_back({ l,r });//��ŵ�������
	}
	merge(segs);
	cout << segs.size() << endl;
}
/*��������
5
1 2
2 4
5 6
7 8
7 9
*/
//��� 3
