/*
vector �䳤���飬����˼�루�Ա����ķ�ʽ����ռ�Ӷ���ʡʱ��,2^n��2^n+1   
     size()����Ԫ�ظ���
     empty�����Żغ����Ƿ�Ϊ��
     clear�������
     ֧�ֱȽ�����(���ֵ���Ƚ�
pair<int ,int >//�ܴ����������,��Ҫʱ�Ե�������first/secondȡ������auto t:q[N]��
string �ַ�����substr(),c_str()
      size()
      empty()
      clear()
quene   size(),empty(),push(),front(),pop(),��ղ�����q=quene<int>()
priority_quene  ���ȶ��У�push������top������pop���� Ĭ���Ǵ���ѣ���clear
stack  ջpush������top������pop����  
deque  ˫�˶��� size��empty������������ȫ�ܵ���
set,map,multiset,multimap  ����ƽ�������ʵ�֣������������̬ά��һ�����������
set/multiset size()
    insert()
    find() 
    empty()
    count()����ĳ��������
unordered_set��unordered_map,unordered_multiset,unordered_multimap ��ϣ��
bitset ѹλ
      c++�е�boolΪһ���ֽ�
      bitset��ÿһ���ֽڴ��λ�������boolʡ�˰˱��ռ�\
      any���ж��Ƿ�������һ��1
      count�������ض��ٸ�һ
      none �����жϿ�
      set����������λ����1
      set(k,v)����kΪ���v
      reset()������λ��0
*/

/*
* C++ Maps��һ�ֹ���ʽ�������������ؼ���/ֵ����
begin() ����ָ��mapͷ���ĵ�����
clear(�� ɾ������Ԫ��
count() ����ָ��Ԫ�س��ֵĴ���
empty() ���mapΪ���򷵻�true
end() ����ָ��mapĩβ�ĵ�����
equal_range() ����������Ŀ�ĵ�������
erase() ɾ��һ��Ԫ��
find() ����һ��Ԫ��
get_allocator() ����map��������
insert() ����Ԫ��
key_comp() ���رȽ�Ԫ��key�ĺ���
lower_bound() ���ؼ�ֵ>=����Ԫ�صĵ�һ��λ��
max_size() ���ؿ������ɵ����Ԫ�ظ���
rbegin() ����һ��ָ��mapβ�������������
rend() ����һ��ָ��mapͷ�������������
size() ����map��Ԫ�صĸ���
swap() ��������map
upper_bound() ���ؼ�ֵ>����Ԫ�صĵ�һ��λ��
value_comp() ���رȽ�Ԫ��value�ĺ���
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<string>
#include<set>
#include<map>
using namespace std;
int main() {
    //�����Ƕ�pair��ʹ��
    pair<int, string >p;
    p = make_pair(10, "yxc");
    cout << p.first << p.second;
    p = { 20,"abc" };
    cout << p.first << p.second;
    pair<int, pair<int, int >>pp;
    pp = { 20,{10,0} };
    cout << pp.first << pp.second.first << pp.second.second << endl;
    string a = "ysdsd";
    a += 'c';
    cout << a << endl;
    cout << a.substr(5) << endl;//substr�еĵڶ���������Ҫ�����鳤��
    cout << a.c_str() << endl;
    //�����Ƕ����ȶ��е�ʹ��
    priority_queue<int> heap;//�������ѵȼ���
    //priority_queue<int,vector<int>,less<int>>heap
    priority_queue<int, vector<int>, greater<int>>heap1;
    heap1.push(33);
    heap1.push(2);
    heap1.push(3);
    heap1.push(1);
    while (heap1.size()) {
      cout << heap1.top() << endl; 
      heap1.pop();//ɾ�����ȼ���ߵ�Ԫ��
    }
    //�����Ƕ�string��ʹ��
        string s = "sfsa";
        string a1 = s.substr(0, 3);
        string b = s.substr();
        string c = s.substr(2, 3);
        cout << a1 << endl;
        cout << b << endl;
        cout << c << endl;
        set<int> a2;//set�Զ������Զ��������Զ�ȥ��
        //�����Ƕ�set������
    a2.insert(2);
    a2.insert(2);
    a2.insert(5);
    a2.insert(1);
    for (set<int>::iterator it = a2.begin(); it != a2.end(); it++)
        cout << *it<<" ";
    for (auto it = a2.begin(); it != a2.end(); it++)//����iterator��Ϊ����������ָ����,Ҳ����auto�Զ�ʶ��
        cout << *it << " ";
   // cout << *a2.find(5);���ص���һ��ָ��
    a2.erase(a2.find(5));//find���ҳ�����Ӧ��λ��,erase��ɾ����ַ��Ӧ����,Ҳ����ֱ��ɾ����,һ���Ǵ���find������find�������ĵ�ַ
    for (auto it = a2.begin(); it != a2.end(); it++)
        cout << *it << " ";
    //������map���÷�
    //int�Ǹ�λ�� ����ؼ��֣�string�Ǹ�λ�ô���ؼ�ֵ
    //�����ǶԹؼ�ֵ��������
    map<int, string,greater<int> > m;
    m.insert({ 4,"stu4" });
    m.insert({2,"stu2"});
    m.insert(pair<int ,string>{3,"stu3"});
    map<int, string>::iterator t;
    for (t = m.begin(); t != m.end(); t++)
        cout << t->second << endl;
        return 0;
}