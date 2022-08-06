/*
* ��̬����
*	�������һ�������һ��Ԫ����Ϊ����Ԫ�ش�����������
*	δ��ʹ�õ�����Ԫ�س�Ϊ��������
*	�����һ��Ԫ�أ����±�Ϊ0��Ԫ�ص�cur�ʹ�ű�������ĵ�һ�������±ꣻ
	����������һ��Ԫ�ص�cur��ŵ�һ������ֵ��Ԫ�ص��±꣬�൱�ڵ������е�ͷ��������
*/
#include<iostream>

using namespace std;

const int MAXSIZE = 1000;

typedef struct{
	int data;
	int cur;    //�α꣬Ϊ0ʱ��ʾ��ָ��
}Component, StaticLinkList[MAXSIZE];

void InitList(StaticLinkList space) {
	
	for (int i = 0; i < MAXSIZE; ++i) {
		space[i].cur = i + 1;   //�±������
	}
	space[MAXSIZE - 1].cur = 0;  //Ŀǰ�ľ�̬����Ϊ�գ����һ��Ԫ�ص�curΪ0
	cout << "��ʼ����̬����ɹ�" << endl;
}

//�����ÿռ�����ǿգ��򷵻ط���Ľ���±꣬���򷵻�0
int Malloc_SLL(StaticLinkList space) {
	int i = space[0].cur;  //��ǰ�����һ��Ԫ�ص�cur��ֵ���õ��ľ��ǵ�һ�����ÿռ���±�

	if (space[0].cur)
		space[0].cur = space[i].cur; //ע������һ���õ���i��ʵ���ǵõ����ÿռ�ĵ�һ����ʹ�õĽ����������±꣩
		                             //Ҫ�ó���һ������ʹ�ã�����Ӧ��������һ���������������ã��滻����
	                                 //ʵ��������malloc�ĺ���������
	return i;          //���ص������Ǽ���ʹ�õ�����������±�  
}

int Listlenth_SLL(StaticLinkList space) {
	int len = 0;
	int i = space[MAXSIZE - 1].cur;
	while (i) {
		len++;
		i = space[i].cur;   //ֱ��cur��Ϊ0��ʱ��˵����̬�����е�Ԫ���Ų���ϣ��õ������ݵ��ܳ���
	}

	return len;
}

void ListInsert(StaticLinkList space, int i, int e) { // �ھ�̬����L�е�i��λ�ò����µ�Ԫ��e��i��1��ʼ

	int j, k, l;
	if ((i < 1) || (i > Listlenth_SLL(space) + 1))
		cout << "����ʧ��" << endl;
	l = Malloc_SLL(space);   //��ñ���Ԫ�ص��±�
	j = MAXSIZE - 1;   //��һ�������ݵ�λ��

	if (j != 0) {
		space[l].data = e;    //��ֵ
		for (k = 0; k < i - 1; ++k) {  //�ҵ���i������������Ԫ��֮ǰ�ģ�Ԫ��֮ǰ��λ��
			j = space[j].cur;
		}
		space[l].cur = space[j].cur;  //��ֵԭ�����j��ָ�����һ��λ��
		space[j].cur = l;
		cout << "����ɹ�" << endl;
	}
}

void Free_SLL(StaticLinkList space, int i){
	space[i].cur = space[0].cur; //�ѵ�һ��Ԫ��curֵ����Ҫɾ���ķ���cur
	space[0].cur = i;  //��Ҫɾ���ķ����±긳ֵ����һ��Ԫ�ص�cur,�����ɾ���Ľ����ս����õ�������
}

void ListDelete(StaticLinkList space, int i) {
	int j, k;
	if (i < 1 || i > Listlenth_SLL(space))
		cout << "ɾ��ʧ�� .." << endl;

	k = MAXSIZE - 1;
	for (j = 1; j <= i - 1; ++j) {
		k = space[k].cur;
	}

	j = space[k].cur;  //��ʱ����Ǽ���ɾ�����Ǹ��±�
	space[k].cur = space[j].cur;  //������ɾ��������±��Ӧ�ĺ�̽����±���и�ֵ
	Free_SLL(space, j);
	cout << "ɾ���ɹ� .." << endl;
}


int main() {
	StaticLinkList space;  //StaticLinkList[MAXSIZE] ֱ�Ӷ����˾���MAXSIZE��Ԫ�صĽṹ���������ͣ���ע�������ͣ������Ǳ���
	InitList(space);

	ListInsert(space, 1, 99);
	ListInsert(space, 2, 100);
	ListInsert(space, 3, 101);
	ListInsert(space, 4, 102); 
	ListInsert(space, 3, 99);
	//for (int i = 1; i < 6; ++i) {
	//	cout << space[i].data << " " << space[i].cur << endl;
	//}


	system("pause");
	return 0;
}