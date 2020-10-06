////////////////////////////////////
////存、读数据的操作时间复杂度为O（1）；
////
////插入 删除的操作时间复杂度为O（n）；
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
///* 初始化顺序线性表 */
//Status InitList(SqList *L)
//{
//	L->length = 0;
//	return OK;
//}
//
///* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
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
///* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
//Status ClearList(SqList *L)
//{
//	L->length = 0;
//	return OK;
//}
//
///* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
//Status ListLength(SqList L)
//{
//	return L.length;
//}
//
///* 初始条件：顺序线性表L已存在，1≤i≤ListLength(L) */
///* 操作结果：用e返回L中第i个数据元素的值,注意i是指位置，第1个位置的数组是从0开始 */
//Status GetElem(SqList L, int i, ElemType *e)
//{
//	if (L.length == 0 || i<1 || i>L.length)
//		return ERROR;
//	*e = L.data[i - 1];
//	return OK;
//}
//
///* 初始条件：顺序线性表L已存在 */
///* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
///* 若这样的数据元素不存在，则返回值为0 */
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
//	if (L->length == MAXSIZE)/*顺序线性表已满*/
//		return ERROR;
//	if (i<1 || i>L->length + 1)/*当i不在范围内*/
//		return ERROR;
//	if (i <= L->length)
//	{
//		for (k = L->length - 1; k >= i - 1; k--)/*将要插入位置后的所有数据元素往后移动一位*/
//			L->data[k + 1] = L->data[k];
//	}
//	L->data[i - 1] = e;/*插入新元素*/
//	L->length++;
//	return OK;
//}
//
//Status ListDelete(SqList *L, int i, ElemType *e)
//{
//	int k;
//	if (L->length == 0)/*顺序线性表为空*/
//		return ERROR;
//	if (i<1 || i>L->length )/*当i不在范围内*/
//		return ERROR;
//
//	*e = L->data[i - 1];
//
//	if (i < L->length)/*如果不是最后位置*/
//	{
//		for (k = i; k < L->length;  k++)/*将要插入位置后的所有数据元素往前移动一位*/
//			L->data[k -1] = L->data[k];
//	}
//	
//	L->length--;
//	return OK;
//}
//
////遍历输出
//Status ListTraverse(SqList L)
//{
//	int i;
//	for (i = 0; i < L.length; i++)
//		visit(L.data[i]);
//	printf("\n");
//	return OK;
//}
//
////将b中找出a里没有的并插入a中
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
//	printf("初始化后：L.length=%d", L.length);
//
//	for (j = 1; j < 5; j++)
//		i = ListInsert(&L, 1, j);
//	printf("在L的表头依次插入1~5后：L.data=");
//	ListTraverse(L);
//
//	printf("L.length=%d \n", L.length);
//	i = ListEmpty(L);
//	printf("L是否空：i=%d(1:是 0:否)\n", i);
//
//	i = ClearList(&L);
//	printf("清空L后：L.length=%d\n", L.length);
//	i = ListEmpty(L);
//	printf("L是否空：i=%d(1:是 0:否)\n", i);
//
//	for (j = 1; j <= 10; j++)
//		ListInsert(&L, j, j);
//	printf("在L的表尾依次插入1～10后：L.data=");
//	ListTraverse(L);
//
//	printf("L.length=%d \n", L.length);
//
//	ListInsert(&L, 1, 0);
//	printf("在L的表头插入0后：L.data=");
//	ListTraverse(L);
//	printf("L.length=%d \n", L.length);
//
//
//	GetElem(L, 5, &e);
//	printf("第5个元素的值为：%d\n", e);
//	for (j = 3; j <= 4; j++)
//	{
//		k = LocateElem(L, j);
//		if (k)
//			printf("第%d个元素的值为%d\n", k, j);
//		else
//			printf("没有值为%d的元素\n", j);
//	}
//
//
//	k = ListLength(L); /* k为表长 */
//	for (j = k + 1; j >= k; j--)
//	{
//		i = ListDelete(&L, j, &e); /* 删除第j个数据 */
//		if (i == ERROR)
//			printf("删除第%d个数据失败\n", j);
//		else
//			printf("删除第%d个的元素值为：%d\n", j, e);
//	}
//	printf("依次输出L的元素：");
//	ListTraverse(L);
//
//	j = 5;
//	ListDelete(&L, j, &e); /* 删除第5个数据 */
//	printf("删除第%d个的元素值为：%d\n", j, e);
//
//	printf("依次输出L的元素：");
//	ListTraverse(L);
//
//	//构造一个有10个数的Lb
//	i = InitList(&Lb);
//	for (j = 6; j <= 15; j++)
//		i = ListInsert(&Lb, 1, j);
//
//	insertAfromB(&L, Lb);
//
//	printf("依次输出合并了Lb的L的元素：");
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
