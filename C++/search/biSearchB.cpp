#include<iostream>
#include<vector>


using namespace std;


//说明：元素必须是有序的，如果是无序的则要先进行排序操作。
//复杂度分析：最坏情况下，关键词比较次数为log2(n+1)，且期望时间复杂度为O(log2n)；
//循环
int biSearch(vector<int> &S, int const  &e, int low, int high)
{
	while (high-low>1)//留出中间一位
	{
		int mid = (low + high) >> 1;//以中点为轴点
		(e < S[mid]) ? high = mid : low = mid;
	}
	return e<S[low]?low-1:low;//分清下标数！！！
}


int main() {

	vector<int> s;

	for (int i = 0; i < 10; i++)
	{
		s.push_back(i*i);
	}

	int location = biSearch(s, 25, 0, 9);
	printf("下标为：%d", location);
	system("pause");
	return 0;
}


