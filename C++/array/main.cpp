#include <iostream>
#include<cstdlib>

//////////////
///ѭ�������ʾ///
/////////////
typedef struct node* link;

struct node
{
	int item;
	link next;
};


int main()
{
	int i, N = 9, M = 5;
	link t = (link)malloc(sizeof(*t)), x = t;
	t->item = 1;
	t->next = t;
	for (i = 2; i <= N; i++)
	{
		x = (x->next = (link)malloc(sizeof(*x)));
		printf("%d x�ĵ�ַ%d\n", x->item,&(x->item));
		x->item = i;
		x->next = t;
		printf("%d x�ĵ�ַ%d\n", x->item, &(x->item));
	}
	while (x!=x->next)
	{
		for (i = 1; i < M; i++)
			x = x->next;
		x->next = x->next->next;
		//N--;
	}
	printf("%d\n", x->item);
	system("pause");
}


//#include<iostream>
//
//using namespace std;
// //ѭ�������ʾ
//struct Node
//{
//	int data;
//	Node *pNext;
//};
//
//void main()
//{
//	int n, k, m, i;
//	Node *p, *q, *head;
//	cout << "��������n��ֵ��";
//	cin >> n;
//	cout << "������ʼ�����˺���k��ֵ��";
//	cin >> k;
//	cout << "��������m���е�m��ֵ��";
//	cin >> m;
//
//
//	head = (Node*) new Node;
//	p = head;         //ȷ��ͷ�������pָ��ͷ���
//
//	//Ϊѭ������ֵ
//	for (i = 1; i <= n - 1; i++)
//	{
//		p->data = i;
//		p->pNext = (Node*)new Node;//Ϊ��һ������½��ڴ�
//		p = p->pNext;
//	}
//
//	p->data = n;//���һ����㵥������
//	p->pNext = head;//ָ��ͷ��㣬�γ�ѭ������
//	p = head;
//
//	while (p->data != (p->pNext)->data)//��ʾֻʣ��һ�����
//	{
//		while (p->data != k)//Ѱ�ұ��Ϊk�Ľ��
//			p = p->pNext;
//		if (m == 1)
//		{
//			for (i = i; i <= n; i++)
//			{
//				cout << p->data << "\t";
//				p = p->pNext;
//			}
//			cout << "\n";
//			return;
//		}
//		else
//		{
//			for (i = 1; i < m - 1; i++)
//			{
//				p = p->pNext;
//			}
//			q = p->pNext;
//			cout << q->data << "\t";
//			k = (q->pNext)->data;
//			p->pNext = q->pNext;
//		}
//		cout << p->data << "\n";
//	}
//
//	system("pause");
//
//}


