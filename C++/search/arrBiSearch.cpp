#include<iostream>

using namespace std;

//���ֲ��ҷ�������һ�������Ԫ�أ����������ڵ�λ�õ��±꣬
//����Ҫ��һ����������飬

//һ��ѭ��������֧������������03_Vector
int biSearch(int arr[], int len, int val)
{
	while (1)
	{
		int start = 0;
		int end = len - 1;
		while (start<=end)
		{
			int mid = (start + end) / 2;
			int mid_val = arr[mid];//�����м���Ϊ��׼ֵ
			if (mid_val == val)//mid�������в���ֵ
			{
				return mid;
			}
			else if(mid_val>val)//�м�ֵ����Ҫ���ҵ�ֵ����ʾ�����
			{
				end = mid - 1;
			}
			else if(mid_val<val)//�м�ֵС��Ҫ���ҵ�ֵ����ʾ���Ҳ�
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
	printf("��������λ���±�Ϊ%d\n", location);
	system("pause");
	return 0;
}