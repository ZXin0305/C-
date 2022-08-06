/*
* ��������ǹ��ڴ����ݽṹ�е�һЩdemo����
*/

#include<iostream>
#include<time.h>

using namespace std;

//���Ա����Ԫ��  P52
bool ListInsert(int* arr, int insert_idx, int num, int len, int max_size) {
	insert_idx -= 1;
	if (insert_idx < 0 || (insert_idx + 1) >= max_size)   //�����λ�ò����б�ķ�Χ֮��
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
	struct Node* next;   //ָ������ռ�õ��ڴ��С�ǹ̶��ģ����۸�ָ��ָ�������������ͣ�����32 λϵͳ��Ϊ4 �ֽڣ���64 λϵͳ��Ϊ8 �ֽ�
};

typedef struct Node* LinkList;


//������ĳ�ʼ��
//1.�������n��Ԫ�ص�ֵ����������ͷ���ĵ�����L(ͷ�巨)
void CreateListHead(LinkList* L, int n) {  //�����LinkList��Ҫ������ǵ�ַ����Ȼ�޷��������е�����
	LinkList p;   //������һ��  LinkList�������ָ����ʽ�ģ����Կ���ֱ��д��(*L)->next = p;

	srand(time(0));      //��ʼ�����������
	*L = (LinkList)malloc(sizeof(Node));  //memory allocation�� ��̬�ڴ���䣬��������һ��������ָ����С���ڴ��������void*���ͷ��ط�����ڴ������ַ��
	                                      //���޷�֪���ڴ����λ�õ�ʱ����Ҫ���������ڴ�ռ䣬����Ҫ�õ���̬�ķ����ڴ棬�ҷ���Ĵ�С���ǳ���Ҫ��Ĵ�С
	(*L)->next = NULL;   //�Ƚ���һ����ͷ���ĵ�����

	for (int i = 0; i < n; ++i) {
		p = (LinkList)malloc(sizeof(Node));  //�����½�㣬 ��c++��ֱ��ʹ��new�ͺ���
		p->data = rand() % 100 + 1;     //����������
		cout << p->data << endl;
		p->next = (*L)->next;
		(*L)->next = p;    //���뵽��ͷ
	}
}

//�������β�巨
void CreateListTail(LinkList* L, int n) {
	LinkList p, r;
	srand(time(0));
	*L = (LinkList)malloc(sizeof(Node));
	r = *L;  //rΪָ��β���Ľ��

	for (int i = 0; i < n; ++i) {
		p = (LinkList)malloc(sizeof(Node));
		p->data = rand() % 100 + 1;
		cout << p->data << endl;
		r->next = p;
		r = p;

	}
	r->next = NULL;
}

//������Ĳ���
void ListInsert(LinkList* L, int i, int e) {
	int j;
	LinkList p, s;
	p = *L;
	j = 1;

	while (p && j < i) {  //Ѱ�ҵ�i-1�����
		p = p->next;
		++j;
	}

	if (!p || j > i)
		cout << "����ʧ��" << endl;

	//����һ���µĽ�㣬�ȶ�̬����һ���ڴ�
	s = (LinkList)malloc(sizeof(Node));
	s->data = e;
	s->next = p->next;
	p->next = s;
	cout << "����ɹ�" << endl;
}

//�������ɾ��
void ListDelete(LinkList* L, int i, int* e) {
	int j;
	LinkList p, q;
	p = *L;
	j = 1;

	while (p->next && j < i) {  //����Ѱ�ҵ�i-1�����
		p = p->next;
		++j;
	}
	if (!(p->next) || j > i) {
		cout << "ɾ��ʧ��" << endl;
	}

	q = p->next;  //q����Ҫɾ����������,���Ա���ʱҪͣ����ǰһ�����
	p->next = p->next->next;
	*e = q->data; //��q����е����ݸ�*e
	free(q);   //ϵͳ����q��㣬�ͷ��ڴ�
	cout << "ɾ���ɹ�" << endl;

}

void ClearList(LinkList* L) {
	LinkList p, q;
	p = (*L)->next;  //��һ�����
	while (p) {
		q = p->next;  //Ҫ�Ȱ����������������Ȼ��p����֮����޷���ȡ��
		free(p);
		p = q;
	}

	(*L)->next = NULL;  //ͷ���ָ����Ϊ��
	cout << "������" << endl;

}

//�������ȡ
int GetElem(LinkList L, int i, int* e) {
	int j;
	LinkList p;  //����һ��ָ�� p
	p = L->next; //��pָ������L�ĵ�һ�����  L�������ͷ���,�����ʱ��ֻ�����˵�һ�����ĵ�ַ
	j = 1;      //jΪ������

	while (p && j < i) {  // p��Ϊ��ָ����j��û�б�����iʱ��ѭ������
		p = p->next;  //pָ����һ�����
		++j;
	}

	if (!p || j > i)
		return -1;

	*e = p->data;  // int --> int  e�Ǹ���ַ ������*e
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
	//int get_ele = GetElem(L, 3, &e);  //Ҫ�������e�ĵ�ַ
	//cout << get_ele << endl;
	ListInsert(&L, 2, 60);
	ListDelete(&L, 4, &e);
	system("pause");
	return 0;
}