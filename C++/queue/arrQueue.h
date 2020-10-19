#pragma once


class arrayQueue {

public:
	int *arr;
	int capacity;
	int head;
	int tail;
	int length;


	arrayQueue();
	arrayQueue(int cap);
	~arrayQueue();
	bool isEmpty();
	int isLength();
	bool isFull();
	void enQueue(int q);
	int deQueue();
	int getHead();
	void visit();
	void clear();
};


