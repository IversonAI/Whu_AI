#include<iostream>

using namespace std;

template<class T>
class MaxHeap
{
private:
	T *mHeap;//����
	int mCapacity;//�ܵ�����
	int mSize;//ʵ�ʴ�С

	//�������µ���
	void filterdown(int start, int end);
	//�������ϵ���(������0��
	void filterup(int start);

	// ���ڵ������
	int parent(int root) {
		return (root-1) / 2;
	}
	// ���ӵ�����
	int left(int root) {
		return root * 2 + 1;
	}

public:
	MaxHeap();
	MaxHeap(int capacity);
	~MaxHeap();

	int getIndex(T data);//����data������
	int remove(T data);//ɾ��
	int insert(T data);//����
	void print();//��ӡ

};

template<class T>
void MaxHeap<T>::filterdown(int start, int end)
{
	int l = left(start);
	T tmp = mHeap[start];

	while (l<=end)
	{
		if (l < end &&mHeap[l] < mHeap[l + 1])
			l++;
		if (tmp >= mHeap[l])
			break;
		else
		{
			mHeap[start] = mHeap[l];
			start = l;
			l = left(l);
		}

	}
	mHeap[start] = tmp;
}

template<class T>
void MaxHeap<T>::filterup(int start)
{
	//start -- ���ϵ��ڵ����ʼλ��(һ��Ϊ���������һ��Ԫ�ص�����)
	T tmp = mHeap[start];
	int p = parent(start);

	while (start > 0)
	{
		if (mHeap[p] >= tmp)
			break;
		else
		{
			mHeap[start] = mHeap[p];
			start = p;
			p = parent(p);
		}
	}
	mHeap[start] = tmp;
}

template<class T>
MaxHeap<T>::MaxHeap()
{
	new(this)MaxHeap(30);
}

template<class T>
MaxHeap<T>::MaxHeap(int capacity)
{
	mSize = 0;
	mCapacity = capacity;
	mHeap = new T[mCapacity];
}

template<class T>
MaxHeap<T>::~MaxHeap()
{
	mSize = 0;
	mCapacity = 0;
	delete[] mHeap;
}

template<class T>
int MaxHeap<T>::getIndex(T data)
{
	for (int i = 0; i < mSize; i++)
	{
		if (data = mHeap[i])
			return i;
	}
	return -1;
}

template<class T>
int MaxHeap<T>::remove(T data)
{
	int index;
	if (mSize == 0)
		cout << "�ѿգ�" << endl;
	index = getIndex(data);
	if (index == -1)
		return -1;
	mHeap[index] = mHeap[--mSize];
	filterdown(index, mSize - 1);
	return 0;
}

template<class T>
int MaxHeap<T>::insert(T data)
{
	//��������
	if (mSize == mCapacity)
		cout << "������" << endl;
	else
	{
		mHeap[mSize] = data;//�����������
		filterup(mSize);//�ϸ�
		mSize++;//ʵ�ʴ�С+1
	}
	return 0;
}

template<class T>
void MaxHeap<T>::print()
{
	for (int i = 0; i < mSize; i++)
		cout << mHeap[i] <<" ";
}



int main()
{
	int a[] = { 10,40,30,60,90,70,20,50,80 };
	int i, len = sizeof(a) / sizeof(a[0]);

	MaxHeap<int> tree(30);

	cout << "������ӣ�";
	for (i = 0; i < len; i++)
	{
		cout << a[i] << " ";
		tree.insert(a[i]);
	}

	cout << endl;

	cout << "����Ϊ��";
	tree.print();

	cout << endl;
	i = 85;
	tree.insert(i);
	cout << "���Ԫ�أ�" << i << endl;
	cout << "����Ϊ��";
	tree.print();

	cout << endl;
	i = 90;
	tree.remove(i);
	cout << "ɾ��Ԫ�أ�" << i << endl;
	cout << "����Ϊ��";
	tree.print();
	cout << endl;

	system("pause");
	return 0;

}
