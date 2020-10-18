#include "string.h"
#include "ctype.h"      

#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 1000 /* 存储空间初始分配量 */

typedef int Status;           /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int SElemType;        /* ElemType类型根据实际情况而定，这里假设为char */

typedef struct {
	SElemType data[MAXSIZE];
	int top;
}SqStack;

//进栈
Status Push(SqStack *S, SElemType e)
{
	if (S->top == MAXSIZE - 1)//栈满
		return ERROR;
	S->top++;//栈顶指针加一
	S->data[S->top] = e;//将新插入元素赋值给栈顶空间
	return OK;
}
//出栈
Status Pop(SqStack *S, SElemType *e)
{
	if (S->top == -1)//栈空
		return ERROR;
	*e = S->data[S->top];//将要删除的栈顶元素赋值给e
	S->top--;//栈顶指针减一
	return OK;
}

Status visit(SElemType c)
{
	printf("%d", c);
	return OK;
}
//初始化栈
Status InitStack(SqStack *S)
{
	S->top = -1;
	return OK;
}

/* 把S置为空栈 */
Status ClearStack(SqStack *S)
{
	S->top = -1;
	return OK;
}

//判断是否空栈
Status StackEmpty(SqStack S)
{
	if (S.top == -1)
		return TRUE;
	else
	{
		return FALSE;
	}
}
//栈长
int StackLength(SqStack S)
{
	return S.top + 1;
}
//返回栈顶
Status GetTop(SqStack S, SElemType *e)
{
	if (S.top == -1)
		return ERROR;
	else
		*e = S.data[S.top];
	return OK;
}
//遍历
Status StackTraverse(SqStack S)
{
	int i;
	i = 0;
	while (i<=S.top)
	{
		visit(S.data[i++]);
	}
	printf("\n");
	return OK;

}

int main()
{
	int j;
	SqStack s;
	SElemType e;
	if (InitStack(&s) == OK)
		for (j = 1; j <= 10; j++)
			Push(&s, j);
	printf("栈中元素依次为：");
	StackTraverse(s);
	Pop(&s, &e);
	printf("弹出的栈顶元素 e=%d\n", e);
	printf("栈空否：%d(1:空 0:否)\n", StackEmpty(s));
	GetTop(s, &e);
	printf("栈顶元素 e=%d 栈的长度为%d\n", e, StackLength(s));
	ClearStack(&s);
	printf("清空栈后，栈空否：%d(1:空 0:否)\n", StackEmpty(s));

	system("pause");
	return 0;
}


