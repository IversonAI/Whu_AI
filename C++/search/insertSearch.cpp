#include<iostream>
#include<vector>


using namespace std;


//说明：元素必须是有序的，如果是无序的则要先进行排序操作。
//复杂度分析：最坏情况下，关键词比较次数为log2(n+1)，且期望时间复杂度为O(log2n)；
//循环

int biSearch(vector<int> &S, int const  &e, int low, int high)
{
	while ((low < high))//每步迭代可能要做两次判断，有三个分支
	{

		//根据关键字在整个有序表中所处的位置，让mid值的变化更靠近关键字key，这样也就间接地减少了比较次数。
		int mid = low + (e - S[low]) / (S[high] - S[low])*(high - low);

		if (e < S[mid])//前半段查找
			high = mid;
		else if (S[mid] < e)//后半段继续查找
		{
			low = mid + 1;
		}
		else
		{
			return mid;//在mid处命中
		}
	}
	return -1;
}


int main() {

	vector<int> s;

	for (int i = 0; i < 10; i++)
	{
		s.push_back(i);
	}

	int location = biSearch(s, 6, 0, 9);
	printf("下标为：%d", location);
	system("pause");
	return 0;
}




