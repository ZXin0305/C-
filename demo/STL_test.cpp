#include<iostream>
#include<vector>
using namespace std;

int add_num(int a, int b) {
	return a + b;
}


template <typename T, typename U>
auto add_1(T t, U u) -> decltype(t + u)
{
	return t + u;
}

// 还可以这样
// R->返回值类型, T->参数1类型, U->参数2类型
template <typename R, typename T, typename U>
R add_2(T t, U u)
{
	return t + u;
}



int main() {

	vector<int> v{ 1, 2, 3, 4, 5 };

	//auto it = v.erase(v.begin() + 2);  // 删除当前的元素，返回下一个元素的迭代器
	//cout << *it << endl;
	//cout << *(v.begin() + 2) << endl;

	//auto add_two_num = add_num;
	//auto num = add_two_num(1, 2);

	//第一种
	cout << add_1(10, 11) << endl;
	//第二种
	int x = 10;
	int y = 11;
	cout << add_2<decltype(x + y), int, int>(x, y) << endl;
	cout << add_2<decltype(x + y)>(x, y) << endl;  // 简化
	system("pause");
	return 0;
}