#include<iostream>

using namespace std;


template<class T>
class MinHeap
{
private:
	T *mHeap;
	int mCapacity;
	int mSize;

	void filterdown(int start, int end);
	void filterup(int start);

	int parent(int root) { return (root - 1) / 2; }
	int left(int root) { return root * 2 + 1; }
	
public:
	MinHeap();
	MinHeap(int capacity);
	~MinHeap();

	void insert(T data);
	void remove(T data);
	int getIndex(T data);
	void print();
};

template<class T>
void MinHeap<T>::filterdown(int start, int end)
{
	T tmp = mHeap[start];
	int l = left(start);
	while (l <= end)
	{
		if (l < end&&mHeap[l] > mHeap[l + 1])
			l++;
		if (tmp <= mHeap[l])
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
void MinHeap<T>::filterup(int start)
{
	T tmp = mHeap[start];
	
	while (start > 0)
	{
		int p = parent(start);
		if (mHeap[p] <= tmp)
			break;
		else
		{
			mHeap[start] = mHeap[p];
			start = p;
		}
	}
	mHeap[start] = tmp;
}

template<class T>
MinHeap<T>::MinHeap()
{
	new(this)MinHeap(30);
}

template<class T>
MinHeap<T>::MinHeap(int capacity)
{
	mSize = 0;
	mCapacity = capacity;
	mHeap = new T[mCapacity];
}

template<class T>
MinHeap<T>::~MinHeap()
{
	mSize = 0;
	mCapacity = 0;
	delete[] mHeap;
}

template<class T>
void MinHeap<T>::insert(T data)
{
	if (mSize == mCapacity)
		cout << "堆满！";
	else
	{
		mHeap[mSize] = data;
		filterup(mSize);
		mSize++;
	}
}

template<class T>
void MinHeap<T>::remove(T data)
{
	int index;
	index = getIndex(data);
	if (mSize == 0)
		cout << "堆空！";
	else
	{
		mHeap[index] = mHeap[--mSize];
		filterdown(index, mSize - 1);
	}
}

template<class T>
int MinHeap<T>::getIndex(T data)
{
	for (int i = 0; i < mSize; i++)
	{
		if (mHeap[i] = data)
			return i;
	}
	cout << "该元素不在堆内！";
	return -1;
}

template<class T>
void MinHeap<T>::print()
{
	for (int i = 0; i < mSize; i++)
	{
		cout << mHeap[i] << " ";
	}
}

int main()
{
	int a[] = {80, 40, 30, 60, 90, 70, 10, 50, 20 };
	int i, len = sizeof(a) / sizeof(a[0]);

	MinHeap<int> *tree = new MinHeap<int>();

	cout << "依次添加：";
	for (i = 0; i < len; i++)
	{
		cout << a[i] << " ";
		tree->insert(a[i]);
	}

	cout << endl;

	cout << "最小堆为：";
	tree->print();

	cout << endl;
	i = 15;
	tree->insert(i);
	cout << "添加元素：" << i << endl;
	cout << "最小堆为：";
	tree->print();

	cout << endl;
	i = 10;
	tree->remove(i);
	cout << "删除元素：" << i << endl;
	cout << "最小堆为：";
	tree->print();
	cout << endl;

	system("pause");
	return 0;
}