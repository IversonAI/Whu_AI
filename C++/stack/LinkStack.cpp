//#include "string.h"
//#include "ctype.h"      
//
//#include "stdio.h"    
//#include "stdlib.h"   
//#include "io.h"  
//#include "math.h"  
//#include "time.h"
//
//#define OK 1
//#define ERROR 0
//#define TRUE 1
//#define FALSE 0
//
//#define MAXSIZE 1000 /* �洢�ռ��ʼ������ */
//
//typedef int Status;           /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
//typedef char SElemType;        /* ElemType���͸���ʵ������������������Ϊchar */
//
//
//typedef struct StackNode
//{
//	SElemType data;
//	struct StackNode *next;
//}StackNode,*LinkStackPtr;
//
//typedef struct LinkStack
//{
//	LinkStackPtr top;
//	int count;
//}LinkStack;
//
//
////�ж��Ƿ�Ϊ��
//Status StackEmpty(LinkStack S)
//{
//	if (S.count == 0)
//		return TRUE;
//	else
//	{
//		return FALSE;
//	}
//}
////��ջ
//Status Push(LinkStack *S, SElemType e)
//{
//	LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
//	s->data = e;
//	s->next = S->top;//����ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ��
//	S->top = s;//���½���s��ֵ��ջ��ָ��
//	S->count++;
//	return OK;
//}
//
////��ջ
//Status Pop(LinkStack *S, SElemType *e)
//{
//	LinkStackPtr p;
//	if (StackEmpty(*S))
//		return ERROR;
//	*e = S->top->data;
//	p = S->top;
//	S->top = p->next;
//	free(p);
//	S->count--;
//	return OK;
//}
//
//Status visit(SElemType c)
//{
//	printf("%d ", c);
//	return OK;
//}
//
///*  ����һ����ջS */
//Status InitStack(LinkStack *S)
//{
//	S->top = (LinkStackPtr)malloc(sizeof(StackNode));
//	if (!S->top)
//		return ERROR;
//	S->top = NULL;
//	S->count = 0;
//	return OK;
//}
//
///* ��S��Ϊ��ջ */
//Status ClearStack(LinkStack *S)
//{
//	LinkStackPtr p, q;
//	p = S->top;
//	while (p)
//	{
//		q = p;
//		p = p->next;
//		free(q);
//	}
//	S->count = 0;
//	return OK;
//}
//
///* ����S��Ԫ�ظ�������ջ�ĳ��� */
//int StackLength(LinkStack S)
//{
//	return S.count;
//}
//
///* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
//Status GetTop(LinkStack S, SElemType *e)
//{
//	if (S.top == NULL)
//		return ERROR;
//	else
//		*e = S.top->data;
//	return OK;
//}
//
//Status StackTraverse(LinkStack S)
//{
//	LinkStackPtr p;
//	p = S.top;
//	while (p)
//	{
//		visit(p->data);
//		p = p->next;
//	}
//	printf("\n");
//	return OK;
//}
//
//int main()
//{
//	int j;
//	LinkStack s;
//	SElemType e;
//	if (InitStack(&s) == OK)
//		for (j = 1; j <= 10; j++)
//			Push(&s, j);
//	printf("ջ��Ԫ������Ϊ��");
//	StackTraverse(s);
//	Pop(&s, &e);
//	printf("������ջ��Ԫ�� e=%d\n", e);
//	printf("ջ�շ�%d(1:�� 0:��)\n", StackEmpty(s));
//	GetTop(s, &e);
//	printf("ջ��Ԫ�� e=%d ջ�ĳ���Ϊ%d\n", e, StackLength(s));
//	ClearStack(&s);
//	printf("���ջ��ջ�շ�%d(1:�� 0:��)\n", StackEmpty(s));
//	system("pause");
//	return 0;
//}