#pragma once

class listQueue {
	struct queueNode
	{
		int data;
		queueNode *next;
		queueNode(int data1, queueNode *next1 = nullptr)
		{
			data = data1;
			next = next1;
		}
	};
	queueNode *front;
	queueNode *rear;
public:
	listQueue();
	~listQueue();
	void enqueue(int);
	void dequeue();
	bool isEmpty();
	void clear();
	void visit();
	int &getFront();
	int &getRear();
	int length;
};