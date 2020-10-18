#include "string.h"
#include "ctype.h"      

#include "stdio.h"    
#include "stdlib.h"   
#include "io.h"  
#include "math.h"  
#include "time.h"

#define ok 1
#define error 0
#define true 1
#define false 0

#define maxsize 1000 /* �洢�ռ��ʼ������ */

typedef int status;           /* status�Ǻ���������,��ֵ�Ǻ������״̬���룬��ok�� */
typedef int selemtype;        /* elemtype���͸���ʵ������������������Ϊchar */

typedef struct
{
	selemtype data[maxsize];
	int top1;
	int top2;
}sqdoublestack;

//��ջ
status push(sqdoublestack *s, selemtype e, int stacknumber)
{
	if (s->top1 + 1 == s->top2)//ջ��
		return error;
	if (stacknumber == 1)//��ջ1
		s->data[++s->top1 = e];//����top1+1�������Ԫ�ظ�ֵ
	else if (stacknumber == 2)//��ջ2
		s->data[--s->top2 = e];//����top2-1�������Ԫ�ظ�ֵ
	return ok;
}

//��ջ
status pop(sqdoublestack *s, selemtype *e, int stacknumber)
{
	if (stacknumber == 1)
	{
		if (s->top1 == -1)
			return error;
		*e = s->data[s->top1--];
	}
	else if(stacknumber==2)
	{
		if (s->top2==maxsize)
		{
			return error;
		}
		*e = s->data[s->top2++];
	}
	return ok;
}