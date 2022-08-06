/*
* 堆排序是不稳定的排序，空间复杂度为O(1),平均的时间复杂度为O(nlogn),最坏情况下也稳定在O(nlogn) 
*/

#include<iostream>
using namespace std;

void HeapAdjust(int arr[], int start, int end) {

	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) {
		if (son + 1 <= end && arr[son] < arr[son + 1]) {  //有右孩子并且左孩子小于右孩子
			son++;
		}
		if (arr[dad] > arr[son])
			return;
		else {
			swap(arr[dad], arr[son]);   // 前面已经比较的两个孩子的大小，会选出最大的那个孩子和父结点比较
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void HeapSort(int arr[], int len) {

	// 第一次建立大顶堆，从后往前依次调整，为下面的排序做准备
	// len / 2 - 1 是依据数组长度推算出来的第一个非叶子节点的索引（从左往右）
	for (int i = len / 2 - 1; i >= 0; --i) {
		HeapAdjust(arr, i, len - 1);
	}

	// 先将第一个元素和已经排序好的元素前一位做交换，再重新调整，直到排序完成
	for (int i = len - 1; i > 0; --i) {
		swap(arr[0], arr[i]);
		HeapAdjust(arr, 0, i - 1);   // 这一次是从上往下
	}
}

int main() {

	int arr[] = { 9,5,6,3,5,3,1,0,96,66};
	HeapSort(arr, 10);   // 从大到小
	for (auto xx : arr)
		cout << xx << endl;
	cout << endl;

	system("pause");
	return 0;
}