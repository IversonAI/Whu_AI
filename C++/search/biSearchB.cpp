#include<iostream>
#include<vector>


using namespace std;


//˵����Ԫ�ر���������ģ�������������Ҫ�Ƚ������������
//���Ӷȷ����������£��ؼ��ʱȽϴ���Ϊlog2(n+1)��������ʱ�临�Ӷ�ΪO(log2n)��
//ѭ��
int biSearch(vector<int> &S, int const  &e, int low, int high)
{
	while (high-low>1)//�����м�һλ
	{
		int mid = (low + high) >> 1;//���е�Ϊ���
		(e < S[mid]) ? high = mid : low = mid;
	}
	return e<S[low]?low-1:low;//�����±���������
}


int main() {

	vector<int> s;

	for (int i = 0; i < 10; i++)
	{
		s.push_back(i*i);
	}

	int location = biSearch(s, 25, 0, 9);
	printf("�±�Ϊ��%d", location);
	system("pause");
	return 0;
}


