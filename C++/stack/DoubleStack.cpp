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

#define maxsize 1000 /* 存储空间初始分配量 */

typedef int status;           /* status是函数的类型,其值是函数结果状态代码，如ok等 */
typedef int selemtype;        /* elemtype类型根据实际情况而定，这里假设为char */

typedef struct
{
	selemtype data[maxsize];
	int top1;
	int top2;
}sqdoublestack;

//进栈
status push(sqdoublestack *s, selemtype e, int stacknumber)
{
	if (s->top1 + 1 == s->top2)//栈满
		return error;
	if (stacknumber == 1)//进栈1
		s->data[++s->top1 = e];//则先top1+1后给数组元素赋值
	else if (stacknumber == 2)//进栈2
		s->data[--s->top2 = e];//则先top2-1后给数组元素赋值
	return ok;
}

//出栈
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