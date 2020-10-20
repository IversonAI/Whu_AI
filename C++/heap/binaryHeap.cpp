#include<iostream>
#include"binaryHeap.h"
#include<time.h>

using namespace std;

int main()
{
	int MAX_ELEMENT = 10;
	Heap<int> heap(MAX_ELEMENT);

	int i;
	srand(time(NULL));
	for (i = 0; i < MAX_ELEMENT; i++)
	{
		heap.push(100 - i, i);
		printf("push:key:%d->value:%d\n", 100 - i, i);
	}
	heap.print_heap();

	for (i = 0; i < MAX_ELEMENT / 2; i++)
	{
		heap.remove(i);
		cout << "remove value:" << i << endl;
	}
	heap.print_heap();

	while (!heap.is_empty())
	{
		Heap<int>::elem e = heap.pop();
		printf("pop:key:%d->value:%d\n", e.key, e.data);
	}
	heap.print_heap();

	system("pause");
	return 0;
}

