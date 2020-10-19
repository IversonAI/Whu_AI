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

//判断为空
bool arrayQueue::isEmpty()
{
	if (length == 0)
		return true;
	else
		return false;
}

//队列长度
int arrayQueue::isLength()
{
	 
	return length;
}


//判断队为满
bool arrayQueue::isFull()
{
	if (length == capacity)
		return true;
	else

		return false;

}
//入队
void arrayQueue::enQueue(int q)
{
	//判断是否需要扩容
	if (isFull())
	{
		cout << "Queue full, automatically expanded!\n";
		int index = 0;
		capacity <<= 1;//指数倍扩大容量
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
//出队
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

//获取头结点元素
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