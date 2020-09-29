// BSTree.cpp : �������̨Ӧ�ó������ڵ㡣

#include <iostream>
#include "biTree.h"
using namespace std;
int main()
{
	BSTree<int> s;
	int a;
	cout << "���������������Թ�������������" << endl;
	while (cin >> a)
		s.insert(a);
	cin.clear();

	cout << "ǰ��������������:" << endl;
	s.postOrder();
	cout << endl;


	cout << "����������������:" << endl;
	s.inOrder();
	cout << endl;


	cout << "����������������:" << endl;
	s.postOrder();
	cout << endl;


	cout << "��ӡ���������" << endl;
	s.print();

	cout << "������Ҫ���ҵ�����" << endl;

	while (cin >> a)
	{
		BSTNode<int>* findnode = s.search(a);
		if (!findnode)
		{
			cout << "����ʧ��" << endl;
			s.insert(a);
			cout << "�Ѿ���" << a << "������������,���ڶ��������Ϊ��" << endl;
			s.inOrder();
			cout << endl;
		}
		else
		{
			cout << findnode->_key << "���ҳɹ�" << endl;
		}
	}
	cin.clear();

	cout << "���������Բ�����ǰ���ڵ�" << endl;
	BSTNode<int>* findPreNode = new BSTNode<int>(1, NULL, NULL, NULL);
	while (cin >> findPreNode->_key)
	{
		BSTNode<int>* preNode;
		if ((preNode = s.predecessor(findPreNode)) != NULL)
		{
			cout << "��ǰ�����Ϊ��";
			cout << preNode->_key << endl;
		}
		else
			cout << "û��ǰ�����" << endl;

		if ((preNode = s.sucessor(findPreNode)) != NULL)
		{
			cout << "���̽��Ϊ��";
			cout << preNode->_key << endl;
		}
		else
			cout << "û�к�̽��" << endl;
	}

	cin.clear();
	cout << "������Ҫɾ���Ľ�㣺" << endl;
	while (cin >> a)
	{

		s.remove(a);
		cout << "ɾ����Ķ�����������" << endl;
		s.inOrder();
	}


	BSTNode<int>* maxNode = s.minimumNode();
	if (maxNode)
		cout << "��С�Ľڵ�Ϊ��" << maxNode->_key << endl;

	BSTNode<int>* minNode = s.maximumNode();
	if (minNode)
		cout << "���Ľڵ�Ϊ��" << minNode->_key << endl;

	cout << "���ٶ�����" << endl;
	s.destory();
	s.inOrder();

	system("pause");

	return 0;
}