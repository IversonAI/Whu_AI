#include<iostream>
#include<vector>


using namespace std;


//˵����Ԫ�ر���������ģ�������������Ҫ�Ƚ������������
//���Ӷȷ����������£��ؼ��ʱȽϴ���Ϊlog2(n+1)��������ʱ�临�Ӷ�ΪO(log2n)��
//ѭ��

int biSearch(vector<int> &S, int const  &e, int low, int high)
{
	while ((low < high))//ÿ����������Ҫ�������жϣ���������֧
	{

		//���ݹؼ����������������������λ�ã���midֵ�ı仯�������ؼ���key������Ҳ�ͼ�ӵؼ����˱Ƚϴ�����
		int mid = low + (e - S[low]) / (S[high] - S[low])*(high - low);

		if (e < S[mid])//ǰ��β���
			high = mid;
		else if (S[mid] < e)//���μ�������
		{
			low = mid + 1;
		}
		else
		{
			return mid;//��mid������
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
	printf("�±�Ϊ��%d", location);
	system("pause");
	return 0;
}




