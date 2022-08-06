#include<iostream>
#include<stack>
#include<string>
#include<vector>

using namespace std;

// �º���
class FunctionMode {
public:
	FunctionMode(){}
	bool operator()(int& val1, int& val2) {  //���Ҳ�����������
		return val1 > val2;
	}
};

//����������У����Ҫ�ܹ��������㣬Ӧ�������ص�������з��������������
class Test {
private:
	int _num;
public:
	Test(){}
	Test(int num) :_num(num) {}
	Test operator+(const Test& t) const {  // ���ﲻʹ������Ҳ�ǿ��Եģ������ٶ�������Ҫ������һ������
		Test t_tmp;
		t_tmp._num = this->_num + t._num;
		return t_tmp;   // ���ܹ�����t_tmp��ָ�룬��Ϊ����һ���ֲ��������ᱻ���٣�Ȼ�󷵻ص�ָ��ͱ����Ұָ��
	}
	int getNum() { return this->_num; }
};


// ����ģ�壬Function f��һ������ָ�룬ָ���������
template<typename Function>
void compare(int val1, int val2, Function f) {
	if (f(val1, val2))
		cout << val1 << " ���� " << val2 << endl;
	else
		cout << val1 << " С�� " << val2 << endl;
}

int main() {

	// stack������������ģ��������������1.�洢��������� 2.�ײ�����������
   /*	top()������һ��ջ��Ԫ�ص����ã�����Ϊ T& �����ջΪ�գ�����ֵδ���塣
		push(const T & obj)�����Խ����󸱱�ѹ��ջ��������ͨ�����õײ������� push_back() ������ɵġ�
		push(T && obj)�����ƶ�����ķ�ʽ������ѹ��ջ��������ͨ�����õײ�����������ֵ���ò����� push_back() ������ɵġ�
		pop()������ջ��Ԫ�ء�
		size()������ջ��Ԫ�صĸ�����
		empty()����ջ��û��Ԫ�ص�����·��� true��
		emplace()���ô���Ĳ������ù��캯������ջ�����ɶ���
		swap(stack<T> & other_stack)������ǰջ�е�Ԫ�غͲ����е�Ԫ�ؽ���������������Ԫ�ص����ͱ���͵�ǰջ����ͬ������ stack ������һ����������ȫ�ֺ��� swap() ����ʹ�á�
	*/
	// ����һ���ô���ַ��������stack����
	//stack<string> words;

	//words.push("zx1");
	//words.push("zx2");
	//words.emplace("zx3");

	//words.pop();
	//words.pop();
	//words.pop();
	//cout << words.size() << endl;

	//char c1 = '[';
	//char c2 = ']';
	//string s1;
	//s1 = c1;
	//string s2;
	//s2 = c2;
	//
	//cout << s1+s2<< endl;

	//string s = "hello";

	//reverse(s.begin(), s.end());

	//cout << s << endl;
	//string ss = "12";
	//int xx = atoi(ss.c_str());
	//cout << xx << endl;

	FunctionMode f;
	int val1 = 12, val2 = 13;
	cout << f(val1, val2) << endl;  // ���������
	compare(12, 13, f);  // ����Ƿº�����ʹ�ã�����һ���������֮�󣬻������������е�operator()()
	compare(12, 13, [](int val1, int val2) {return val1 > val2; });  //�����lambda����

	Test t1(12), t2(13), t3(14);

	Test t4 = t1 + t2 + t3;  // �����������������������������Ҫ�����������з������ɵĶ���
	cout << t4.getNum() << endl;

	system("pause");
	return 0;
}