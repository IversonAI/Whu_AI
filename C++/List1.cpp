////////////////////////////////////
////�桢�����ݵĲ���ʱ�临�Ӷ�ΪO��1����
////
////���� ɾ���Ĳ���ʱ�临�Ӷ�ΪO��n����
////
////////////////////////////////////
//#include <iostream>
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
//typedef struct
//{
//	ElemType data[MAXSIZE];
//	int length;
//}SqList;
//
//
//Status visit(ElemType c)
//{
//	printf("%d ", c);
//	return OK;
//}
//
///* ��ʼ��˳�����Ա� */
//Status InitList(SqList *L)
//{
//	L->length = 0;
//	return OK;
//}
//
///* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
//Status ListEmpty(SqList L)
//{
//	if (L.data == 0)
//		return TRUE;
//	else
//	{
//		return FALSE;
//	}
//}
//
///* ��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ� */
//Status ClearList(SqList *L)
//{
//	L->length = 0;
//	return OK;
//}
//
///* ��ʼ������˳�����Ա�L�Ѵ��ڡ��������������L������Ԫ�ظ��� */
//Status ListLength(SqList L)
//{
//	return L.length;
//}
//
///* ��ʼ������˳�����Ա�L�Ѵ��ڣ�1��i��ListLength(L) */
///* �����������e����L�е�i������Ԫ�ص�ֵ,ע��i��ָλ�ã���1��λ�õ������Ǵ�0��ʼ */
//Status GetElem(SqList L, int i, ElemType *e)
//{
//	if (L.length == 0 || i<1 || i>L.length)
//		return ERROR;
//	*e = L.data[i - 1];
//	return OK;
//}
//
///* ��ʼ������˳�����Ա�L�Ѵ��� */
///* �������������L�е�1����e�����ϵ������Ԫ�ص�λ�� */
///* ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
//Status LocateElem(SqList L, ElemType e)
//{
//	int i;
//	if (L.length == 0 )
//		return ERROR;
//	for (i = 0; i < L.length; i++)
//	{
//		if (L.data[i] == e)
//			break;
//	}
//	return i + 1;
//}
//Status ListInsert(SqList *L, int i, ElemType e)
//{
//	int k;
//	if (L->length == MAXSIZE)/*˳�����Ա�����*/
//		return ERROR;
//	if (i<1 || i>L->length + 1)/*��i���ڷ�Χ��*/
//		return ERROR;
//	if (i <= L->length)
//	{
//		for (k = L->length - 1; k >= i - 1; k--)/*��Ҫ����λ�ú����������Ԫ�������ƶ�һλ*/
//			L->data[k + 1] = L->data[k];
//	}
//	L->data[i - 1] = e;/*������Ԫ��*/
//	L->length++;
//	return OK;
//}
//
//Status ListDelete(SqList *L, int i, ElemType *e)
//{
//	int k;
//	if (L->length == 0)/*˳�����Ա�Ϊ��*/
//		return ERROR;
//	if (i<1 || i>L->length )/*��i���ڷ�Χ��*/
//		return ERROR;
//
//	*e = L->data[i - 1];
//
//	if (i < L->length)/*����������λ��*/
//	{
//		for (k = i; k < L->length;  k++)/*��Ҫ����λ�ú����������Ԫ����ǰ�ƶ�һλ*/
//			L->data[k -1] = L->data[k];
//	}
//	
//	L->length--;
//	return OK;
//}
//
////�������
//Status ListTraverse(SqList L)
//{
//	int i;
//	for (i = 0; i < L.length; i++)
//		visit(L.data[i]);
//	printf("\n");
//	return OK;
//}
//
////��b���ҳ�a��û�еĲ�����a��
//
//void insertAfromB(SqList *La, SqList Lb)
//{
//	int La_len, Lb_len, i;
//	ElemType e;
//	La_len = ListLength(*La);
//	Lb_len = ListLength(Lb);
//	for (i = 1; i <= Lb_len; i++)
//	{
//		GetElem(Lb, i, &e);
//		if (!LocateElem(*La, e))
//			ListInsert(La, ++La_len, e);
//	}
//}
//
//int main() {
//
//	SqList L;
//	SqList Lb;
//
//	ElemType e;
//	Status i;
//	int j, k;
//
//	i = InitList(&L);
//
//	printf("��ʼ����L.length=%d", L.length);
//
//	for (j = 1; j < 5; j++)
//		i = ListInsert(&L, 1, j);
//	printf("��L�ı�ͷ���β���1~5��L.data=");
//	ListTraverse(L);
//
//	printf("L.length=%d \n", L.length);
//	i = ListEmpty(L);
//	printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);
//
//	i = ClearList(&L);
//	printf("���L��L.length=%d\n", L.length);
//	i = ListEmpty(L);
//	printf("L�Ƿ�գ�i=%d(1:�� 0:��)\n", i);
//
//	for (j = 1; j <= 10; j++)
//		ListInsert(&L, j, j);
//	printf("��L�ı�β���β���1��10��L.data=");
//	ListTraverse(L);
//
//	printf("L.length=%d \n", L.length);
//
//	ListInsert(&L, 1, 0);
//	printf("��L�ı�ͷ����0��L.data=");
//	ListTraverse(L);
//	printf("L.length=%d \n", L.length);
//
//
//	GetElem(L, 5, &e);
//	printf("��5��Ԫ�ص�ֵΪ��%d\n", e);
//	for (j = 3; j <= 4; j++)
//	{
//		k = LocateElem(L, j);
//		if (k)
//			printf("��%d��Ԫ�ص�ֵΪ%d\n", k, j);
//		else
//			printf("û��ֵΪ%d��Ԫ��\n", j);
//	}
//
//
//	k = ListLength(L); /* kΪ�� */
//	for (j = k + 1; j >= k; j--)
//	{
//		i = ListDelete(&L, j, &e); /* ɾ����j������ */
//		if (i == ERROR)
//			printf("ɾ����%d������ʧ��\n", j);
//		else
//			printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);
//	}
//	printf("�������L��Ԫ�أ�");
//	ListTraverse(L);
//
//	j = 5;
//	ListDelete(&L, j, &e); /* ɾ����5������ */
//	printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);
//
//	printf("�������L��Ԫ�أ�");
//	ListTraverse(L);
//
//	//����һ����10������Lb
//	i = InitList(&Lb);
//	for (j = 6; j <= 15; j++)
//		i = ListInsert(&Lb, 1, j);
//
//	insertAfromB(&L, Lb);
//
//	printf("��������ϲ���Lb��L��Ԫ�أ�");
//	ListTraverse(L);
//
//	return 0;
//
//
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
