#include<iostream>


void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}
void combSort(int data[], int n)
{
	int step = n, j, k;
	while ((step = int(step / 1.3)) > 1)
		for (j = n - 1; j >= step; j--)
		{
			k = j - step;
			if (data[j] < data[k])
				swap(data[j], data[k]);
		}
	bool again = true;
	for (int i = 0; i < n - 1 && again; i++)
		for (j = n - 1, again = false; j > i; --j)
			if (data[j] < data[j - 1])
			{
				swap(data[j], data[j - 1]);
				again = true;
			}
}

int main() {
	int a[] = { 3,11,52,5,66,10,9,5,20,11,69,35 };
	int length = sizeof(a) / sizeof(a[0]);
	combSort(a, length);

	for (int i = 0; i < length; i++)
		printf("%d\n", a[i]);
	system("pause");
	return 0;
}