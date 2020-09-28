#include<iostream>
using namespace std;
const int max_size = 12;
//复杂度分析：最坏情况下，时间复杂度为O(log2n)，且其期望复杂度也为O(log2n)。

//斐波那契数列
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

//查找
//斐波那契查找与折半查找很相似，他是根据斐波那契序列的特点对有序表进行分割的。他要求开始表中记录的个数为某个斐波那契数小1，及n = F(k) - 1;
//开始将k值与第F(k - 1)位置的记录进行比较(及mid = low + F(k - 1) - 1), 比较结果也分为三种
//1）相等，mid位置的元素即为所求
//2） > ，low = mid + 1, k -= 2;
//说明：low = mid + 1说明待查找的元素在[mid + 1, high]范围内，k -= 2 说明范围[mid + 1, high]内的元素个数为n - (F(k - 1)) = Fk - 1 - F(k - 1) = Fk - F(k - 1) - 1 = F(k - 2) - 1个，所以可以递归的应用斐波那契查找。
//3） < ，high = mid - 1, k -= 1。
//	说明：low = mid + 1说明待查找的元素在[low, mid - 1]范围内，k -= 1 说明范围[low, mid - 1]内的元素个数为F(k - 1) - 1个，所以可以递归 的应用斐波那契查找。
//

int fibSearch(int *a, int key, int n)
{
	int i, low = 0, high = n - 1;
	int mid = 0;
	int k = 0;
	int F[max_size];
	fib(F);
	while (n > F[k] - 1)
		++k;//进入循环后得到n>F（k）-1的k后再加一从而此时F（k）一定大于n  
	
	int  * temp;//将数组a扩展到F[k]-1的长度  
	temp = new int[F[k] - 1];
	memcpy(temp, a, n * sizeof(int));
	for (i = n; i < F[k] - 1; i++)//因此需要对所给数组进行扩容
		temp[i] = a[n-1];//将最大值重复往后填充


	//开始判断
	while (low <= high)
	{
		mid = low + F[k - 1] - 1;
		if (temp[mid] > key)
		{
			high = mid - 1;
			k = k - 1;//右边往左走，右边是high是f(k-1)
		}
		else if(temp[mid]<key)
		{
			low = mid + 1;
			k = k - 2;//左边往右走，左边是low,是f（k-2）
		}
		else {
			if (mid <n)
				return mid; //若相等则说明mid即为查找到的位置
			else
			{
				return n-1;//若mid>=n则说明是扩展的数值,返回n-1 
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
	printf("请输入要查找的数字:\n");
	scanf("%d", &k);
	res = fibSearch(a, k, 13);
	if (res != -1)
		printf("在数组的第%d个位置找到元素\n", res + 1);
	else
		printf("未在数组中找到元素:\n");
	
	system("pause");
	return 0;
}

