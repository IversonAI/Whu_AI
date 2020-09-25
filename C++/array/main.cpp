#include <iostream>
#include<cstdlib>

//////////////
///循环链表表示///
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
		printf("%d x的地址%d\n", x->item,&(x->item));
		x->item = i;
		x->next = t;
		printf("%d x的地址%d\n", x->item, &(x->item));
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
// //循环链表表示
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
//	cout << "输入总数n的值：";
//	cin >> n;
//	cout << "输入起始报数人号码k的值：";
//	cin >> k;
//	cout << "输入数到m出列的m的值：";
//	cin >> m;
//
//
//	head = (Node*) new Node;
//	p = head;         //确定头结点用用p指向头结点
//
//	//为循环链表赋值
//	for (i = 1; i <= n - 1; i++)
//	{
//		p->data = i;
//		p->pNext = (Node*)new Node;//为下一个结点新建内存
//		p = p->pNext;
//	}
//
//	p->data = n;//最后一个结点单独处理
//	p->pNext = head;//指向头结点，形成循环链表
//	p = head;
//
//	while (p->data != (p->pNext)->data)//表示只剩下一个结点
//	{
//		while (p->data != k)//寻找编号为k的结点
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


