/*
* STL����
* 20220704  ����
*/

#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<forward_list>
#include<map>
#include<tuple>
#include<string>
#include<algorithm>

using namespace std;

bool fncomp(char lhs, char rhs) { return lhs < rhs; }

struct classcomp {
	bool operator() (const char& lhs, const char& rhs) const
	{
		return lhs < rhs;
	}
};

bool compare_(int a, int b) {
	return a < b;
}


int main() {

	/*
	* array����
	* ������й̶��Ĵ�С�����Ҳ�ͨ��������������Ԫ�صķ��䣺�����Ƿ�װ�̶���С����Ԫ�صľۺ����͡���ˣ����ǲ��ܶ�̬���������С��
	* �÷�:
	* array::begin()  array::end()  array::rbegin()  array::rend()
	* array::cbegin()  array::cend()  array::crbegin()  array::crend()
	  ����ָ�����������г�����������const_iterator��������������������Ӻͼ��٣����ǲ��������޸���ָ�������
	* array::size()  --> constexpr size_type size����noexcept;
	* array::max_size --> constexpr size_type max_size() noexcept;  �����������������ɵ����Ԫ��������������max_size����sizeһ����ʼ�յ�������ʵ��������ģ����ĵڶ���ģ�������
	* array::empty --> ����һ������ֵ��ָʾ���������Ƿ�Ϊ�գ�������size()�Ƿ�Ϊ0
	* array::operator[] --> ���������е�n��λ�õ�Ԫ�ص����á���array::at���ƣ���array::at��������߽粢ͨ���׳�һ��out_of_range�쳣���ж�n�Ƿ񳬳���Χ����array::operator[]�����߽硣
	* array::at --> ���������е�n��λ�õ�Ԫ�ص����á���array::operator[]����
	* array::front --> ���ض����������е�һ��Ԫ�ص����á�array::begin���ص��ǵ�������array::front���ص���ֱ������
	* array::back
	* array::data --> ����ָ����������е�һ��Ԫ�ص�ָ�롣���������е�Ԫ�ش洢�������Ĵ洢λ�ã����Լ�������ָ�����ƫ���Է��������е��κ�Ԫ�ء�
	* array::fill --> ��val�����������Ԫ�أ���val����Ϊ�������������Ԫ�ص�ֵ��֮ǰ��ֵ����и��ǣ�
	* array::swap --> ͨ��x�����ݽ�����������ݣ�������һ����ͬ���͵�������󣨰�����ͬ�Ĵ�С�����˳�Ա����ͨ���ڸ���Ԫ��֮��ִ�������С��ͬ�ĵ�������������������ʱ������
	* get��array��--> std::get<0>(myarray)������һ����������������ָ��λ��Ԫ�ص�����
	* relational operators (array) --> ���磺arrayA != arrayB��arrayA > arrayB�����˱Ƚ�����ÿ��Ԫ�صĴ�С��ϵ��
	*/
	std::array<int, 5> array_tmp = { 2,16,77,34,50 };
	//std::cout << "my array contains: ";
	//for (auto it = array_tmp.begin(); it != array_tmp.end(); ++it) {
	//	std::cout << " " << *it;
	//}
	//std::cout << endl;

	//std::cout << "my array contains: ";
	//for (auto it = array_tmp.rbegin(); it != array_tmp.rend(); ++it) {
	//	std::cout << " " << *it;
	//}
	//std::cout << endl;

	//cout << "size:" << array_tmp.size() << endl;
	//cout << "max_size: " << array_tmp.max_size() << endl;
	//cout << "sizeof: " << sizeof(array_tmp) << endl;

	//cout << array_tmp[0] << endl;
	//cout << array_tmp.at(1) << endl;

	//cout << "front: " << array_tmp.front() << endl;
	//cout << "back: " << array_tmp.back() << endl;
	//for (auto x : array_tmp) cout << " " << x;
	//cout << endl;

	//const char* cstr = "test string";
	//array<char, 12> charray;
	//memcpy(charray.data(), cstr, 12);
	//cout << charray.data() << "\n";

	//array_tmp.fill(100);
	//for (auto x : array_tmp) cout << " " << x;
	//cout << endl;

	array<int, 5> array2;
	array2.fill(10);

	//array2.swap(array_tmp);
	//cout << "array2: ";
	//for (auto x : array2) cout << " " << x;
	//cout << endl;
	//cout << "array_tmp: ";
	//for (auto x : array_tmp) cout << " " << x;
	//cout << endl;

	//cout << std::get<0>(array2) << endl;

	//if (array_tmp == array2) cout << "��� .." << endl;
	//else if (array_tmp > array2) cout << "tmp �� .." << endl;
	//else cout << "array2 �� .." << endl;

	/*
	* vector: ���Ըı��С���������������
	* ��������һ����vectorΪ���ǵ�Ԫ��ʹ�������Ĵ洢λ�ã�����ζ�����ǵ�Ԫ��Ҳ����ʹ�õ���Ԫ�صĳ���ָ���ϵ�ƫ�������ʣ����Һ�����һ����Ч��
	  ���������鲻ͬ���ǣ����ǵĴ�С���Զ�̬�ظı䣬���ǵĴ洢�������Զ�����
	  ��������ȣ��������ĸ�����ڴ�����������洢������Ч��ʽ��̬������������������ȣ��������ĸ�����ڴ�����������洢������Ч��ʽ��̬����������
	  ��� vector �ĸ��ֳ��������ĸ��Ӷȣ�Ч�ʣ����£�
		������� - ���� O(1)
		��β����ɾԪ�� - ƽ̯��amortized������ O(1)}}
		��ɾԪ�� - �� vector β�������Ծ��� O(n)}}
	*
	* vector::vector -->
	*	empty�������캯����Ĭ�Ϲ��캯���� ����һ���յ�������û��Ԫ��
		fill���캯�� ��n��Ԫ�ع���һ��������ÿ��Ԫ�ض���val�ĸ���������ṩ��
		��Χ��range�������� ʹ����[ range��first��last]��Χ�ڵ�Ԫ����ͬ��˳����һ�����������е�ÿ��Ԫ�ض���emplace -�Ӹ÷�Χ����Ӧ��Ԫ�ع������
		���ƣ�copy�����캯�������÷��������ƣ� ������ͬ��˳����һ������x��ÿ��Ԫ�صĸ���������
		�ƶ���move�����캯�����ͷ������ƶ��� ����һ����ȡxԪ�ص������� ���ָ����alloc������x�ķ�������ͬ����ôԪ�ؽ����ƶ�������û�й���Ԫ�أ����ǵ�����Ȩֱ��ת�ƣ��� x����δָ������Ч��״̬
		��ʼ���б��캯�� ����һ�������е�ÿ��Ԫ���е�һ��������IL������ͬ��˳��
	* vector::~vector --> �������������⽫��ÿ��������Ԫ���ϵ���allocator_traits::destroy����ʹ����������ͷ���ʸ����������д洢����
	* vector::operator= --> �������ݷ�����������滻�䵱ǰ���ݣ�����Ӧ���޸����С  vector& operator= (const vector& x);
	                                                                                vector& operator= (vector&& x);
																					vector& operator= (initializer_list<value_type> il);
    *
	* vector::begin  vector::end  vector::rbegin  vector::rend  vector::cbegin  vector::cend  vector::rcbegin  vector::rcend  
	* vector::size --> ����vector�б����ʵ�ʶ������������һ��������洢������
	* vector::max_size --> ���ظ�vector�����ɵ�Ԫ�ص����������������֪��ϵͳ���ʵ������
	*					   �����������Դﵽ�����Ǳ�ڴ�С���������޷���֤�ܹ��ﵽ�ô�С���ڴﵽ�ô�С֮ǰ���κ�ʱ�䣬��Ȼ�޷�����洢
	* vector::resize --> ���������Ĵ�С��ʹ�����n��Ԫ�ء�
	*					 ���nС�ڵ�ǰ������size�����ݽ�����С��ǰn��Ԫ�أ�����ɾ�������������ǣ���
	*                    ���n���ڵ�ǰ����size����ͨ����ĩβ���뾡���ܶ��Ԫ���Դﵽ��Сn����չ���ݡ����ָ����val������Ԫ�ؽ���ʼ��Ϊval�ĸ��������򽫽���ֵ��ʼ����
	*                    ���nҲ���ڵ�ǰ��������capacity��������������Ĵ洢�ռ佫�Զ����·��䡣
	*                    �������ͨ���������ɾ��Ԫ�ص��������ı�������ʵ�����ݡ�
	* vector::capacity --> ���ص�ǰΪvector����Ĵ洢�ռ�Ĵ�С����Ԫ�ر�ʾ��
	                       ���capacity(����)��һ������vector��size����������Ȼ���󣬶���Ŀռ�������Ӧ������������Ҫ���·���ÿ�����롣
	* vector::empty 
	* vector::reserve --> ����vector�����������԰���n��Ԫ�ء�
	                      ���n���ڵ�ǰvector��������ú���ʹ�������·�����洢�������Ӷ������������ӵ�n�������
						  ��������������£��������ò��ᵼ�����·��䣬����vector��������Ӱ�졣
						  ���������vector��Сû��Ӱ�죬Ҳ���ܸı�����Ԫ�ء�
	* vector::shrink_to_fit --> Ҫ��������С��capacity(����)����Ӧ��ߴ硣
	* vector::operator[]
	* vector::at
	* vector::front
	* vector::back
	* vector::data
	* vector::assign --> �������ݷ����vector���滻�䵱ǰ���ݣ�����Ӧ���޸����С
						 �ڷ�Χ�汾��1���У��������Ǵӵ�һ�������һ����Χ�ڵ�ÿ��Ԫ�ذ���ͬ˳�����Ԫ��
						 �����汾��2���У���������n��Ԫ�أ�ÿ��Ԫ�ض�����ʼ��Ϊһ��val�ĸ���
						 �ڳ�ʼ���б�汾��3���У�������������ͬ˳����Ϊ��ʼ���б��ݵ�ֵ�ĸ���
	* vector::push_back --> ��vector�����һ��Ԫ��֮�����һ����Ԫ�ء�val�����ݱ����ƣ����ƶ������µ�Ԫ�ء�
	* vector::pop_back --> ɾ��vector�е����һ��Ԫ�أ���Ч�ؽ�����size����һ��
	* vector::insert --> ͨ����ָ��λ�õ�Ԫ��֮ǰ������Ԫ������չ��vector��ͨ������Ԫ�ص�������Ч������������С
	                     ��ᵼ�·���Ĵ洢�ռ��Զ����·��䣬ֻ�����µ�vector��size������ǰ��vector��capacity������¡�
	                     ����vectorʹ��������Ϊ������洢����˳��˽�Ԫ�ز��뵽vectorĩβ֮�󣬻�vector��begin֮ǰ������λ�ûᵼ���������¶�λλ��֮�������Ԫ�ص����ǵ���λ�á�
						 �������������������������list��forward_list��ִ����ͬ�����Ĳ�����ȣ���ͨ���ǵ�Ч�Ĳ�����
			���ַ�ʽ��
						iterator insert (const_iterator position, const value_type& val); ��������
						iterator insert (const_iterator position, size_type n, const value_type& val); ���������

						template <class InputIterator>                                                 ���ݷ�Χ
						iterator insert (const_iterator position, InputIterator first, InputIterator last);

						iterator insert (const_iterator position, value_type&& val);                   �ƶ� ������ 
						initializer list (5)
						iterator insert (const_iterator position, initializer_list<value_type> il);
	* vector::erase --> ��vector��ɾ������Ԫ�أ�position����һϵ��Ԫ�أ�[first��last��
	                    ����Ч�ؼ����˱�ȥ����Ԫ�ص��������Ӷ��ƻ��������Ĵ�С��

			���ַ�ʽ��
						iterator erase (const_iterator position);
                        iterator erase (const_iterator first, const_iterator last);
	* vector::swap --> ͨ��x�����ݽ������������ݣ�x����һ����ͬ���͵�vector���󡣳ߴ���ܲ�ͬ��
   					   �ڵ��������Ա����֮����������е�Ԫ������Щ�ڵ���֮ǰ��x�е�Ԫ�أ�
	                   ��x��Ԫ���������Ԫ���е�Ԫ�ء����е����������ú�ָ��Խ������󱣳���Ч��
	* vector::clear --> ��vector��ɾ�����е�Ԫ�أ������٣�������sizeΪ0������
	* vector::emplace --> ͨ����positionλ�ô�������Ԫ��args����չ�����������Ԫ������args��Ϊ�����Ĳ�����������
	                      ����洢�ռ���Զ����·��䷢�����µ�vector��size������ǰ���������������
	* vector::emplace_back --> 
	* vector::get_allocator --> ������vector�����Ĺ���������ĸ�����
	*/

	vector<int> first; // empty vector of ints
	vector<int> second(4, 100);
	vector<int> third(second.begin(), second.end());
	vector<int> fourth(third);  // a copy of third

	vector<int> test_{ 1,3,2,50,1 };
	sort(test_.begin(), test_.end(), compare_);
	for (auto x : test_) cout << x << " ";
	cout << endl;

	//int myInts[] = { 10,20,30,40 };
	//vector<int> fifth(myInts, myInts + sizeof(myInts) / sizeof(int));
	//cout << "data: ";
	//for (auto x : fifth) cout << x << " ";
	//cout << endl;

	//vector<int> foo(3, 0);
	//vector<int> bar(5, 12);

	//bar = foo;
	//cout << bar.size() << endl;
	//cout << bar.capacity() << endl;
	//cout << bar.max_size() << endl;

	//bar.resize(10);
	//cout << bar.size() << endl;
	//for (auto x : bar) cout << x << " ";
	//cout << endl;

	//std::vector<int>::size_type sz;

	//std::vector<int> foo;
	//sz = foo.capacity();
	//cout << "��ʼ����: " << sz << endl;
	//std::cout << "making foo grow:\n";
	//for (int i = 0; i < 100; ++i) {
	//	foo.push_back(i);
	//	if (sz != foo.capacity()) {
	//		sz = foo.capacity();
	//		std::cout << "capacity changed: " << sz << '\n';
	//	}
	//}

	//std::vector<int> bar;
	//sz = bar.capacity();
	//bar.reserve(100);   // this is the only difference with foo above
	//std::cout << "making bar grow:\n";
	//for (int i = 0; i < 100; ++i) {
	//	bar.push_back(i);
	//	if (sz != bar.capacity()) {
	//		sz = bar.capacity();
	//		std::cout << "capacity changed: " << sz << '\n';
	//	}
	//}

	//vector<int> xx;
	//vector<int> yy;
	//vector<int> zz;

	//xx.assign(7, 100);   //���汾

	//vector<int>::iterator it;
	//it = xx.begin() + 1;

	//yy.assign(it, xx.end() - 1);  //��Χ�汾

	//int myInts[] = { 10,20.30 };
	//zz.assign(myInts, myInts + 3);  //��ʼ���汾

	//zz.erase(zz.begin(), zz.begin() + 2);

	//vector<int> cc(3, 100);
	//vector<int> dd(5, 200);

	//cc.swap(dd);
	//for (auto x : cc) cout << x << " ";
	//cout << endl;
	//for (auto x : dd) cout << x << " ";
	//cout << endl;


	// -------------------------------------------------------- 
	// ��vector���ڴ�����������
	//std::vector<int> myvector;
	//int* p;
	//unsigned int i;

	//// allocate an array with space for 5 elements using vector's allocator:
	//p = myvector.get_allocator().allocate(5);  //��λ
	//cout << myvector.size() << endl;

	//// construct values in-place on the array:
	//for (i = 0; i < 5; i++) myvector.get_allocator().construct(&p[i], i); //ԭ�ظı�Ԫ��ֵ
	////cout << myvector.size() << endl;

	//std::cout << "The allocated array contains:";
	//for (i = 0; i < 5; i++) std::cout << ' ' << p[i];
	//std::cout << '\n';

	//// destroy and deallocate:
	//for (i = 0; i < 5; i++) myvector.get_allocator().destroy(&p[i]);  // ����  destory����������͵�����������������Ӧ�ڴ��ϵ����ݣ������ٺ��ڴ��ַ�Ա�����
	//myvector.get_allocator().deallocate(p, 5);    // deallocate�����ͷ��ڴ棨��ʱ��Ӧ�ڴ��е�ֵ�ڴ�֮ǰӦ����destory���٣����ڴ��ַ���ظ�ϵͳ�������ⲿ�ֵ�ַʹ������-1��
	// ----------------------------------------------------

	/*
	* deque  ˫�˶���  ͷβ���롢ͷβɾ��O(1)  ����  ���ظ�  һ�����������
	* template < class T, class Alloc = allocator<T> > class deque;
	* deque::deque --> ����һ��deque�������󣬸�����ʹ�õĹ��캯���汾��ʼ����������
	* deque::push_back --> �ڵ�ǰ�����һ��Ԫ��֮�� ����deque������ĩβ���һ����Ԫ�ء�val�����ݱ����ƣ����ƶ������µ�Ԫ�ء�
	* deque::push_front --> ��deque�����Ŀ�ʼλ�ò���һ���µ�Ԫ�أ�λ�ڵ�ǰ�ĵ�һ��Ԫ��֮ǰ��val�����ݱ����ƣ����ƶ����������Ԫ��
	* deque::pop_back --> ɾ��deque�����е����һ��Ԫ�أ���Ч�ؽ�������С����һ����
	* deque::emplace_front --> ��deque�Ŀ�ͷ����һ���µ�Ԫ�أ������䵱ǰ�ĵ�һ��Ԫ��֮ǰ������µ�Ԫ������args��Ϊ�����Ĳ����������ġ�
	*						   ��Ԫ����ͨ������allocator_traits::construct��ת��args��������
	*                          ����һ�����Ƶĳ�Ա����push_front�������Խ����ж����ƻ��ƶ��������С�
	*                          template <class... Args>
							     void emplace_front (Args&&... args);
	* deque::emplace_back --> ��deque��ĩβ����һ���µ�Ԫ�أ������ڵ�ǰ�����һ��Ԫ��֮������µ�Ԫ������args��Ϊ�����Ĳ�����������
	*						��Ԫ����ͨ������allocator_traits::construct��ת��args�������ġ�
							����һ�����Ƶĳ�Ա����push_back�������Խ����ж����ƻ��ƶ���������
	*/

	deque<int> de_first;
	deque<int> de_second(4, 100);
	deque<int> de_third(de_second.begin(), de_second.end());
	deque<int> de_fourth(de_third);   // ���ƹ���

	//int de_myInts[] = { 16, 2, 77, 29 };
	//deque<int> de_fifth(de_myInts, de_myInts + sizeof(de_myInts) / sizeof(int));

	//de_fifth.push_back(100);
	//de_fifth.push_front(200);

	//de_fifth.pop_back();
	//de_fifth.pop_front();

	//de_fifth.emplace_front(111);
	//de_fifth.emplace_back(123);

	//for (auto x : de_fifth) cout << x << " ";
	//cout << endl;

	/*
	* forward_list  ʵ��Ϊ������
	* forward_list::forward_list
	* forward_list::~forward_list --> �����������
	* forward_list::before_begin --> ����ָ�������е�һ��Ԫ��֮ǰ��λ�õĵ�������
	*								 ���صĵ�������Ӧ��������ã�����Ϊ��������Ա�����Ĳ���emplace_after��insert_after��erase_after��splice_after��
	                                 ָ�����У�����ִ�иö�����λ�õĿ�ʼλ�á�
	* forward_list::cbefore_begin --> ����ָ�������е�һ��Ԫ��֮ǰ��λ�õ�const_iterator
	*								  һ����������ָ�������ݵĵ�������
	                                 ����������������Ӻͼ��٣�����������Ҳ��const��������forward_list::before_begin���صĵ�����һ����
									 �����������޸���ָ������ݡ�
	*/

	forward_list<int> fl_first;           // default�� empty
	forward_list<int> fl_second(3, 77);   // fill ���
	forward_list<int> fl_third(fl_second.begin(), fl_second.end());  // range ��ʼ��
	forward_list<int> fl_fourth(fl_third);    // copy constructor
	forward_list<int> fl_fifth(std::move(fl_fourth)); // move ctor. (fourth wasted)
	forward_list<int> fl_sixth = { 3, 52, 25, 90 };

	//for (auto x : fl_fifth) cout << x << " ";
	//cout << endl;	

	//for (auto x : fl_fourth) cout << x << " ";
	//cout << endl;

	//fl_sixth.insert_after(fl_sixth.before_begin(), 11);
	//for (auto x : fl_sixth) cout << x << " ";
	//cout << endl;		


	/*
	* map
	* typedef pair<const Key, T> value_type;
	* ӳ������ͨ����unordered_map����������ͨ�����ǵļ������ʸ���Ԫ�أ�������������������ǵ�˳����Ӽ�����ֱ�ӵ���
	* �ڸ�ӳ��ֵ��ͼ����ֱ��ͨ��ʹ������Ӧ�ļ��������������������������[] ��
	* 
	* map::map  --> ����һ��ӳ���������󣬸�����ʹ�õĹ������汾��ʼ�������ݣ�
	*		       ��1�����������캯����Ĭ�Ϲ��캯����
	*               ����һ���յ�������û��Ԫ�ء�
	*			   ��2����Χ���캯��
	*               �������һ�����Ԫ�صķ�Χ�ڵ�����[��һ�����һ��), ����ÿ��Ԫ�����蹹��Ĵ��ڸ÷�Χ��������Ӧ��Ԫ��
	*				(3)���ƹ��캯�������÷��������ƣ�
	*               ʹ��x�е�ÿ��Ԫ�صĸ�������һ������
	*               (4)�ƶ����캯�������������һ���ƶ���
	*               ����һ����ȡxԪ�ص������� 
	                ���ָ����alloc������x�ķ�������ͬ����ôԪ�ؽ����ƶ���
					����û�й���Ԫ�أ����ǵ�����Ȩֱ��ת�ƣ��� x����δָ������Ч��״̬��
				   ��5����ʼ���б��캯��
					��il�е�ÿ��Ԫ�صĸ�������һ������
	* map::begin --> ��������map�����е�һ��Ԫ�صĵ�����������map����ʼ�ձ�����Ԫ�ص�˳�����Կ�ʼָ����ѭ���������׼��Ԫ�ء� 
	                 ��������ǿյģ��򷵻صĵ�����ֵ��Ӧ��������á�
	* map::key_comp --> �����������ڱȽϼ��ıȽ϶���ĸ����� key_compare key_comp() const;
	* 
	* map::value_comp --> ���ؿ����ڱȽ�����Ԫ�صıȽ϶����Ի�ȡ��һ��Ԫ�صļ��Ƿ��ڵڶ���Ԫ��֮ǰ
	* 
	* map::find --> ���������������е���K�ļ���Ԫ�أ�����ҵ��򷵻�һ�������������򷵻�map::end�ĵ�����
	* map::count --> �������һ���ض��ļ��Ƿ����
	* map::count --> ���������������е���k�ļ���Ԫ�أ�������ƥ��������� ���ڵ�ͼ�����е�����Ԫ�ض���Ψһ�ģ���˸ú���ֻ�ܷ���1������ҵ���Ԫ�أ��򷵻��㣨���򣩡�
	* 
	map::lower_bound --> �����������ص����ޡ� ����ָ�������е�һ��Ԫ�صĵ���������Ԫ�صļ�������k֮ǰ����
					     һ������£�lower_bound����ָ���Ԫ�صĵ���������upper_bound����ָ����һ��Ԫ�صĵ�������

	* map::equal_range --> ��ȡ��ͬԪ�صķ�Χ��
	*                      ���ذ������������о�����k�ȼ۵ļ���Ԫ�صķ�Χ�߽硣 
	                       ���ڵ�ͼ�����е�Ԫ�ؾ���Ψһ�������Է��صķ�Χ���ֻ����һ��Ԫ�ء����û���ҵ�ƥ�䣬�򷵻صķ�Χ������ĳ��ȣ�
	*/

	map<char, int> map_first;
	map_first['a'] = 10;
	map_first['b'] = 30;
	map_first['c'] = 50;
	map_first['d'] = 70;

	map<char, int> map_second(map_first.begin(), map_first.end());

	map<char, int> map_third(map_second);

	map<char, int, classcomp> map_fourth;   // class as compare   ������ʹ�ú������������������Ȼ���������������ڲ���������ʹ��

	//for (auto it = map_fourth.begin(); it != map_fourth.end(); ++it) {
	//	cout << it->first << " " << it->second << endl;
	//}

	bool(*fn_pt)(char, char) = fncomp;   // ����ʹ��һ��lambda����
	map<char, int, bool(*)(char, char)> map_fifth(fn_pt); // function pointer as Compare

	map<char, int> mymap;
	mymap['b'] = 500;
	mymap['a'] = 200;
	mymap['c'] = 300;

	//for (auto it = mymap.begin(); it != mymap.end(); ++it) {
	//	cout << it->first << " " << it->second << endl;
	//}

	//std::map<char, int>::key_compare mycomp = mymap.key_comp();

	//char highest = mymap.rbegin()->first;  // key value of last element

	//std::map<char, int>::iterator it = mymap.begin();
	//do {
	//	std::cout << it->first << " => " << it->second << '\n';
	//} while (mycomp((*it++).first, highest));

	//std::pair<char, int> highest = *mymap.rbegin();  // last element

	//std::map<char, int>::iterator it = mymap.begin();
	//do {
	//	std::cout << it->first << " => " << it->second << '\n';
	//} while (mymap.value_comp()(*it++, highest));


	map<char, int> mymap_2;

	map<char, int>::iterator it;
	
	mymap_2['a'] = 50;
	mymap_2['b'] = 100;
	mymap_2['c'] = 150;
	mymap_2['d'] = 200;

	//it = mymap_2.find('b');  //�����ǵ�����
	//if (it != mymap_2.end())
	//	mymap_2.erase(it);

	//cout << "elements in mymap_2:" << '\n';
	//cout << "a: " << mymap_2.find('a')->second << endl;
	//cout << "b: " << mymap_2.find('b')->second << endl;
	//cout << "c: " << mymap_2.find('c')->second << endl;

	//if (mymap_2.count('a') > 0)
	//	cout << "here .." << endl;

	std::map<char, int> mymap_3;
	std::map<char, int>::iterator itlow, itup;

	mymap_3['a'] = 20;
	mymap_3['b'] = 40;
	mymap_3['c'] = 60;
	mymap_3['d'] = 80;
	mymap_3['e'] = 100;

	mymap_3.insert(std::pair<char, int>('f', 10));

	//itlow = mymap_3.lower_bound('b');  // itlow points to b
	//itup = mymap_3.upper_bound('d');   // itup points to e (not d!)

	//mymap_3.erase(itlow, itup);        // erases [itlow,itup)

	//for (std::map<char, int>::iterator it = mymap_3.begin(); it != mymap_3.end(); ++it)
	//	std::cout << it->first << " => " << it->second << '\n';

	//std::pair<std::map<char, int>::iterator, std::map<char, int>::iterator> ret;
	//ret = mymap_3.equal_range('b');

	//std::cout << "lower bound points to: ";
	//std::cout << ret.first->first << " => " << ret.first->second << '\n';

	//std::cout << "upper bound points to: ";
	//std::cout << ret.second->first << " => " << ret.second->second << '\n';


	/*
	* tuple
	* template <class... Types> class tuple;
	* 
	* tuple::tuple --> ����һ�� tuple��Ԫ�飩����
	*/

	std::tuple<int, char> tuple1(10, 'x');
	auto bar = std::make_tuple("test", 3.1, 14, 'y');

	std::get<2>(bar) = 100;
	
	int myInt; char myChar;

	std::tie(myInt, myChar) = tuple1;  // unpack elements
	std::tie(std::ignore, std::ignore, myInt, myChar) = bar;  // unpack (with ignore)

	/*myChar = std::get<3>(bar);*/

	//cout << myChar << endl;

	//std::get<0>(tuple1) = std::get<2>(bar);
	//std::get<1>(tuple1) = myChar;

	//cout << std::get<0>(tuple1) << endl;
	//cout << std::get<1>(tuple1) << endl;

	//std::tuple<int, char> tuple_first;                             // default
	//std::tuple<int, char> tuple_second(tuple_first);                    // copy
	//std::tuple<int, char> tuple_third(std::make_tuple(20, 'b'));   // move
	//std::tuple<long, char> tuple_fourth(tuple_third);                   // implicit conversion
	//std::tuple<int, char> tuple_fifth(10, 'a');                    // initialization
	//std::tuple<int, char> tuple_sixth(std::make_pair(30, 'c'));    // from pair / move


	/*
	* pair --> 
	* ������һ��ֵ��values�������һ����Щֵ�����ǲ�ͬ�����ͣ�T1 �� T2����ÿ��ֵ���Ա����еĳ�Ա����first��second���ʡ�
	* pair��tuple��Ԫ�飩��һ������
	* pair��ʵ����һ���ṹ�壬��Ҫ��������Ա������first second ��Ϊ��ʹ��struct����class�����Կ���ֱ��ʹ��pair�ĳ�Ա������
	* Ӧ�ã�
	*    ���Խ���������������ϳ�һ����map<key, value>  mymap_3.insert(std::pair<char, int>('f', 10));
	*    ��ĳ��������Ҫ��������ֵʱ
	*/


	std::pair<string, double> product1;   // default constructor 
	std::pair<string, double> product2("tomatoes", 2.30);  // value init
	std::pair <std::string, double> product3(product2);  // copy constructor

	product1 = std::make_pair(std::string("lightbulbs"), 0.99);   // using make_pair (move)

	product2.first = "shoes";                  // the type of first is string
	product2.second = 39.90;                   // the type of second is double

	std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
	std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
	std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';


	system("pause");
	return 0;
}
