#include<iostream>

using namespace std;

//˵����˳������ʺ��ڴ洢�ṹΪ˳��洢�����Ӵ洢�����Ա�
//����������ҡ�
//ʱ�临�Ӷ�ΪO(n)��

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