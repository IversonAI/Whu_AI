#include<iostream>
#include <vector>
#include <stack>

using namespace std;



// �ڲ�����ݹ�
// params:
//      length:     ��ջԪ�ظ���
//      index:      ��ǰԪ���±�
//      inStack:    ��ǰ��ջ����
//      outList:    ��ǰ��ջ����
//      outputs:    ��������г�ջ���н�����±꣩
void intShufflingRecursion(int length, int index, stack<int> &inStack,
	vector<int> &outList, vector<vector<int>> &outputs)
{
	//���ȫ��Ԫ�ض���ջ
	if (outList.size() == length)
	{
		outputs.push_back(outList);//����վԪ��д����outputs
		return;
	}

	//�����ǰԪ���±�С����Ԫ�ظ�������ʼ��ջ�ݹ�
	if (index < length)
	{
		inStack.push(index);//��ջ��ǰ�±�
		intShufflingRecursion(length, index + 1, inStack, outList, outputs);
		inStack.pop();//��ջջ��Ԫ��
	}

	//���ջԪ�ظ�������0����ʼ��ջ�ݹ�
	if (inStack.size() > 0)
	{
		int top = inStack.top();//��ȡջ��Ԫ���±�
		inStack.pop();//��ջջ��Ԫ��
		outList.push_back(top);//����ջԪ�ؼӵ���ջ������

		//�˴��ݹ飬���ж�Ԫ�س�ջ���Ƿ���Ҫ��ջ��ջ�������Ƿ���Ԫ��û�����ջ��
		intShufflingRecursion(length, index, inStack, outList, outputs);
		inStack.push(top);//������ջԭջ��Ԫ��
		outList.pop_back();//��ԭջ��Ԫ���Ƴ�
	}
}

// �������г�ջ���У��±��0���㣩
// params:
//      length:     ��ջԪ�ظ���
//      outputs:    ������г�ջ���н�����±꣩
void Shuffling(int length, vector<vector<int>> &outputs)
{
	if (length <= 0)
		return;
	stack<int> inStack;
	vector<int> outList;
	intShufflingRecursion(length, 0, inStack, outList, outputs);
}

int main() {
	int length = -1;
	while (true)
	{
		cout << "ջ��ϴ��������ջ�ĳ��ȣ�";
		while (!(cin >> length) || length < 0)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "���벻�Ϸ�������������ջ���ȣ�";
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		vector<vector<int>> outputs;//�������г�ջ���
		Shuffling(length, outputs);//�����ջ����

		//��ӡ���г�ջ˳��
		for (int i = 0; i < outputs.size(); i++)
		{
			cout << i << ":";
			for (int j = 0; j < outputs[i].size(); j++)
			{
				//��ջ����±��Ǵ�0��ʼ��Ԫ���Ǵ�1��ʼ
				//���ԭʼ���ݲ���1-n,�����滻��ԭ��ջ����[outputs[i][j]]
				cout << (outputs[i][j] + 1) << "	";
			}
			cout << endl;
		}
		cout << "һ����" << outputs.size() << "�ֳ�ջ���С�" << endl;
		cout << endl;
	 }
	system("pause");
	return 0;
}