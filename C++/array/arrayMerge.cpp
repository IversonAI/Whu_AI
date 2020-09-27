#include <iostream>
using namespace std;

void mergeArray(int a[], int start, int mid, int end, int res[])
{
	int length = end - start + 1;
	int index1 = start, index2 = mid + 1;
	int index = start;

	while (index1 <= mid && index2 <= end)
	{
		if (a[index1] < a[index2])
		{
			res[index++] = a[index1++];
		}
		else
		{
			res[index++] = a[index2++];
		}
	}

	while (index1 <= mid)
	{
		res[index++] = a[index1++];////将左边剩余元素填充进res中
	}
	while (index2 <= end)
	{
		res[index++] = a[index2++];////将右序列剩余元素填充进res中
	}
	for (int i = start; i <= end; i++)
	{
		a[i] = res[i];//将temp中的元素全部拷贝到原数组中
	}
}


void mergeSort(int a[], int start, int end, int res[])
{
	if (start == end)
		return;

	cout << "sort" << "	" << start << "	" << end << endl;
	int mid = (start + end) / 2;
	cout << "left" << "	" << start << "	" << mid << endl;
	mergeSort(a, start, mid, res);//左边有序
	cout << "right	" << mid + 1 << "	" << end << endl;
	mergeSort(a, mid + 1, end, res);//右边有序
	cout << "merge	" << start << "	" << end << endl;
	mergeArray(a, start, mid, end, res);//再将俩有序数列合并
}


int main() {
	int a[] = { 8,4,5,7,1,3,6,2 };
	int length = sizeof(a) / sizeof(a[0]);
	//在排序前，先建好一个长度等于原数组长度的临时数组，避免递归中频繁开辟空间
	int *temp = new int[length];
	mergeSort(a, 0, length - 1, temp);
	for (int i = 0; i < length; i++)
		cout << a[i] << endl;
	system("pause");
	return 0;

}