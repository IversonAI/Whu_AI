#include <iostream>
#include<cmath>
#include<vector>
#include<stdlib.h>
#include<ctime>
using namespace std;

template <typename T>

//����������ڲ��ӱ���
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

//��������
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
	void resize();//����
	void append(T t);//��
	void remove(int loc);//ɾ
	void revise(int loc, T t);//��
	T getElement(int loc);//��
	void concat(Array<T>* array1, Array<T>* array2,
		Array<T>*&array3);//�ϲ�������
};

//����
template<class T>
void Array<T>::resize()
{
	if (size >= maxsize)
	{
		T* newArr;
		//ʹ��ceil������ceil(x)���ص��Ǵ���x����С������
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

//׷��
template<class T>
void Array<T>::append(T t)
{
	if (size >= maxsize)
		resize();
	element[size++] = t;
}

//ɾ��
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

//��
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

//��
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

//�ϲ�2
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
	//��ʼ��ֵ
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		array->append(rand() % 100);
	}
	for (int i = 0; i < 10; i++)
	{
		cout << (*array)[i] << "\t";
	}

	cout << endl << "�޸ĺ�" << endl;
	array->revise(0,100);
	for (int i = 0; i < 10; i++)
	{
		cout << (*array)[i] << "\t";
	}

	cout << endl << "ɾ����" << endl;
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

	cout << endl << "�ϲ���" << endl;
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