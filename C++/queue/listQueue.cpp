#include "listQueue.h"
#include<iostream>
#include<cstdlib>

using namespace std;

listQueue::listQueue()
{	
	front = nullptr;
	rear = nullptr;
	length = 0;
}

listQueue::~listQueue()
{	
	queueNode *garbage = front;
	while (garbage != nullptr)
	{
		front = front->next;
		garbage->next = nullptr;
		delete garbage;
		garbage = front;
	}
}

void listQueue::enqueue(int num)
{
	if (isEmpty())
	{
		front = new queueNode(num);
		rear = front;
	}
	else
	{
		rear->next = new queueNode(num);
		rear = rear->next;
	}
	length++;
}

void listQueue::dequeue()
{
	queueNode *tmp=nullptr;

	if (isEmpty())
	{
		cout << "The queue is empty!\n";
	}

	else
	{
		
		tmp = front;
		front = front->next;
		delete tmp;
	}
	length--;

}

bool listQueue::isEmpty()
{
	return length == 0;
}

void listQueue::clear()
{
	
	while (!isEmpty())
	{
		dequeue();
	}
}



void listQueue::visit()
{
	if (isEmpty())
		cout << "The queue is empty!\n";
	else
	{
		queueNode *p =front;
		while (p != NULL)
		{
			cout << p->data << "	";
			p = p->next;
		}
		cout << endl;
	}
}
int & listQueue::getFront()
{
	if (0 == length)
		throw isEmpty();
	return front->data;
}

int & listQueue::getRear()
{
	// TODO: 在此处插入 return 语句
	if (0 == length)
		throw isEmpty();
	return rear->data;
}


