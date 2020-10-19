#include<iostream>
#include"listQueue.h"

using namespace std;

int main() {
	listQueue lq;
	for (int i = 0; i <10; i++)
		lq.enqueue(i*i);

	lq.visit();
	
	lq.enqueue(100);
	cout << lq.getFront()<<"  "<<lq.getRear()<<endl;

	cout << lq.length << endl;
	lq.dequeue();
	cout << lq.length << endl;
	lq.visit();
	lq.clear();
	cout << lq.length << endl;
	system("pause");
	return 0;

}