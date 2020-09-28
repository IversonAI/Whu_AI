//#include<iostream>
//#include<vector>
//
//
//using namespace std;
//
////循环
//int biSearch(vector<int> &S, int const  &e, int low, int high)
//{
//	while ((low < high))//每步迭代可能要做两次判断，有三个分支
//	{
//		
//
//		int mid = (low + high) >> 1;//以中点为轴点
//
//		if (e < S[mid])//前半段查找
//			high = mid;
//		else if (S[mid] < e)//后半段继续查找
//		{
//			low = mid + 1;
//		}
//		else
//		{
//			return mid;//在mid处命中
//		}
//	}
//	return -1;
//}
//
//
//int main() {
//
//	vector<int> s;
//
//	for (int i = 0; i < 10; i++)
//	{
//		s.push_back(i);
//	}
//	
//	int location=biSearch(s, 6, 0, 9);
//	printf("下标为：%d", location);
//	system("pause");
//	return 0;
//}