//#include<iostream>
//#include<vector>
//
//
//using namespace std;
//
////ѭ��
//int biSearch(vector<int> &S, int const  &e, int low, int high)
//{
//	while ((low < high))//ÿ����������Ҫ�������жϣ���������֧
//	{
//		
//
//		int mid = (low + high) >> 1;//���е�Ϊ���
//
//		if (e < S[mid])//ǰ��β���
//			high = mid;
//		else if (S[mid] < e)//���μ�������
//		{
//			low = mid + 1;
//		}
//		else
//		{
//			return mid;//��mid������
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
//	printf("�±�Ϊ��%d", location);
//	system("pause");
//	return 0;
//}