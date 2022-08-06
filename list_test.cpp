#include<iostream>
#include<time.h>

using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

typedef struct Node* LinkList;

void creat_list_head(LinkList* L, int num) {

	LinkList tmp;
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;

	srand(time(0));
	for (int i = 0; i < num; ++i) {
		tmp = (LinkList)malloc(sizeof(Node));
		int data_ = rand() % 100 + 1;
		tmp->data = data_;
		tmp->next = (*L)->next;
		(*L)->next = tmp;
	}
	cout << "初始化单链表 .." << endl;
}

void creat_list_tail(LinkList* L, int num) {
	LinkList tmp1, tmp2;
	*L = (LinkList)malloc(sizeof(Node));
	tmp1 = *L;

	for (int i = 0; i < num; ++i) {
		tmp2 = (LinkList)malloc(sizeof(Node));
		int data_ = rand() % 100 + 1;
		tmp2->data = data_;

		tmp1->next = tmp2;
		tmp1 = tmp2;
	}

	tmp1->next = NULL;
	cout << "初始化单链表 .." << endl;
}

void get_element(LinkList L, int num) {
	int j;
	LinkList p;
	p = L->next;
	j = 1;

	while (p && j < num) {
		p = p->next;
		++j;
	}

	if (!p || j > num)
		cout << "error .." << endl;

	cout << "data is : " << p->data << endl;
}

void delete_list(LinkList* L, int num) {
	int j;
	LinkList p, q;
	p = (*L);
	j = 1;
	while (p->next && j < num) {
		p = p->next;
		++j;
	}

	if (!(p->next) || j > num) {
		cout << "删除失败" << endl;
	}

	q = p->next;
	p->next = q->next;
	int e = q->data;
	free(q);
	cout << "删除成功" << endl;

}

void insert_list(LinkList* L, int num, int e) {
	int j;
	LinkList p, q;
	q = (LinkList)malloc(sizeof(Node));
	p = (*L);
	j = 1;

	while (p && j < num) {
		p = p->next;
		++j;
	}

	if (!p || j > num)
		cout << "插入失败 .." << endl;

	q->data = e;
	q->next = p->next;
	p->next = q;
	cout << "插入成功 .." << endl;

}

void clear_list(LinkList* L) {
	LinkList p, q;
	p = (*L)->next;

	while (p) {
		q = p->next;
		free(p);
		p = q;
	}
	(*L)->next = NULL;
	cout << "全部删除 .." << endl;
}

int main() {


	LinkList L;
	//creat_list_head(&L, 10);
	creat_list_tail(&L, 20);
	get_element(L, 3);
	delete_list(&L, 3);
	insert_list(&L, 3, 70);
	clear_list(&L);
	system("pause");
	return 0;
}