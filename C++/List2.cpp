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
////用e返回L中第i个数据元素的值
//Status GetElem(LinkList L, int i, ElemType *e)
//{
//	int j;
//	LinkList p;//声明一结点p
//	p = L->next;//让p指向链表L的第一个结点
//	j = 1;//j为计数器
//	while (p && j < i) //p不为空或者计数器j还没有等于i时，循环继续
//	{
//		p = p->next;//让p指向下一个结点
//		++j;
//	}
//	if (!p || j > i)
//		return ERROR;
//	*e = p->data;//取第i个元素的数据
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
////删除操作
//Status ListDelete(LinkList *L, int i, ElemType *e)
//{
//	int j;
//	LinkList p, q;
//	p = *L;
//	j = 1;
//	while (p->next && j < i)//遍历寻找第i个元素
//	{
//		p = p->next;
//		++j;
//	}
//	if (!(p->next) || j > i)
//		return ERROR;//第i个元素不存在
//	q = p->next;
//	p->next = q->next;//将q的后继赋值给p的后继
//	*e = q->data;//将q结点的数据给e
//	free(q);//让系统回收此结点，释放内存
//	return OK;
//}
//
////头插法
//void CreateListHead(LinkList *L, int n)
//{
//	int i;
//	LinkList p;
//	srand(time(0));//初始化随机数种子
//	*L = (LinkList)malloc(sizeof(Node));
//	(*L)->next = NULL;//先建立一个带头结点的单链表
//	for (i = 0; i < n; i++)
//	{
//		p = (LinkList)malloc(sizeof(Node));//生成新结点
//		p->data = rand() % 100 + 1;//随机生成100以内的数字
//		p->next = (*L)->next;
//		(*L)->next = p;//插入到表头
//	}
//}
//
////尾插法
//void CreateListTail(LinkList *L, int n)
//{
//	LinkList p, r;
//	int i;
//	srand(time(0));//初始化随机数种子
//	*L = (LinkList)malloc(sizeof(Node));//为整个线性表
//	r = *L;//r为指向尾部的结点
//	for (i = 0; i < n; i++)
//	{
//		p = (Node *)malloc(sizeof(Node));//生成新结点
//		p->data = rand() % 100 + 1;//随机生成100以内的数字
//		r->next = p;//将表尾终端结点的指针指向新结点
//		r = p;//将当前新结点定义为表尾终点结点
//	}
//	r->next = NULL;//表示当前链表结束
//}
//
////销毁链表
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
