#include<iostream>

using namespace std;

//二分查找法，查找一个数组的元素，并返回所在的位置的下标，
//必须要是一个有序的数组，

//一：循环（三分支）其他方法见03_Vector
int biSearch(int arr[], int len, int val)
{
	while (1)
	{
		int start = 0;
		int end = len - 1;
		while (start<=end)
		{
			int mid = (start + end) / 2;
			int mid_val = arr[mid];//设置中间数为基准值
			if (mid_val == val)//mid正好命中查找值
			{
				return mid;
			}
			else if(mid_val>val)//中间值大于要查找的值，表示在左侧
			{
				end = mid - 1;
			}
			else if(mid_val<val)//中间值小于要查找的值，表示在右侧
			{
				start = mid + 1;
			}

		}
		return -1;
	}
}

int main() {
	int arr[10] = { 1,3,5,7,9,10,16,22,33,56 };
	int location = biSearch(arr, 10, 16);
	printf("所在数组位置下标为%d\n", location);
	system("pause");
	return 0;
}