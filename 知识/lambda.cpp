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

	// ʹ�ú���ָ��
	int count3 = std::count_if(numbers.begin(), numbers.end(), f3);
	//cout << count3 << endl;

	// ʹ�ú�����
	f_mod obj(3);  // �ȴ���һ������󣬴洢�ض�������ֵ
	bool is_div_by_3 = obj(7);  //ʹ���������������صĺ�����
	cout << is_div_by_3 << endl;
	//ͬʱ�����캯�����������������count_if()�Ⱥ����Ĳ���
	// f_mod(3)����һ������󣬴洢��ֵ3����count_if()ʹ�øö���������operator()()
	// ��������x����Ϊnumbers��һ��Ԫ��
	count3 = count_if(numbers.begin(), numbers.end(), f_mod(3));
	cout << count3 << endl;

	// lambda����
	//[](int x) {return x % 3 == 0; } //ʹ��[]�����������û��������������-->�൱��ʹ��decltype���ݷ���ֵ�ƶϵõ���
	count3 = count_if(numbers.begin(), numbers.end(), [](int x) {return x % 3 == 0; });
	cout << count3 << endl;
	//����lambda���ʽ��ȫ��һ������������ʱ,�Զ������ƶϲŹ���,������Ҫʹ�������ķ������ͺ����÷�
	// [](double x)->double{int y = x; return x - y;}

	// ��lambdaָ��һ������,��ʹ�ø���������
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