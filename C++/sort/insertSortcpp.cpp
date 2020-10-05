#include<iostream>

//插入排序——时间复杂度O(n²)
void insertSort(int data[], int n)
{
	for (int i = 1, j; i < n; i++)
	{
		int temp = data[i];
		for (j = i; j > 0 && temp < data[j - 1]; j--)
			data[j] = data[j - 1];
		data[j] = temp;
	}
}

int main()
{
	int a[] = { 6,3,4,9,1,12 };
	int length = sizeof(a) / sizeof(a[0]);
	insertSort(a, length);
	for (int i = 0; i < length; i++)
		printf("%d\n", a[i]);
	system("pause");

	return 0;

}