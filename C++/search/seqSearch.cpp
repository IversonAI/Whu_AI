#include<iostream>

using namespace std;

//说明：顺序查找适合于存储结构为顺序存储或链接存储的线性表。
//属于无序查找。
//时间复杂度为O(n)。

int seqSearch(int arr[], int length, int keyData)
{
	int tmp;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == keyData)
			return i;
	}
}

int main() {
	int a[] = { 1,5,9,10,3,20,95,2 };
	int location = seqSearch(a, 8, 10);
	printf("%d\n", location);
	system("pause");
	return 0;
}