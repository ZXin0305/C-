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

// ����������
// R->����ֵ����, T->����1����, U->����2����
template <typename R, typename T, typename U>
R add_2(T t, U u)
{
	return t + u;
}



int main() {

	vector<int> v{ 1, 2, 3, 4, 5 };

	//auto it = v.erase(v.begin() + 2);  // ɾ����ǰ��Ԫ�أ�������һ��Ԫ�صĵ�����
	//cout << *it << endl;
	//cout << *(v.begin() + 2) << endl;

	//auto add_two_num = add_num;
	//auto num = add_two_num(1, 2);

	//��һ��
	cout << add_1(10, 11) << endl;
	//�ڶ���
	int x = 10;
	int y = 11;
	cout << add_2<decltype(x + y), int, int>(x, y) << endl;
	cout << add_2<decltype(x + y)>(x, y) << endl;  // ��
	system("pause");
	return 0;
}