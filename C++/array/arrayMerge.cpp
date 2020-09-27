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
		res[index++] = a[index1++];////�����ʣ��Ԫ������res��
	}
	while (index2 <= end)
	{
		res[index++] = a[index2++];////��������ʣ��Ԫ������res��
	}
	for (int i = start; i <= end; i++)
	{
		a[i] = res[i];//��temp�е�Ԫ��ȫ��������ԭ������
	}
}


void mergeSort(int a[], int start, int end, int res[])
{
	if (start == end)
		return;

	cout << "sort" << "	" << start << "	" << end << endl;
	int mid = (start + end) / 2;
	cout << "left" << "	" << start << "	" << mid << endl;
	mergeSort(a, start, mid, res);//�������
	cout << "right	" << mid + 1 << "	" << end << endl;
	mergeSort(a, mid + 1, end, res);//�ұ�����
	cout << "merge	" << start << "	" << end << endl;
	mergeArray(a, start, mid, end, res);//�ٽ����������кϲ�
}


int main() {
	int a[] = { 8,4,5,7,1,3,6,2 };
	int length = sizeof(a) / sizeof(a[0]);
	//������ǰ���Ƚ���һ�����ȵ���ԭ���鳤�ȵ���ʱ���飬����ݹ���Ƶ�����ٿռ�
	int *temp = new int[length];
	mergeSort(a, 0, length - 1, temp);
	for (int i = 0; i < length; i++)
		cout << a[i] << endl;
	system("pause");
	return 0;

}