//���ر������⣬���ر����ǵ��ر����ı�ʽ��ͬʱ����ȫ����������˲���Լ��
//�����Ǳ�����������һ��ά���Ż�
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 1e4+10;
int a[N], b[N], s[N];
int f[N];//���ǶԶ�ά���Ż�
int n, x,sum;

int main() {
	cin >> n >> x ;
	f[0] = 1;
	for (int i = 1; i <= n; i++)cin >> a[i] >> b[i];//��a[i],b[i]����
	for (int i = 1; i <= n; i++) {
		for (int j = x; j >= 0;j--) {
			for (int k = 1; k <= b[i]; k++) {
				if (k * a[i] <= j)
				{
               f[j] =max( f[j],f[j - k * a[i]]);		 
				}		
			}
		}
	}
	if (f[x])cout << "Yes";
	else cout << "No";
}
//�Ż�˼·��������s=200�����԰������ɶ��2�ļ����ݺͼ���һ����������Ӷ����ϴ����ת����Ҫ��Ҫѡ���ٵļ���ѡ�01������ʽ
//���������Ż�