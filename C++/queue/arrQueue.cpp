#include "arrQueue.h"
#include<iostream>
using namespace std;



arrayQueue::arrayQueue() {
	capacity = 10;
	arr = new int[capacity];
	head = 0;
	tail = 0;
	length = 0;
}
arrayQueue::arrayQueue(int cap)
{
	if (cap <= 0)
	{
		cout << "Capacity must be positive!Initialize the queue by default.\n" << endl;
		capacity = 10;
	}
	else
	{
		capacity = cap;
	}
	arr = new int[capacity];
	head = 0;
	tail = 0;
	length = 0;
}
arrayQueue::~arrayQueue()
{
	delete[]arr;
	arr = NULL;
}

//�ж�Ϊ��
bool arrayQueue::isEmpty()
{
	if (length == 0)
		return true;
	else
		return false;
}

//���г���
int arrayQueue::isLength()
{
	 
	return length;
}


//�ж϶�Ϊ��
bool arrayQueue::isFull()
{
	if (length == capacity)
		return true;
	else

		return false;

}
//���
void arrayQueue::enQueue(int q)
{
	//�ж��Ƿ���Ҫ����
	if (isFull())
	{
		cout << "Queue full, automatically expanded!\n";
		int index = 0;
		capacity <<= 1;//ָ������������
		int *newArr = new int[capacity];
		for (int i = 0; i < isLength(); i++)
		{
			index = head + i;
			newArr[i] = arr[index];
		}
		delete[]arr;
		arr = newArr;
		head = 0;
		tail = isLength();
	}
	arr[tail] = q;
	tail = (tail + 1) % capacity;
	length += 1;

}
//����
int arrayQueue::deQueue()
{
	if (!isEmpty())
	{
		int preHead = head;
		head = (head + 1) % capacity;
		length--;
		return arr[preHead];
	}
	else
	{
		cout << "Queue underflow!\n";
	}

}

//��ȡͷ���Ԫ��
int arrayQueue::getHead()
{
	if (!isEmpty())
		return arr[head];
	else
	{
		cout << "Queue is empty!\n";
		return NULL;
	}
}

void arrayQueue::visit()
{
	if (isEmpty())
	{
		cout << "Queue is empty!\n";
	}
	else
	{
		int index = 0;
		for (int i = 0; i < isLength(); i++)
		{
			index = (head + i) % capacity;
			cout << arr[index] << "	";
		}
		cout << endl;
	}
}

void arrayQueue::clear()
{
	length = 0;
	head = 0;
	tail = 0;
	return;
}