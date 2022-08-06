/*
* STL容器
* 20220704  张鑫
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
	* array数组
	* 数组具有固定的大小，并且不通过分配器管理其元素的分配：它们是封装固定大小数组元素的聚合类型。因此，他们不能动态地扩大或缩小。
	* 用法:
	* array::begin()  array::end()  array::rbegin()  array::rend()
	* array::cbegin()  array::cend()  array::crbegin()  array::crend()
	  返回指向数组容器中常量迭代器（const_iterator）；这个迭代器可以增加和减少，但是不能用来修改它指向的内容
	* array::size()  --> constexpr size_type size（）noexcept;
	* array::max_size --> constexpr size_type max_size() noexcept;  返回数组容器可容纳的最大元素数。数组对象的max_size与其size一样，始终等于用于实例化数组模板类的第二个模板参数。
	* array::empty --> 返回一个布尔值，指示数组容器是否为空，即它的size()是否为0
	* array::operator[] --> 返回数组中第n个位置的元素的引用。与array::at相似，但array::at会检查数组边界并通过抛出一个out_of_range异常来判断n是否超出范围，而array::operator[]不检查边界。
	* array::at --> 返回数组中第n个位置的元素的引用。与array::operator[]相似
	* array::front --> 返回对数组容器中第一个元素的引用。array::begin返回的是迭代器，array::front返回的是直接引用
	* array::back
	* array::data --> 返回指向数组对象中第一个元素的指针。由于数组中的元素存储在连续的存储位置，所以检索到的指针可以偏移以访问数组中的任何元素。
	* array::fill --> 用val填充数组所有元素，将val设置为数组对象中所有元素的值（之前有值会进行覆盖）
	* array::swap --> 通过x的内容交换数组的内容，这是另一个相同类型的数组对象（包括相同的大小）。此成员函数通过在各个元素之间执行与其大小相同的单独交换操作，以线性时间运行
	* get（array）--> std::get<0>(myarray)；传入一个数组容器，返回指定位置元素的引用
	* relational operators (array) --> 形如：arrayA != arrayB、arrayA > arrayB；依此比较数组每个元素的大小关系。
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

	//if (array_tmp == array2) cout << "相等 .." << endl;
	//else if (array_tmp > array2) cout << "tmp 大 .." << endl;
	//else cout << "array2 大 .." << endl;

	/*
	* vector: 可以改变大小的数组的序列容器
	* 就像数组一样，vector为它们的元素使用连续的存储位置，这意味着它们的元素也可以使用到其元素的常规指针上的偏移来访问，而且和数组一样高效。
	  但是与数组不同的是，它们的大小可以动态地改变，它们的存储由容器自动处理。
	  与数组相比，载体消耗更多的内存来交换管理存储和以有效方式动态增长的能力与数组相比，载体消耗更多的内存来交换管理存储和以有效方式动态增长的能力
	  针对 vector 的各种常见操作的复杂度（效率）如下：
		随机访问 - 常数 O(1)
		在尾部增删元素 - 平摊（amortized）常数 O(1)}}
		增删元素 - 至 vector 尾部的线性距离 O(n)}}
	*
	* vector::vector -->
	*	empty容器构造函数（默认构造函数） 构造一个空的容器，没有元素
		fill构造函数 用n个元素构造一个容器。每个元素都是val的副本（如果提供）
		范围（range）构造器 使用与[ range，first，last]范围内的元素相同的顺序构造一个容器，其中的每个元素都是emplace -从该范围内相应的元素构造而成
		复制（copy）构造函数（并用分配器复制） 按照相同的顺序构造一个包含x中每个元素的副本的容器
		移动（move）构造函数（和分配器移动） 构造一个获取x元素的容器。 如果指定了alloc并且与x的分配器不同，那么元素将被移动。否则，没有构建元素（他们的所有权直接转移）。 x保持未指定但有效的状态
		初始化列表构造函数 构造一个容器中的每个元件中的一个拷贝的IL，以相同的顺序。
	* vector::~vector --> 销毁容器对象。这将在每个包含的元素上调用allocator_traits::destroy，并使用其分配器释放由矢量分配的所有存储容量
	* vector::operator= --> 将新内容分配给容器，替换其当前内容，并相应地修改其大小  vector& operator= (const vector& x);
	                                                                                vector& operator= (vector&& x);
																					vector& operator= (initializer_list<value_type> il);
    *
	* vector::begin  vector::end  vector::rbegin  vector::rend  vector::cbegin  vector::cend  vector::rcbegin  vector::rcend  
	* vector::size --> 这是vector中保存的实际对象的数量，不一定等于其存储容量。
	* vector::max_size --> 返回该vector可容纳的元素的最大数量。由于已知的系统或库实现限制
	*					   这是容器可以达到的最大潜在大小，但容器无法保证能够达到该大小：在达到该大小之前的任何时间，仍然无法分配存储
	* vector::resize --> 调整容器的大小，使其包含n个元素。
	*					 如果n小于当前的容器size，内容将被缩小到前n个元素，将其删除（并销毁它们）。
	*                    如果n大于当前容器size，则通过在末尾插入尽可能多的元素以达到大小n来扩展内容。如果指定了val，则新元素将初始化为val的副本，否则将进行值初始化。
	*                    如果n也大于当前的容器的capacity（容量），分配的存储空间将自动重新分配。
	*                    这个函数通过插入或者删除元素的内容来改变容器的实际内容。
	* vector::capacity --> 返回当前为vector分配的存储空间的大小，用元素表示。
	                       这个capacity(容量)不一定等于vector的size。它可以相等或更大，额外的空间允许适应增长，而不需要重新分配每个插入。
	* vector::empty 
	* vector::reserve --> 请求vector容量至少足以包含n个元素。
	                      如果n大于当前vector容量，则该函数使容器重新分配其存储容量，从而将其容量增加到n（或更大）
						  在所有其他情况下，函数调用不会导致重新分配，并且vector容量不受影响。
						  这个函数对vector大小没有影响，也不能改变它的元素。
	* vector::shrink_to_fit --> 要求容器减小其capacity(容量)以适应其尺寸。
	* vector::operator[]
	* vector::at
	* vector::front
	* vector::back
	* vector::data
	* vector::assign --> 将新内容分配给vector，替换其当前内容，并相应地修改其大小
						 在范围版本（1）中，新内容是从第一个和最后一个范围内的每个元素按相同顺序构造的元素
						 在填充版本（2）中，新内容是n个元素，每个元素都被初始化为一个val的副本
						 在初始化列表版本（3）中，新内容是以相同顺序作为初始化列表传递的值的副本
	* vector::push_back --> 在vector的最后一个元素之后添加一个新元素。val的内容被复制（或移动）到新的元素。
	* vector::pop_back --> 删除vector中的最后一个元素，有效地将容器size减少一个
	* vector::insert --> 通过在指定位置的元素之前插入新元素来扩展该vector，通过插入元素的数量有效地增加容器大小
	                     这会导致分配的存储空间自动重新分配，只有在新的vector的size超过当前的vector的capacity的情况下。
	                     由于vector使用数组作为其基础存储，因此除了将元素插入到vector末尾之后，或vector的begin之前，其他位置会导致容器重新定位位置之后的所有元素到他们的新位置。
						 与其他种类的序列容器（例如list或forward_list）执行相同操作的操作相比，这通常是低效的操作。
			四种方式：
						iterator insert (const_iterator position, const value_type& val); 单个数据
						iterator insert (const_iterator position, size_type n, const value_type& val); 填充多个数据

						template <class InputIterator>                                                 数据范围
						iterator insert (const_iterator position, InputIterator first, InputIterator last);

						iterator insert (const_iterator position, value_type&& val);                   移动 ？？？ 
						initializer list (5)
						iterator insert (const_iterator position, initializer_list<value_type> il);
	* vector::erase --> 从vector中删除单个元素（position）或一系列元素（[first，last）
	                    这有效地减少了被去除的元素的数量，从而破坏了容器的大小。

			两种方式：
						iterator erase (const_iterator position);
                        iterator erase (const_iterator first, const_iterator last);
	* vector::swap --> 通过x的内容交换容器的内容，x是另一个相同类型的vector对象。尺寸可能不同。
   					   在调用这个成员函数之后，这个容器中的元素是那些在调用之前在x中的元素，
	                   而x的元素是在这个元素中的元素。所有迭代器，引用和指针对交换对象保持有效。
	* vector::clear --> 从vector中删除所有的元素（被销毁），留下size为0的容器
	* vector::emplace --> 通过在position位置处插入新元素args来扩展容器。这个新元素是用args作为构建的参数来构建的
	                      分配存储空间的自动重新分配发生在新的vector的size超过当前向量容量的情况下
	* vector::emplace_back --> 
	* vector::get_allocator --> 返回与vector关联的构造器对象的副本。
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
	//cout << "初始容量: " << sz << endl;
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

	//xx.assign(7, 100);   //填充版本

	//vector<int>::iterator it;
	//it = xx.begin() + 1;

	//yy.assign(it, xx.end() - 1);  //范围版本

	//int myInts[] = { 10,20.30 };
	//zz.assign(myInts, myInts + 3);  //初始化版本

	//zz.erase(zz.begin(), zz.begin() + 2);

	//vector<int> cc(3, 100);
	//vector<int> dd(5, 200);

	//cc.swap(dd);
	//for (auto x : cc) cout << x << " ";
	//cout << endl;
	//for (auto x : dd) cout << x << " ";
	//cout << endl;


	// -------------------------------------------------------- 
	// 用vector的内存来构建数组
	//std::vector<int> myvector;
	//int* p;
	//unsigned int i;

	//// allocate an array with space for 5 elements using vector's allocator:
	//p = myvector.get_allocator().allocate(5);  //定位
	//cout << myvector.size() << endl;

	//// construct values in-place on the array:
	//for (i = 0; i < 5; i++) myvector.get_allocator().construct(&p[i], i); //原地改变元素值
	////cout << myvector.size() << endl;

	//std::cout << "The allocated array contains:";
	//for (i = 0; i < 5; i++) std::cout << ' ' << p[i];
	//std::cout << '\n';

	//// destroy and deallocate:
	//for (i = 0; i < 5; i++) myvector.get_allocator().destroy(&p[i]);  // 销毁  destory负责调用类型的析构函数，销毁相应内存上的内容（但销毁后内存地址仍保留）
	//myvector.get_allocator().deallocate(p, 5);    // deallocate负责释放内存（此时相应内存中的值在此之前应调用destory销毁，将内存地址返回给系统，代表这部分地址使用引用-1）
	// ----------------------------------------------------

	/*
	* deque  双端队列  头尾插入、头尾删除O(1)  无序  可重复  一个中央控制器
	* template < class T, class Alloc = allocator<T> > class deque;
	* deque::deque --> 构造一个deque容器对象，根据所使用的构造函数版本初始化它的内容
	* deque::push_back --> 在当前的最后一个元素之后 ，在deque容器的末尾添加一个新元素。val的内容被复制（或移动）到新的元素。
	* deque::push_front --> 在deque容器的开始位置插入一个新的元素，位于当前的第一个元素之前。val的内容被复制（或移动）到插入的元素
	* deque::pop_back --> 删除deque容器中的最后一个元素，有效地将容器大小减少一个。
	* deque::emplace_front --> 在deque的开头插入一个新的元素，就在其当前的第一个元素之前。这个新的元素是用args作为构建的参数来构建的。
	*						   该元素是通过调用allocator_traits::construct来转换args来创建的
	*                          存在一个类似的成员函数push_front，它可以将现有对象复制或移动到容器中。
	*                          template <class... Args>
							     void emplace_front (Args&&... args);
	* deque::emplace_back --> 在deque的末尾插入一个新的元素，紧跟在当前的最后一个元素之后。这个新的元素是用args作为构建的参数来构建的
	*						该元素是通过调用allocator_traits::construct来转换args来创建的。
							存在一个类似的成员函数push_back，它可以将现有对象复制或移动到容器中
	*/

	deque<int> de_first;
	deque<int> de_second(4, 100);
	deque<int> de_third(de_second.begin(), de_second.end());
	deque<int> de_fourth(de_third);   // 复制构造

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
	* forward_list  实现为单链表
	* forward_list::forward_list
	* forward_list::~forward_list --> 单链表的销毁
	* forward_list::before_begin --> 返回指向容器中第一个元素之前的位置的迭代器。
	*								 返回的迭代器不应被解除引用：它是为了用作成员函数的参数emplace_after，insert_after，erase_after或splice_after，
	                                 指定序列，其中执行该动作的位置的开始位置。
	* forward_list::cbefore_begin --> 返回指向容器中第一个元素之前的位置的const_iterator
	*								  一个常量性是指向常量内容的迭代器。
	                                 这个迭代器可以增加和减少（除非它本身也是const），就像forward_list::before_begin返回的迭代器一样，
									 但不能用来修改它指向的内容。
	*/

	forward_list<int> fl_first;           // default： empty
	forward_list<int> fl_second(3, 77);   // fill 填充
	forward_list<int> fl_third(fl_second.begin(), fl_second.end());  // range 初始化
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
	* 映射容器通常比unordered_map容器慢，以通过它们的键来访问各个元素，但是它们允许基于它们的顺序对子集进行直接迭代
	* 在该映射值地图可以直接通过使用其相应的键来访问括号运算符（（操作符[] ）
	* 
	* map::map  --> 构造一个映射容器对象，根据所使用的构造器版本初始化其内容：
	*		       （1）空容器构造函数（默认构造函数）
	*               构造一个空的容器，没有元素。
	*			   （2）范围构造函数
	*               构造具有一样多的元素的范围内的容器[第一，最后一个), 其中每个元件布设构造的从在该范围内它的相应的元件
	*				(3)复制构造函数（并用分配器复制）
	*               使用x中的每个元素的副本构造一个容器
	*               (4)移动构造函数（并与分配器一起移动）
	*               构造一个获取x元素的容器。 
	                如果指定了alloc并且与x的分配器不同，那么元素将被移动。
					否则，没有构建元素（他们的所有权直接转移）。 x保持未指定但有效的状态。
				   （5）初始化列表构造函数
					用il中的每个元素的副本构造一个容器
	* map::begin --> 返回引用map容器中第一个元素的迭代器。由于map容器始终保持其元素的顺序，所以开始指向遵循容器排序标准的元素。 
	                 如果容器是空的，则返回的迭代器值不应被解除引用。
	* map::key_comp --> 返回容器用于比较键的比较对象的副本。 key_compare key_comp() const;
	* 
	* map::value_comp --> 返回可用于比较两个元素的比较对象，以获取第一个元素的键是否在第二个元素之前
	* 
	* map::find --> 在容器中搜索具有等于K的键的元素，如果找到则返回一个迭代器，否则返回map::end的迭代器
	* map::count --> 用来检查一个特定的键是否存在
	* map::count --> 在容器中搜索具有等于k的键的元素，并返回匹配的数量。 由于地图容器中的所有元素都是唯一的，因此该函数只能返回1（如果找到该元素）或返回零（否则）。
	* 
	map::lower_bound --> 将迭代器返回到下限。 返回指向容器中第一个元素的迭代器，该元素的键不会在k之前出现
					     一般情况下，lower_bound返回指向该元素的迭代器，而upper_bound返回指向下一个元素的迭代器。

	* map::equal_range --> 获取相同元素的范围。
	*                      返回包含容器中所有具有与k等价的键的元素的范围边界。 
	                       由于地图容器中的元素具有唯一键，所以返回的范围最多只包含一个元素。如果没有找到匹配，则返回的范围具有零的长度，
	*/

	map<char, int> map_first;
	map_first['a'] = 10;
	map_first['b'] = 30;
	map_first['c'] = 50;
	map_first['d'] = 70;

	map<char, int> map_second(map_first.begin(), map_first.end());

	map<char, int> map_third(map_second);

	map<char, int, classcomp> map_fourth;   // class as compare   这里是使用函数符，重载运算符，然后传入匿名对象，在内部当作函数使用

	//for (auto it = map_fourth.begin(); it != map_fourth.end(); ++it) {
	//	cout << it->first << " " << it->second << endl;
	//}

	bool(*fn_pt)(char, char) = fncomp;   // 可以使用一个lambda函数
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

	//it = mymap_2.find('b');  //这里是单引号
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
	* tuple::tuple --> 构建一个 tuple（元组）对象
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
	* 这个类把一对值（values）结合在一起，这些值可能是不同的类型（T1 和 T2）。每个值可以被公有的成员变量first、second访问。
	* pair是tuple（元组）的一个特例
	* pair的实现是一个结构体，主要的两个成员变量是first second 因为是使用struct不是class，所以可以直接使用pair的成员变量。
	* 应用：
	*    可以将两个类型数据组合成一个如map<key, value>  mymap_3.insert(std::pair<char, int>('f', 10));
	*    当某个函数需要两个返回值时
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
