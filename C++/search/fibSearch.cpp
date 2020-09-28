#include<iostream>
using namespace std;
const int max_size = 12;
//���Ӷȷ����������£�ʱ�临�Ӷ�ΪO(log2n)�������������Ӷ�ҲΪO(log2n)��

//쳲���������
void fib(int *f)
{
	int i;
	f[0] = 0;
	f[1] = 1;
	for (i = 2; i < max_size; ++i)
	{
		f[i] = f[i - 2] + f[i - 1];
	}
}

//����
//쳲������������۰���Һ����ƣ����Ǹ���쳲��������е��ص���������зָ�ġ���Ҫ��ʼ���м�¼�ĸ���Ϊĳ��쳲�������С1����n = F(k) - 1;
//��ʼ��kֵ���F(k - 1)λ�õļ�¼���бȽ�(��mid = low + F(k - 1) - 1), �ȽϽ��Ҳ��Ϊ����
//1����ȣ�midλ�õ�Ԫ�ؼ�Ϊ����
//2�� > ��low = mid + 1, k -= 2;
//˵����low = mid + 1˵�������ҵ�Ԫ����[mid + 1, high]��Χ�ڣ�k -= 2 ˵����Χ[mid + 1, high]�ڵ�Ԫ�ظ���Ϊn - (F(k - 1)) = Fk - 1 - F(k - 1) = Fk - F(k - 1) - 1 = F(k - 2) - 1�������Կ��Եݹ��Ӧ��쳲��������ҡ�
//3�� < ��high = mid - 1, k -= 1��
//	˵����low = mid + 1˵�������ҵ�Ԫ����[low, mid - 1]��Χ�ڣ�k -= 1 ˵����Χ[low, mid - 1]�ڵ�Ԫ�ظ���ΪF(k - 1) - 1�������Կ��Եݹ� ��Ӧ��쳲��������ҡ�
//

int fibSearch(int *a, int key, int n)
{
	int i, low = 0, high = n - 1;
	int mid = 0;
	int k = 0;
	int F[max_size];
	fib(F);
	while (n > F[k] - 1)
		++k;//����ѭ����õ�n>F��k��-1��k���ټ�һ�Ӷ���ʱF��k��һ������n  
	
	int  * temp;//������a��չ��F[k]-1�ĳ���  
	temp = new int[F[k] - 1];
	memcpy(temp, a, n * sizeof(int));
	for (i = n; i < F[k] - 1; i++)//�����Ҫ�����������������
		temp[i] = a[n-1];//�����ֵ�ظ��������


	//��ʼ�ж�
	while (low <= high)
	{
		mid = low + F[k - 1] - 1;
		if (temp[mid] > key)
		{
			high = mid - 1;
			k = k - 1;//�ұ������ߣ��ұ���high��f(k-1)
		}
		else if(temp[mid]<key)
		{
			low = mid + 1;
			k = k - 2;//��������ߣ������low,��f��k-2��
		}
		else {
			if (mid <n)
				return mid; //�������˵��mid��Ϊ���ҵ���λ��
			else
			{
				return n-1;//��mid>=n��˵������չ����ֵ,����n-1 
			}
		}
	}
	delete[]temp;
	return 0;
}

int main()
{
	int a[13] = { 5, 15, 19, 20, 25, 31, 38, 41, 45, 49, 52, 55, 57 };
	int k, res = 0;
	printf("������Ҫ���ҵ�����:\n");
	scanf("%d", &k);
	res = fibSearch(a, k, 13);
	if (res != -1)
		printf("������ĵ�%d��λ���ҵ�Ԫ��\n", res + 1);
	else
		printf("δ���������ҵ�Ԫ��:\n");
	
	system("pause");
	return 0;
}

