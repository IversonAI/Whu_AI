#include<iostream>

void bubbleSort(int data[], int n)
{
	bool again = true;//���ñ�־������ѭ������
	for (int i = 0; i < n - 1 && again; i++)
		for (int j = n - 1; j > i; --j)
			if (data[j] < data[j - 1])
			{
				int tmp = data[j];
				data[j] = data[j - 1];
				data[j - 1] = tmp;
				again = true;
			}
}
//���������򲻶� �ο����������㷨��
//{
//	for (int i = 1, j; i <= n - 1; i++) //n��������ֻ�ý���n-1��
//	{
//		for (j = 1; j <= n - i; j++) //�ӵ�1λ��ʼ�Ƚ�ֱ�����һ����δ��λ����
//		{
//			if (data[j] < data[j + 1]) //�Ƚϴ�С������
//			{
//				int t = data[j];
//				data[j] = data[j + 1];
//				data[j + 1] = t;
//			}
//		}
//	}
//}
int main() {
	int a[] = { 3,1,9,5,8,6,2,10 };
	int length = sizeof(a) / sizeof(a[0]);
	bubbleSort(a, length);
	for (int i = 0; i < length; i++)
		printf("%d\n", a[i]);
	system("pause");
	return 0;
}