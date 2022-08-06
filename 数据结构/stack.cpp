/*
* �����ݽṹChapter 4:ջ�Ͷ���
*	1.˳��ջ
*/
#include<iostream>

using namespace std;

typedef int SElemType;  //������ʵ�����ͽ��ж���

void printUI() {
    cout << "*******************************************************" << endl;
    cout << "*********  1.��ʼ��Ϊ��ջ                     *********" << endl;
    cout << "*********  2.����ջ                           *********" << endl;
    cout << "*********  3.��ջ�ÿ�                         *********" << endl;
    cout << "*********  4.�ж�ջ�Ƿ�Ϊ��ջ                 *********" << endl;
    cout << "*********  5.����ջ�ĳ���                     *********" << endl;
    cout << "*********  6.��ջ��Ԫ��                       *********" << endl;
    cout << "*********  7.����Ԫ�أ���ʹ���Ϊջ��Ԫ��     *********" << endl;
    cout << "*********  8.ɾ��ջ��Ԫ�أ���������ֵ         *********" << endl;
    cout << "*********  9.���ջ��Ԫ��                     *********" << endl;
    cout << "*********  10.����������ջԪ��                *********" << endl;
    cout << "*********  11.����ת��                        *********" << endl;
    cout << "*********  12.�˳�                            *********" << endl;
    cout << "*******************************************************" << endl;
}

//ջ��Ԫ��
struct SqStack {
	SElemType *base = nullptr;  //ջ��
	SElemType *top = nullptr;  //ջ��, �����������*top,�����Ա�ʾΪ SElemType top = -1 (-1������������б�������)
	int stacksize;             //ջ��С
};

/*
* ��ʼ��ջ   ����һ�ֶ�̬�����ڴ�ķ���
 * @param S
 * @return true
 * @return false
*/
bool InitStack(SqStack& S, int MAXSIZE) {
    S.base = new SElemType[MAXSIZE];   //new����һ���µĵ�ַ��������Խ��� 
    S.top = S.base;                   //��ʼ����ʱ��ջ����ջ�׵�λ������һ���
    S.stacksize = MAXSIZE;
    return true;
}

/*
* ����ջ
 * @param S
 * @return true
 * @return false
*/
bool DestroyStack(SqStack& S) {
    if (S.base) {
        delete[] S.base;
        S.stacksize = 0;
        S.base = S.top = nullptr;
    }
    //cout << S.top << " " << S.base << endl;   // 00000000 00000000

    return true;
}

/*���ջ
 * @param S
 * @return true
 * @return false
*/
bool ClearStack(SqStack& S) {
    if (S.base)
        S.top = S.base;   //ֱ����ջ����ջ����ȣ����ǲ�û�н�������
    /*cout << S.top << " " << S.base << endl;*/
    return true;
}

/*
* �ж�ջ�Ƿ�Ϊ��
 * @param S
 * @return true
 * @return false
*/
bool StackEmpty(SqStack& S) {
    if (S.top == S.base) {
        return true;
    }
    return false;
}

/*��˳��ջ�ĳ���
 * @param S
 * @return int
*/
int StackLength(SqStack& S) {
    cout << "base: " << S.base << "top: " << S.top<< endl;
    return S.top - S.base;
}

/*ȡջ��Ԫ��
 * @param S
 * @param e
 * @return true
 * @return false
*/
bool GetTop(SqStack S, SElemType& e) {
    if (S.top == S.base)
        return false;
    e = *(S.top - 1);
    //cout << *(S.base) << endl;
    return true;
}

/*
* ����Ԫ��
* @param S
* @param e
* @return true
* @return false
*/
bool Push(SqStack& S, SElemType e) {
    if (S.top - S.base == S.stacksize)
        return false;
    *S.top = e;
    S.top++;   //ָ���ǿ��Խ�������ļӼ��ģ�������ϵ���ʵ��һ��SElemType������ռ���ֽڵĴ�С
    return true;
}

/*
* ��ջ ����Ԫ�ش�ջ��ɾ����
 * @param S
 * @param e
 * @return true
 * @return false
*/

bool Pop(SqStack& S, SElemType& e) {
    if (S.top == S.base)
        return false;
    e = *(S.top-1);
    S.top--;
    return true;
}

/*
* ��ӡԪ��
 * @param S
 * @return true
 * @return false
*/
bool PrintEle(SqStack S) {
    if (S.top == S.base) {
        return false;
    }
    for (SElemType* p = S.top - 1; p >= S.base; p--) {
        cout << *p;
        if (p == S.base)
            cout << endl;
        else
            cout << " " << endl;
    }
    return true;
}

/*
* ʮ����׼ת������
 * @param num
*/
void Dec2Bin(int num) {
    SqStack stack;
    SElemType e;
    InitStack(stack, 100);
    while (num > 0) {
        Push(stack, num % 2);
        num /= 2;
    }
    while (Pop(stack, e))
        cout << e;
    cout << endl;
}

int main() {
	int mode, i;
	SqStack S;     //����һ���ṹ�����
	SElemType e;   //����һ��Ԫ��
    int len;
    int MAXSIZE = 100;
	printUI();
    cout << "�����������ɵ�ջ�Ĵ�С��";
    cin >> MAXSIZE;
    
    while (true) {
        cout << "������������ʾѡ��ģʽ: " << endl;
        cin >> mode;
        if (mode == 12)
            break;
        else if (mode < 1 || mode>12) {
            cout << "��������ȷ��Χ�ڵ�����   ";
            continue;
        }

        if (!S.base && mode != 1 && mode != 10) {
            cout << "��δ��ɳ�ʼ��" << endl;
            continue;
        }

        switch (mode) {
        case 1:
            if (InitStack(S, MAXSIZE))
                cout << "��ʼ��ջ�ɹ�" << endl;
            break;
        case 2:
            if (DestroyStack(S))
                cout << "����ջ�ɹ�" << endl;
            break;
        case 3:
            if (ClearStack(S))
                cout << "���ջ�ɹ�" << endl;
            break;
        case 4:
            if (StackEmpty(S))
                cout << "ջΪ��" << endl;
            else
                cout << "ջ��Ϊ��" << endl;
            break;
        case 5:
            len = StackLength(S);
            cout << "˳��ջ�ĳ���Ϊ: " << len << endl;
            break;
        case 6:
            if (GetTop(S, e))
                cout << "ջ��Ԫ��Ϊ��" << e << endl;
            else
                cout << "��ȡջ��Ԫ��ʧ��" << endl;
            break;
        case 7:
            cout << "�����뽫Ҫ�����Ԫ�أ�" << endl;
            cin >> e;
            if (Push(S, e))
                cout << e << "  ��ջ�ɹ�" << endl;
            else
                cout << e << "  ��ջʧ��" << endl;
            break;
        case 8:
            if (Pop(S, e))
                cout << "ջ��Ԫ��Ϊ��" << e << endl;
            else
                cout << "��ջ��Ԫ��" << endl;
            break;
        case 9:
            if (!PrintEle(S))
                cout << "ջ����Ԫ��" << endl;
            break;
        case 10:
            int n;
            cout << "������Ҫ�����Ԫ�ظ�����" << endl;
            cin >> n;
            if ((n + StackLength(S)) > MAXSIZE) {
                cout << "��������" << endl;
                break;
            }

            InitStack(S, MAXSIZE);
            while (n--) {
                cin >> e;
                Push(S, e);
            }
            break;
        case 11:
            int num;
            cout << "��������Ҫת����ʮ���ƣ�" << endl;
            cin >> num;
            Dec2Bin(num);
            break;
        }
    }
	system("pause");
    return 0;
}