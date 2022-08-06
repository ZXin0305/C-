/*
* 这个代码是关于大话数据结构中的一些demo代码
*/

#include<iostream>
#include<time.h>

using namespace std;

//线性表插入元素  P52
bool ListInsert(int* arr, int insert_idx, int num, int len, int max_size) {
	insert_idx -= 1;
	if (insert_idx < 0 || (insert_idx + 1) >= max_size)   //插入的位置不在列表的范围之中
		return false;
	for (int i = len - 1; i >= insert_idx; --i) {
		arr[i + 1] = arr[i];
	}

	arr[insert_idx] = num;
	len++;
	return true;
}

struct Node {
	int data;
	struct Node* next;   //指针类型占用的内存大小是固定的（无论该指针指向哪种数据类型），在32 位系统中为4 字节；在64 位系统中为8 字节
};

typedef struct Node* LinkList;


//单链表的初始化
//1.随机产生n个元素的值，建立带表头结点的单链表L(头插法)
void CreateListHead(LinkList* L, int n) {  //这里的LinkList需要传入的是地址，不然无法更改其中的内容
	LinkList p;   //先声明一下  LinkList本身就是指针形式的，所以可以直接写成(*L)->next = p;

	srand(time(0));      //初始化随机数种子
	*L = (LinkList)malloc(sizeof(Node));  //memory allocation， 动态内存分配，用于申请一块连续的指定大小的内存块区域以void*类型返回分配的内存区域地址，
	                                      //当无法知道内存具体位置的时候，想要绑定真正的内存空间，就需要用到动态的分配内存，且分配的大小就是程序要求的大小
	(*L)->next = NULL;   //先建立一个带头结点的单链表

	for (int i = 0; i < n; ++i) {
		p = (LinkList)malloc(sizeof(Node));  //生成新结点， 在c++中直接使用new就好了
		p->data = rand() % 100 + 1;     //生成数据域
		cout << p->data << endl;
		p->next = (*L)->next;
		(*L)->next = p;    //插入到表头
	}
}

//单链表的尾插法
void CreateListTail(LinkList* L, int n) {
	LinkList p, r;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;  //r为指向尾部的结点

	for (int i = 0; i < n; ++i) {
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		cout << p->data << endl;
		r->next = p;
		r = p;

	}
	r->next = NULL;
}

//单链表的插入
void ListInsert(LinkList* L, int i, int e) {
	int j;
	LinkList p, s;
	p = *L;
	j = 1;

	while (p && j < i) {  //寻找第i-1个结点
		p = p->next;
		++j;
	}

	if (!p || j > i)
		cout << "插入失败" << endl;

	//生成一个新的结点，先动态申请一个内存
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	cout << "插入成功" << endl;
}

//单链表的删除
void ListDelete(LinkList* L, int i, int* e) {
	int j;
	LinkList p, q;
	p = *L;
	j = 1;

	while (p->next && j < i) {  //遍历寻找第i-1个结点
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i) {
		cout << "删除失败" << endl;
	}

	q = p->next;  //q就是要删除的这个结点,所以遍历时要停留在前一个结点
	p->next = p->next->next;
	*e = q->data; //将q结点中的数据给*e
	free(q);   //系统回收q结点，释放内存
	cout << "删除成功" << endl;

}

void ClearList(LinkList* L) {
	LinkList p, q;
	p = (*L)->next;  //第一个结点
	while (p) {
		q = p->next;  //要先把这个保留下来，不然把p销毁之后就无法获取了
		free(p);
		p = q;
	}

	(*L)->next = NULL;  //头结点指针域为空
	cout << "清除完成" << endl;

}

//单链表读取
int GetElem(LinkList L, int i, int* e) {
	int j;
	LinkList p;  //声明一个指针 p
	p = L->next; //让p指向链表L的第一个结点  L代表的是头结点,构造的时候只加入了第一个结点的地址
	j = 1;      //j为计数器

	while (p && j < i) {  // p不为空指针且j还没有遍历到i时，循环继续
		p = p->next;  //p指向下一个结点
		++j;
	}

	if (!p || j > i)
		return -1;

	*e = p->data;  // int --> int  e是个地址 所以用*e
	return *e;
}

int main() {

	int arr[] = { 0,1,2,4,5,6,7,0,0,0};
	int len = 7;
	int max_size = 10;
	//bool flag = ListInsert(arr, 10, 5, len, max_size);
	//for (int i = 0; i < max_size; ++i)
	//	cout << arr[i] << " ";
	//cout << endl;

	LinkList L;

	//CreateListHead(&L, 10);
	CreateListTail(&L, 10);
	int e = 0;
	//int get_ele = GetElem(L, 3, &e);  //要传入的是e的地址
	//cout << get_ele << endl;
	ListInsert(&L, 2, 60);
	ListDelete(&L, 4, &e);
	system("pause");
	return 0;
}