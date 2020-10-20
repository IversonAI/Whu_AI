#include<iostream>

using namespace std;

template<class T>
class MaxHeap
{
private:
	T *mHeap;//数据
	int mCapacity;//总的容量
	int mSize;//实际大小

	//最大堆向下调整
	void filterdown(int start, int end);
	//最大堆向上调整(上升到0）
	void filterup(int start);

	// 父节点的索引
	int parent(int root) {
		return (root-1) / 2;
	}
	// 左孩子的索引
	int left(int root) {
		return root * 2 + 1;
	}

public:
	MaxHeap();
	MaxHeap(int capacity);
	~MaxHeap();

	int getIndex(T data);//返回data的索引
	int remove(T data);//删除
	int insert(T data);//插入
	void print();//打印

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
	//start -- 被上调节点的起始位置(一般为数组中最后一个元素的索引)
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
		cout << "堆空！" << endl;
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
	//堆满返回
	if (mSize == mCapacity)
		cout << "堆满！" << endl;
	else
	{
		mHeap[mSize] = data;//插在数组最后
		filterup(mSize);//上浮
		mSize++;//实际大小+1
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

	cout << "依次添加：";
	for (i = 0; i < len; i++)
	{
		cout << a[i] << " ";
		tree.insert(a[i]);
	}

	cout << endl;

	cout << "最大堆为：";
	tree.print();

	cout << endl;
	i = 85;
	tree.insert(i);
	cout << "添加元素：" << i << endl;
	cout << "最大堆为：";
	tree.print();

	cout << endl;
	i = 90;
	tree.remove(i);
	cout << "删除元素：" << i << endl;
	cout << "最大堆为：";
	tree.print();
	cout << endl;

	system("pause");
	return 0;

}
