/*
* �������ǲ��ȶ������򣬿ռ临�Ӷ�ΪO(1),ƽ����ʱ�临�Ӷ�ΪO(nlogn),������Ҳ�ȶ���O(nlogn) 
*/

#include<iostream>
using namespace std;

void HeapAdjust(int arr[], int start, int end) {

	int dad = start;
	int son = dad * 2 + 1;
	while (son <= end) {
		if (son + 1 <= end && arr[son] < arr[son + 1]) {  //���Һ��Ӳ�������С���Һ���
			son++;
		}
		if (arr[dad] > arr[son])
			return;
		else {
			swap(arr[dad], arr[son]);   // ǰ���Ѿ��Ƚϵ��������ӵĴ�С����ѡ�������Ǹ����Ӻ͸����Ƚ�
			dad = son;
			son = dad * 2 + 1;
		}
	}
}

void HeapSort(int arr[], int len) {

	// ��һ�ν����󶥶ѣ��Ӻ���ǰ���ε�����Ϊ�����������׼��
	// len / 2 - 1 ���������鳤����������ĵ�һ����Ҷ�ӽڵ���������������ң�
	for (int i = len / 2 - 1; i >= 0; --i) {
		HeapAdjust(arr, i, len - 1);
	}

	// �Ƚ���һ��Ԫ�غ��Ѿ�����õ�Ԫ��ǰһλ�������������µ�����ֱ���������
	for (int i = len - 1; i > 0; --i) {
		swap(arr[0], arr[i]);
		HeapAdjust(arr, 0, i - 1);   // ��һ���Ǵ�������
	}
}

int main() {

	int arr[] = { 9,5,6,3,5,3,1,0,96,66};
	HeapSort(arr, 10);   // �Ӵ�С
	for (auto xx : arr)
		cout << xx << endl;
	cout << endl;

	system("pause");
	return 0;
}