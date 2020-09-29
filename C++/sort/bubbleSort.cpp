#include<iostream>

void bubbleSort(int data[], int n)
{
	bool again = true;//设置标志，减少循环次数
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
//运行完排序不对 参考《啊哈，算法》
//{
//	for (int i = 1, j; i <= n - 1; i++) //n个数排序，只用进行n-1趟
//	{
//		for (j = 1; j <= n - i; j++) //从第1位开始比较直到最后一个尚未归位的数
//		{
//			if (data[j] < data[j + 1]) //比较大小并交换
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