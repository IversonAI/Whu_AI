#include<iostream>


//选择排序————时间复杂度O（n²）
void swap(int &a, int &b)
{
	int c;
	c = a;
	a = b;
	b = c;
}
void selectSort(int data[], int n)
{
	for (int i = 0, j, index; i < n - 1; i++)
	{
		for (j = i + 1, index = i; j < n; j++)
			if (data[j] < data[index])
				index = j;
		if (i != index)
			swap(data[index], data[i]);
	}
}

int main() {

	int a[] = { 3,6,1,9,10,5,7 };
	int length = sizeof(a) / sizeof(a[0]);
	selectSort(a, length);
	for (int i = 0; i < length; i++)
		printf("%d\n", a[i]);

	system("pause");
	return 0;
}