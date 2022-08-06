/*
* 静态链表
*	对数组第一个和最后一个元素作为特殊元素处理，不存数据
*	未被使用的数组元素称为备用链表
*	数组第一个元素，即下标为0的元素的cur就存放备用链表的第一个结点的下标；
	而数组的最后一个元素的cur存放第一个有数值的元素的下标，相当于单链表中的头结点的作用
*/
#include<iostream>

using namespace std;

const int MAXSIZE = 1000;

typedef struct{
	int data;
	int cur;    //游标，为0时表示无指向
}Component, StaticLinkList[MAXSIZE];

void InitList(StaticLinkList space) {
	
	for (int i = 0; i < MAXSIZE; ++i) {
		space[i].cur = i + 1;   //下标的延伸
	}
	space[MAXSIZE - 1].cur = 0;  //目前的静态链表为空，最后一个元素的cur为0
	cout << "初始化静态链表成功" << endl;
}

//若备用空间链表非空，则返回分配的结点下标，否则返回0
int Malloc_SLL(StaticLinkList space) {
	int i = space[0].cur;  //当前数组第一个元素的cur的值，得到的就是第一个备用空间的下标

	if (space[0].cur)
		space[0].cur = space[i].cur; //注意上面一步得到的i其实就是得到备用空间的第一个待使用的结点的索引（下标）
		                             //要拿出来一个分量使用，所以应把他的下一个分量拿来做备用（替换掉）
	                                 //实现类似于malloc的函数的作用
	return i;          //返回的是我们即将使用的这个分量的下标  
}

int Listlenth_SLL(StaticLinkList space) {
	int len = 0;
	int i = space[MAXSIZE - 1].cur;
	while (i) {
		len++;
		i = space[i].cur;   //直到cur不为0的时候，说明静态链表中的元素排查完毕，得到有数据的总长度
	}

	return len;
}

void ListInsert(StaticLinkList space, int i, int e) { // 在静态链表L中第i个位置插入新的元素e，i从1开始

	int j, k, l;
	if ((i < 1) || (i > Listlenth_SLL(space) + 1))
		cout << "插入失败" << endl;
	l = Malloc_SLL(space);   //获得备用元素的下标
	j = MAXSIZE - 1;   //第一个有数据的位置

	if (j != 0) {
		space[l].data = e;    //赋值
		for (k = 0; k < i - 1; ++k) {  //找到第i个（插入的这个元素之前的）元素之前的位置
			j = space[j].cur;
		}
		space[l].cur = space[j].cur;  //赋值原本这个j所指向的下一个位置
		space[j].cur = l;
		cout << "插入成功" << endl;
	}
}

void Free_SLL(StaticLinkList space, int i){
	space[i].cur = space[0].cur; //把第一个元素cur值赋给要删除的分量cur
	space[0].cur = i;  //把要删除的分量下标赋值给第一个元素的cur,将这个删除的结点回收进备用的链表中
}

void ListDelete(StaticLinkList space, int i) {
	int j, k;
	if (i < 1 || i > Listlenth_SLL(space))
		cout << "删除失败 .." << endl;

	k = MAXSIZE - 1;
	for (j = 1; j <= i - 1; ++j) {
		k = space[k].cur;
	}

	j = space[k].cur;  //此时这个是即将删除的那个下标
	space[k].cur = space[j].cur;  //将即将删除的这个下标对应的后继结点的下标进行赋值
	Free_SLL(space, j);
	cout << "删除成功 .." << endl;
}


int main() {
	StaticLinkList space;  //StaticLinkList[MAXSIZE] 直接定义了具有MAXSIZE个元素的结构体数组类型！！注意是类型，而不是变量
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