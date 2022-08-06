#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<set>

using namespace std;

bool less_(int x, int val) {
	return val < x;
}

int main() {
	vector<int> v1{ 100, 99, 97, 98 };
	//v1 = { 96, 99, 94, 95, 102 };  //会覆盖掉前面的初始化
	//cout << v1.size() << endl;

	list<int, std::allocator<int>> l1(10, 4);
	list<int, std::allocator<int>> l2(2, 4);
	//auto itr = l1.begin();
	//cout << *(itr) << endl;
	//for (auto x : l1)
	//	cout << x << endl;
	//cout << l1[0] << endl;
	//cout << l1.size() << endl;
	//l1.unique();
	//cout << l1.size() << endl;
	//l1.merge(l2);
	//cout << l2.size() << endl;

	set<int, std::less<int>> s1(v1.begin(), v1.end());
	//for (auto x : s1)
	//	cout << x << endl;

	map<int, int> m1;
	m1.insert({ 1,2 });
	m1.insert(make_pair(2, 3));
	m1.insert(pair<int, int>(4, 5));

	m1[10] = 1;
	cout << m1[10] << endl;

	system("pause");
	return 0;
}