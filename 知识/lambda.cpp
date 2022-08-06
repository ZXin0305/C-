#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;

bool f3(int x) { return x % 3 == 0; }

class f_mod {
private:
	int dv;
public:
	f_mod(int d = 1):dv(d){}
	bool operator()(int x) { return x % dv == 0; }
};

int main() {
	std::vector<int> numbers(1000);
	std::generate(numbers.begin(), numbers.end(), std::rand);

	// 使用函数指针
	int count3 = std::count_if(numbers.begin(), numbers.end(), f3);
	//cout << count3 << endl;

	// 使用函数符
	f_mod obj(3);  // 先创建一个类对象，存储特定的整数值
	bool is_div_by_3 = obj(7);  //使用这个类对象中重载的函数符
	cout << is_div_by_3 << endl;
	//同时，构造函数本身可以用作诸如count_if()等函数的参数
	// f_mod(3)创建一个虚对象，存储了值3，而count_if()使用该对象来调用operator()()
	// 并将参数x设置为numbers的一个元素
	count3 = count_if(numbers.begin(), numbers.end(), f_mod(3));
	cout << count3 << endl;

	// lambda函数
	//[](int x) {return x % 3 == 0; } //使用[]替代函数名，没有声明返回类型-->相当于使用decltype根据返回值推断得到的
	count3 = count_if(numbers.begin(), numbers.end(), [](int x) {return x % 3 == 0; });
	cout << count3 << endl;
	//仅当lambda表达式完全由一条返回语句组成时,自动类型推断才管用,否则需要使用新增的返回类型后置用法
	// [](double x)->double{int y = x; return x - y;}

	// 给lambda指定一个名称,并使用该名称两次
	auto mod3 = [](int x) ->bool{return x % 3 == 0; };
	count3 = count_if(numbers.begin(), numbers.end(), mod3);
	cout << count3 << endl;

	int count13 = 0;
	for_each(numbers.begin(), numbers.end(), [&count13](int x) {return count13 += x % 13 == 0; });
	cout << count13 << endl;
	int count5 = 0;
	int count14 = 0;
	for_each(numbers.begin(), numbers.end(),
		[&](int x) {count5 += x % 5 == 0; return count14 += x % 14 == 0; });
	cout << count5 << "  " << count14 << endl;

	auto test = [&count5]() {return count5; };
	cout << test() << endl;
	system("pause");
	return 0;
}