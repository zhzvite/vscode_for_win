//��Ч�洢�Ͳ�ѯ�ַ������ϵ����ݽṹ
//ͨ��һ�Ŷ��֦��������Ч�洢,ÿһ����֧����һ���ַ���
#include<iostream>
using namespace  std;
const int N = 100010;
int son[N][26],cnt[N],idx;//�±���0�ĵ�,���ǿսڵ�,���Ǹ��ڵ�
char str[N];//�����ַ���
void insert(char str[]) {//����һ�����ַ���
	int p = 0;
	for (int i = 0; str[i]; i++) {
		int u = str[i] - 'a';//���ַ���ת��������
		if (!son[p][u])son[p][u] = ++idx;//idx������ǵ�ǰ�õ����±�,�±�Ψһ��������洢λ��
		p = son[p][u];
		//cout << "p=" << p << " ";
	}
	cnt[p]++;//p�Ǳ�ǣ���������ֹ���
	//ע������son[0][]������ַ����ĵ�һ����ĸ��֮��p��++�����ô��λ���б�ռ���ˣ����������p�Զ��̳У�������һ��ѭ��
}
//��ѯ�ĵ���Ͳ������һ��
int query(char str[]) {
	int p = 0;
	for (int i = 0; str[i]; i++) {
		int u = str[i] - 'a';
		if (!son[p][u])return 0;
		p = son[p][u];
	}
	return cnt[p];
}
int main() {
	int n;
	cin >> n;//nΪn�β���
	while (n--) {
		char op[2];
		cin >> op;
	//	cout << op[0] << " " << op[1]<<endl;
		cin >> str;
		if (op[0] == 'I')insert(str);//ִ�в������
		else cout << query(str);//ִ��Ѱ�Ҳ���
	}
	
	return 0;
}
/*		
6
I abc
Q abc
Q ab
I ab
Q ab
Q bc
*/