#include <iostream>
#include<cmath>
#include<vector>
#include<stdlib.h>
#include<ctime>
using namespace std;

template <typename T>

//快速排序的内部子表划分
void partition(T* &array, int s, int t, T &cutpoint)
{
	T x = array[s];
	int i = s, j = t;
	while (i!=j)
	{
		while (i<j &&array[j]>x)
		{
			j--;
		}
		if (i < j)
		{
			array[i] = array[j];
			i++;
		}
		while (i<j&&array[i]<x)
		{
			i++;
		}
		if (i < j)
		{
			array[j] = array[i];
			j--;
		}
	}
	array[i] = x;
	cutpoint = i;
}

//快速排序
template<typename T>
void quickSort(T *&array, int s, int t)
{
	int i;
	if (s < t)
	{
		partition(array, s, t, i = 0);
		quickSort(array, s, i - 1);
		quickSort(array, i + 1, t);
	}
}

template <class T>
class Array
{
private:
	int size;
	int maxsize;
public:
	T* element;
	Array(int maxsize_ = 3)
	{
		size = 0;
		maxsize = maxsize_;
		element = new T[maxsize];
	}
	~Array()
	{
		delete[]element;
	}
	int & operator[](int loc)
	{
		int i;
		i = this->element[loc];
		return i;
	}
	int getSize() { return size; }
	int getMaxsize() { return maxsize; }
	void resize();//扩容
	void append(T t);//增
	void remove(int loc);//删
	void revise(int loc, T t);//改
	T getElement(int loc);//查
	void concat(Array<T>* array1, Array<T>* array2,
		Array<T>*&array3);//合并两个数
};

//扩容
template<class T>
void Array<T>::resize()
{
	if (size >= maxsize)
	{
		T* newArr;
		//使用ceil函数。ceil(x)返回的是大于x的最小整数。
		int newMaxsize = ceil(maxsize + maxsize / 2);
		newArr = new T[newMaxsize];
		for (int i = 0; i < maxsize; i++)
		{
			newArr[i] = element[i];
		}
		delete []element;
		element = newArr;
		maxsize = newMaxsize;
	}
}

//追加
template<class T>
void Array<T>::append(T t)
{
	if (size >= maxsize)
		resize();
	element[size++] = t;
}

//删除
template<class T>
void Array<T>::remove(int loc)
{
	if (loc >= size)
	{
		cout << "Error,out of array valid range!";
		return;
	}
	else
	{
		if (loc = size - 1)
		{
			size--;
		}
		else
		{
			for (int i = loc; i < size - 1; i++)
			{
				element[i] = element[i++];
			}
			size--;
		}
	}
}

//改
template<class T>
void Array<T>::revise(int loc, T t)
{
	if (loc >= size)
	{
		cout << "Error";
		return;
	}
	else
	{
		element[loc] = t;
	}
}

//查
template<class T>
T Array<T>::getElement(int loc)
{
	if (loc >= size)
	{
		cout << "Error";
		return -1;
	}
	else
	{
		return element[loc];
	}
}

//合并2
template<class T>
void Array<T>::concat(Array<T>*array1, Array<T>*array2, Array<T>*&array3)
{
	int m = array1->getSize(), n = array2->getSize();
	if (m == 0 & n == 0)
		return;
	quickSort(array1->element, 0, m - 1);
	quickSort(array2->element, 0, n - 1);
	if (m == 0)
		array3 = array2;
	if (n == 0)
		array3 = array1;

	int i = 0, j = 0;
	while (i<m&&j<n)
	{
		if (array1->getElement(i) >= array2->getElement(j))
		{
			array3->append(array2->getElement(j));
			j++;
		}
		else
		{
			array3->append(array1->getElement(i));
			i++;
		}
	}
	while(i<m)
	{
		array3->append(array1->getElement(i));
		i++;
	}
	while (j<n)
	{
		array3->append(array2->getElement(j));
		j++;
	}
}










int main() {
	Array<int> *array = new Array<int>(3);
	//初始赋值
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		array->append(rand() % 100);
	}
	for (int i = 0; i < 10; i++)
	{
		cout << (*array)[i] << "\t";
	}

	cout << endl << "修改后：" << endl;
	array->revise(0,100);
	for (int i = 0; i < 10; i++)
	{
		cout << (*array)[i] << "\t";
	}

	cout << endl << "删除后" << endl;
	array->remove(9);
	for (int i = 0; i < 9; i++)
	{
		cout << (*array)[i] << "\t";
	}

	Array<int>* array2 = new Array<int>(5);
	array2->append(10);
	array2->append(100);
	array2->append(1000);
	array2->append(33);
	Array<int> *array3 = new Array<int>(10);

	cout << endl << "合并后" << endl;
	array3->concat(array2, array, array3);
	cout << endl;

	for (int i = 0; i < array3->getSize(); i++)
	{
		cout << (*array3)[i] << "\t";
	}


	delete array;
	delete array2;
	delete array3;

	system("pause");
	return 0;

}