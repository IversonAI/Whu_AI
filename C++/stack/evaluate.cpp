
#include <iostream>
#include <cmath>
#include <stack>

using namespace std;



#define N_OPTR 9

bool paren(const char exp[], int lo, int hi);//括号匹配
float evaluate(char* s);//表达式求值
float calcu(float popnd);//符号计算
float calcu(float op1, char op, float op2);
char orderBetween(char s1, char s2);//优先级判断
void readNum(char*& p, stack<float>& stk);//读入
// void append( char *&rpn, float opnd);//连接
// void append( char *&rpn, char optr);


//优先级表
typedef enum {   //通过枚举给每一个运算符一个编号
	ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE
} Operator;
const char pri[N_OPTR][N_OPTR] =          //运算符优先级表
{
	/*              |-------------------- 当 前 运 算 符 --------------------| */
	/*              +      -      *      /      ^      !      (      )      \0 */
	/* --  + */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
	/* |   - */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
	/* 栈  * */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
	/* 顶  / */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
	/* 运  ^ */    '>',   '>',   '>',   '>',   '>',   '<',   '<',   '>',   '>',
	/* 算  ! */    '>',   '>',   '>',   '>',   '>',   '>',   ' ',   '>',   '>',
	/* 符  ( */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   '=',   ' ',
	/* |   ) */    ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',
	/* -- \0 */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   ' ',   '='

};

//运算符转换为符号标志
Operator convert(char s) //返回枚举类型
{
	switch (s)
	{
	case '+': return ADD;
	case '-': return SUB;
	case '*': return MUL;
	case '/': return DIV;
	case '^': return POW;
	case '!': return FAC;
	case '(': return L_P;
	case ')': return R_P;
	case '\0': return EOE;
	default: exit(-1);
	}
}

int main() {
	
	//测试表达式求值
	char s[] = "(1+3)*2^3";
	//char *RPN ;
	cout << evaluate(s);
	system("pause");

}

//进制转换_十进制正整数n到base进制的转换
void convert(stack<char>& S, __int64 n, int base) {
	static char digit[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	if (0 < n) {
		S.push(digit[n % base]);
		convert(S, n / base, base);
	}
}
//表达式求值
/*Windows DOS运行及结果：
* C:\Users\DingYandong>set /a ((0+(1+23)/4*5*67-8+9))
* 2011
*/

//对表达式S求值，转换为逆波兰表达式
float evaluate(char* s)//
{
	stack<float> opnd;//运算数栈
	stack<float> optr;//运算符栈
	optr.push('\0'); //这个‘/0’与字符串末尾‘/0’呼应
	while (!optr.empty())
	{
		if (isdigit(*s))
		{
			readNum(s, opnd); //append(RPN, opnd.top());
		}
		else
		{
			switch (orderBetween(optr.top(), *s)) //不同优先级处理
			{
			case '<':
				optr.push(*s); s++;
				break;
			case '>':
			{
				char op = optr.top();
				//append( RPN, op);
				optr.pop();
				if (op == '!')
				{
					float popnd = opnd.top();
					opnd.pop();
					opnd.push(calcu(popnd));
				}
				else
				{
					float popnd2 = opnd.top();
					opnd.pop();
					float popnd1 = opnd.top();
					opnd.pop();
					opnd.push(calcu(popnd1, op, popnd2));
				}
			} break;
			case '=':

				optr.pop(); s++;
				break;
			default: exit(-1);
			}
		}
	}
	return opnd.top();

}
//运算函数(1)_一元运算
float calcu(float popnd) {
	if (popnd == 1) return 1;
	return calcu(popnd) * calcu(popnd - 1);
}
//运算函数(2)_二元运算
float calcu(float op1, char op, float op2) {
	switch (op) {
	case '+': return (op1 + op2);  break;
	case '-': return (op1 - op2); break;
	case '*': return (op1 * op2); break;
	case '/': return (op1 / op2); break;
	case '^': return (pow(op1, op2)); break;
	default: exit(-1); break; //表达式错误，直接返回异常
	}

}

//优先级比较
char orderBetween(char s1, char s2) //判断栈顶运算符与正在读取到的运算符优先级
{
	return pri[convert(s1)][convert(s2)];
}

//读入
void readNum(char*& p, stack<float>& stk) {
	stk.push((float)(*p - '0'));
	while (isdigit(*(++p)))
		stk.push(stk.top() * 10 + (*p - '0'));
	if ('.' != *p) return;
	float fraction = 1;
	while (isdigit(*(++p)))
		stk.push(stk.top() + (*p - '0') * (fraction / 10));
}
