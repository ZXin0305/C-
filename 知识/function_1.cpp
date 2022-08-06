#include<iostream>
#include<string>
using namespace std;
template <typename T, typename F>
T use_f(T v, F f)
{
	static int count = 0;
	count++;
	cout << "use_f count = " << count
		<< ", &count = " << &count << endl;
	return f(v);
}

class Fp {
private:
	double z_;
public:
	Fp(double z = 1.0):z_(z){}
	double operator()(double p) { return z_ * p; }
};

class Fq {
private:
	double z_;
public:
	Fq(double z = 1.0):z_(z){}
	double operator()(double q) { return z_ + q; }
};

void show_list(){}  // 无参数的定义

template<typename T>  //一个参数的定义
void show_list(const T& value) {
	cout << value << "\n";
}

template<typename T, typename... Args>  //多个参数的定义
void show_list(T value, Args... args) {
	cout << value << ", ";
	show_list(args...);
}

double dub(double x) { return 2.0 * x; }
double square(double x) { return x * x; }

int main() {
	double y = 1.21;
	cout << use_f(y, dub) << endl;  //这里的函数名是个指针


	// 可变参数模板
	int n = 14;
	double x = 2.71828;
	string mr = "Mr. String objects!";

	show_list(n, x, mr);
	
	system("pause");
	return 0;
}