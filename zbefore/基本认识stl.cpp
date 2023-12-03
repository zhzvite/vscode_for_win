/*
vector 变长数组，倍增思想（以倍增的方式申请空间从而节省时间,2^n到2^n+1   
     size()返回元素个数
     empty（）放回函数是否为空
     clear（）清空
     支持比较运算(以字典序比较
pair<int ,int >//能存放有序数对,需要时以迭代器加first/second取用例如auto t:q[N]；
string 字符串，substr(),c_str()
      size()
      empty()
      clear()
quene   size(),empty(),push(),front(),pop(),清空操作：q=quene<int>()
priority_quene  优先队列，push（），top（），pop（） 默认是大根堆，无clear
stack  栈push（），top（），pop（）  
deque  双端队列 size，empty，。。。几乎全能但慢
set,map,multiset,multimap  基于平衡二叉树实现（红黑树），动态维护一个有序的序列
set/multiset size()
    insert()
    find() 
    empty()
    count()返回某个数个数
unordered_set，unordered_map,unordered_multiset,unordered_multimap 哈希表
bitset 压位
      c++中的bool为一个字节
      bitset是每一个字节存八位，相较于bool省了八倍空间\
      any是判断是否至少有一个1
      count（）返回多少个一
      none （）判断空
      set（）把所有位重置1
      set(k,v)将第k为变成v
      reset()把所有位变0
*/

/*
* C++ Maps是一种关联式容器，包含“关键字/值”对
begin() 返回指向map头部的迭代器
clear(） 删除所有元素
count() 返回指定元素出现的次数
empty() 如果map为空则返回true
end() 返回指向map末尾的迭代器
equal_range() 返回特殊条目的迭代器对
erase() 删除一个元素
find() 查找一个元素
get_allocator() 返回map的配置器
insert() 插入元素
key_comp() 返回比较元素key的函数
lower_bound() 返回键值>=给定元素的第一个位置
max_size() 返回可以容纳的最大元素个数
rbegin() 返回一个指向map尾部的逆向迭代器
rend() 返回一个指向map头部的逆向迭代器
size() 返回map中元素的个数
swap() 交换两个map
upper_bound() 返回键值>给定元素的第一个位置
value_comp() 返回比较元素value的函数
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
    //以下是对pair的使用
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
    cout << a.substr(5) << endl;//substr中的第二个参数是要的数组长度
    cout << a.c_str() << endl;
    //以下是对优先队列的使用
    priority_queue<int> heap;//定义大根堆等价于
    //priority_queue<int,vector<int>,less<int>>heap
    priority_queue<int, vector<int>, greater<int>>heap1;
    heap1.push(33);
    heap1.push(2);
    heap1.push(3);
    heap1.push(1);
    while (heap1.size()) {
      cout << heap1.top() << endl; 
      heap1.pop();//删除优先级最高的元素
    }
    //以下是对string的使用
        string s = "sfsa";
        string a1 = s.substr(0, 3);
        string b = s.substr();
        string c = s.substr(2, 3);
        cout << a1 << endl;
        cout << b << endl;
        cout << c << endl;
        set<int> a2;//set自动递增自动排序且自动去重
        //以下是对set的运用
    a2.insert(2);
    a2.insert(2);
    a2.insert(5);
    a2.insert(1);
    for (set<int>::iterator it = a2.begin(); it != a2.end(); it++)
        cout << *it<<" ";
    for (auto it = a2.begin(); it != a2.end(); it++)//这里iterator作为迭代器当作指针用,也可用auto自动识别
        cout << *it << " ";
   // cout << *a2.find(5);返回的是一个指针
    a2.erase(a2.find(5));//find能找出数对应的位置,erase能删除地址对应的数,也可以直接删除数,一般是搭配find函数，find回来他的地址
    for (auto it = a2.begin(); it != a2.end(); it++)
        cout << *it << " ";
    //以下是map的用法
    //int那个位置 代表关键字，string那个位置代表关键值
    //排序是对关键值进行排序
    map<int, string,greater<int> > m;
    m.insert({ 4,"stu4" });
    m.insert({2,"stu2"});
    m.insert(pair<int ,string>{3,"stu3"});
    map<int, string>::iterator t;
    for (t = m.begin(); t != m.end(); t++)
        cout << t->second << endl;
        return 0;
}