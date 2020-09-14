//#include<iostream>
//
//#include "stdio.h"    
//
//#include "stdlib.h"   
//#include "io.h"  
//#include "math.h"  
//#include "time.h"
//
//#define MAXSIZE 20
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//
//using namespace std;
//typedef int ElemType;
//typedef int Status;
//
//typedef struct Node
//{
//	ElemType data;
//    struct Node *next;
//}Node;
//
//typedef struct Node *LinkList;
//
////��e����L�е�i������Ԫ�ص�ֵ
//Status GetElem(LinkList L, int i, ElemType *e)
//{
//	int j;
//	LinkList p;//����һ���p
//	p = L->next;//��pָ������L�ĵ�һ�����
//	j = 1;//jΪ������
//	while (p && j < i) //p��Ϊ�ջ��߼�����j��û�е���iʱ��ѭ������
//	{
//		p = p->next;//��pָ����һ�����
//		++j;
//	}
//	if (!p || j > i)
//		return ERROR;
//	*e = p->data;//ȡ��i��Ԫ�ص�����
//	return OK;
//}
//
//
//Status ListInsert(LinkList *L, int i, ElemType e)
//{
//	int j;
//	LinkList p, s;
//	p = *L;
//	j = 1;
//	while (p&&j < i)
//	{
//		p = p->next;
//		++j;
//	}
//	if (!p || j > i)
//		return OK;
//	s = (LinkList)malloc(sizeof(Node));
//	s->data = e;
//	s->next = p->next;
//	p->next = s;
//
//	return OK;
//
//}
//
////ɾ������
//Status ListDelete(LinkList *L, int i, ElemType *e)
//{
//	int j;
//	LinkList p, q;
//	p = *L;
//	j = 1;
//	while (p->next && j < i)//����Ѱ�ҵ�i��Ԫ��
//	{
//		p = p->next;
//		++j;
//	}
//	if (!(p->next) || j > i)
//		return ERROR;//��i��Ԫ�ز�����
//	q = p->next;
//	p->next = q->next;//��q�ĺ�̸�ֵ��p�ĺ��
//	*e = q->data;//��q�������ݸ�e
//	free(q);//��ϵͳ���մ˽�㣬�ͷ��ڴ�
//	return OK;
//}
//
////ͷ�巨
//void CreateListHead(LinkList *L, int n)
//{
//	int i;
//	LinkList p;
//	srand(time(0));//��ʼ�����������
//	*L = (LinkList)malloc(sizeof(Node));
//	(*L)->next = NULL;//�Ƚ���һ����ͷ���ĵ�����
//	for (i = 0; i < n; i++)
//	{
//		p = (LinkList)malloc(sizeof(Node));//�����½��
//		p->data = rand() % 100 + 1;//�������100���ڵ�����
//		p->next = (*L)->next;
//		(*L)->next = p;//���뵽��ͷ
//	}
//}
//
////β�巨
//void CreateListTail(LinkList *L, int n)
//{
//	LinkList p, r;
//	int i;
//	srand(time(0));//��ʼ�����������
//	*L = (LinkList)malloc(sizeof(Node));//Ϊ�������Ա�
//	r = *L;//rΪָ��β���Ľ��
//	for (i = 0; i < n; i++)
//	{
//		p = (Node *)malloc(sizeof(Node));//�����½��
//		p->data = rand() % 100 + 1;//�������100���ڵ�����
//		r->next = p;//����β�ն˽���ָ��ָ���½��
//		r = p;//����ǰ�½�㶨��Ϊ��β�յ���
//	}
//	r->next = NULL;//��ʾ��ǰ�������
//}
//
////��������
//Status ClearList(LinkList *L )
//{
//	LinkList p, q;
//	p = (*L)->next;
//	while (p)
//	{
//		q = p->next;
//		free(p);
//		p = q;
//	}
//	(*L)->next = NULL;
//	return OK;
//}
