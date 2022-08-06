#include <memory>
#include<iostream>
class Son;
class Father;
using fatherptr = std::shared_ptr<Father>;
using sonptr = std::shared_ptr<Son>;
using sonweakptr = std::weak_ptr<Son>;
class Father
{
public:
	sonweakptr s;
	Father();
	~Father();
};
class Son
{
public:
	fatherptr f;
	Son();
	~Son();
};

Father::Father() { std::cout << "hello father" << std::endl; }
Father::~Father() { std::cout << "bye father" << std::endl; }
Son::Son() { std::cout << "hellow son" << std::endl; }
Son::~Son() { std::cout << "bye son" << std::endl; }

int main() {

	fatherptr f(new Father());
	sonptr s(new Son());
	f->s = s;
	s->f = f;  //循环调用

	std::cout << f.use_count() << std::endl;//输出2
	std::cout << s.use_count() << std::endl;//输出2

	system("pause");
	return 0;
}
