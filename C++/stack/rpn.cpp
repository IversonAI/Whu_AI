
#include <iostream>
#include <cmath>
#include <stack>

using namespace std;



#define N_OPTR 9

bool paren(const char exp[], int lo, int hi);//括号匹配
double evaluate(char* s);//表达式求值
double calcu(char op, double b);//符号计算
double calcu(double op1, char op, double op2);
char orderBetween(char s1, char s2);//优先级判断
void readNumber(char*& p, stack<double>& stk);//读入



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

__int64 facI(int n) { __int64 f = 1; while (n > 1) f *= n--; return f; } //阶乘运算（迭代版）

void append(char*& rpn, double opnd) { //将操作数接至RPN末尾
	char buf[64];
	if (0.0 < opnd - (int)opnd) sprintf(buf, "%f \0", opnd); //浮点格式，或
	else                             sprintf(buf, "%d \0", (int)opnd); //整数格式
	rpn = (char*)realloc(rpn, sizeof(char) * (strlen(rpn) + strlen(buf) + 1)); //扩展空间
	strcat(rpn, buf); //RPN加长
}

void append(char*& rpn, char optr) { //将运算符接至RPN末尾
	int n = strlen(rpn); //RPN当前长度（以'\0'结尾，长度n + 1）
	rpn = (char*)realloc(rpn, sizeof(char) * (n + 3)); //扩展空间
	sprintf(rpn + n, "%c ", optr); rpn[n + 2] = '\0'; //接入指定的运算符
}
//表达式求值
/*Windows DOS运行及结果：
* C:\Users\DingYandong>set /a ((0+(1+23)/4*5*67-8+9))
* 2011
*/

//对表达式S求值，转换为逆波兰表达式

double evaluate(char* S, char*& RPN) { //对（已剔除白空格的）表达式S求值，并转换为逆波兰式RPN
	stack<double> opnd; stack<char> optr; //运算数栈、运算符栈 /*DSA*/任何时刻，其中每对相邻元素之间均大小一致
	optr.push('\0'); //尾哨兵'\0'也作为头哨兵首先入栈
	while (!optr.empty()) { //在运算符栈非空之前，逐个处理表达式中各字符
		if (isdigit(*S)) { //若当前字符为操作数，则
			readNumber(S, opnd); append(RPN, opnd.top()); //读入操作数，并将其接至RPN末尾
		}
		else //若当前字符为运算符，则
			switch (orderBetween(optr.top(), *S)) { //视其与栈顶运算符之间优先级高低分别处理
			case '<': //栈顶运算符优先级更低时
				optr.push(*S); S++; //计算推迟，当前运算符进栈
				break;
			case '=': //优先级相等（当前运算符为右括号或者尾部哨兵'\0'）时
				optr.pop(); S++; //脱括号并接收下一个字符
				break;
			case '>': { //栈顶运算符优先级更高时，可实施相应的计算，并将结果重新入栈
				char op = optr.top(); append(RPN, op); //栈顶运算符出栈并续接至RPN末尾
				if ('!' == op) { //若属于一元运算符
					double pOpnd = opnd.top(); //只需取出一个操作数，并
					opnd.push(calcu(op, pOpnd)); //实施一元计算，结果入栈
				}
				else { //对于其它（二元）运算符
					double pOpnd2 = opnd.top(), pOpnd1 = opnd.top(); //取出后、前操作数 /*DSA*/提问：可否省去两个临时变量？
					opnd.push(calcu(pOpnd1, op, pOpnd2)); //实施二元计算，结果入栈
				}
				break;
			}
			default: exit(-1); //逢语法错误，不做处理直接退出
			}//switch

	}//while
	return opnd.top(); //弹出并返回最后的计算结果
}
double calcu(double a, char op, double b) { //执行二元运算
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': if (0 == b) exit(-1); return a / b; //注意：如此判浮点数为零可能不安全
	case '^': return pow(a, b);
	default: exit(-1);
	}
}

double calcu(char op, double b) { //执行一元运算
	switch (op) {
	case '!': return (double)facI((int)b); //目前仅有阶乘，可照此方式添加
	default: exit(-1);
	}
}

//优先级比较
char orderBetween(char s1, char s2) //判断栈顶运算符与正在读取到的运算符优先级
{
	return pri[convert(s1)][convert(s2)];
}

//读入
void readNumber(char*& p, stack<double>& stk) { //将起始于p的子串解析为数值，并存入操作数栈
	stk.push((double)(*p - '0')); //当前数位对应的数值进栈
	while (isdigit(*(++p))) //只要后续还有紧邻的数字（即多位整数的情况），则
		stk.push(stk.top() * 10 + (*p - '0')); //弹出原操作数并追加新数位后，新数值重新入栈
	if ('.' != *p) return; //此后非小数点，则意味着当前操作数解析完成
	float fraction = 1; //否则，意味着还有小数部分
	while (isdigit(*(++p))) //逐位加入
		stk.push(stk.top() + (*p - '0') * (fraction /= 10)); //小数部分
}

int main() {

	//测试表达式求值
	char s[] = "(1+3)*2";
	char* rpn = (char*)malloc(sizeof(char) * 1);   rpn[0] = '\0'; //逆波兰表达式
	cout << evaluate(s, rpn);
	system("pause");

}