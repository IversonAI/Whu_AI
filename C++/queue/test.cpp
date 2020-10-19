#include "arrQueue.h"
#include<iostream>

using namespace std;

int main() {
	arrayQueue aq(-1);
	//arrayQueue aq(12);//初始化队列
	printf("%d\n", aq.capacity);

	for (int i = 0; i < 8; i++)
	{
		aq.enQueue(i);
		
	}
	//printf("%d\n",aq.isLength());
	aq.visit();
	for (int i = 0; i < 8; i++)
	{
		aq.enQueue(i);

	}
	aq.visit();

	for (int i = 0; i < 5; i++)
	{
		aq.deQueue();

	}


	aq.visit();
	cout<<aq.getHead()<<endl;
	aq.clear();

	aq.deQueue();

	aq.visit();
	system("pause");
	return 0;
}
