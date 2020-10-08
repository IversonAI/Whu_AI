
#include <iostream>
#include <cmath>
#include <stack>

using namespace std;



#define N_OPTR 9

bool paren(const char exp[], int lo, int hi);//����ƥ��
float evaluate(char* s);//���ʽ��ֵ
float calcu(float popnd);//���ż���
float calcu(float op1, char op, float op2);
char orderBetween(char s1, char s2);//���ȼ��ж�
void readNum(char*& p, stack<float>& stk);//����
// void append( char *&rpn, float opnd);//����
// void append( char *&rpn, char optr);


//���ȼ���
typedef enum {   //ͨ��ö�ٸ�ÿһ�������һ�����
	ADD, SUB, MUL, DIV, POW, FAC, L_P, R_P, EOE
} Operator;
const char pri[N_OPTR][N_OPTR] =          //��������ȼ���
{
	/*              |-------------------- �� ǰ �� �� �� --------------------| */
	/*              +      -      *      /      ^      !      (      )      \0 */
	/* --  + */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
	/* |   - */    '>',   '>',   '<',   '<',   '<',   '<',   '<',   '>',   '>',
	/* ջ  * */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
	/* ��  / */    '>',   '>',   '>',   '>',   '<',   '<',   '<',   '>',   '>',
	/* ��  ^ */    '>',   '>',   '>',   '>',   '>',   '<',   '<',   '>',   '>',
	/* ��  ! */    '>',   '>',   '>',   '>',   '>',   '>',   ' ',   '>',   '>',
	/* ��  ( */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   '=',   ' ',
	/* |   ) */    ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',   ' ',
	/* -- \0 */    '<',   '<',   '<',   '<',   '<',   '<',   '<',   ' ',   '='

};

//�����ת��Ϊ���ű�־
Operator convert(char s) //����ö������
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
	
	//���Ա��ʽ��ֵ
	char s[] = "(1+3)*2^3";
	//char *RPN ;
	cout << evaluate(s);
	system("pause");

}

//����ת��_ʮ����������n��base���Ƶ�ת��
void convert(stack<char>& S, __int64 n, int base) {
	static char digit[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	if (0 < n) {
		S.push(digit[n % base]);
		convert(S, n / base, base);
	}
}
//���ʽ��ֵ
/*Windows DOS���м������
* C:\Users\DingYandong>set /a ((0+(1+23)/4*5*67-8+9))
* 2011
*/

//�Ա��ʽS��ֵ��ת��Ϊ�沨�����ʽ
float evaluate(char* s)//
{
	stack<float> opnd;//������ջ
	stack<float> optr;//�����ջ
	optr.push('\0'); //�����/0�����ַ���ĩβ��/0����Ӧ
	while (!optr.empty())
	{
		if (isdigit(*s))
		{
			readNum(s, opnd); //append(RPN, opnd.top());
		}
		else
		{
			switch (orderBetween(optr.top(), *s)) //��ͬ���ȼ�����
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
//���㺯��(1)_һԪ����
float calcu(float popnd) {
	if (popnd == 1) return 1;
	return calcu(popnd) * calcu(popnd - 1);
}
//���㺯��(2)_��Ԫ����
float calcu(float op1, char op, float op2) {
	switch (op) {
	case '+': return (op1 + op2);  break;
	case '-': return (op1 - op2); break;
	case '*': return (op1 * op2); break;
	case '/': return (op1 / op2); break;
	case '^': return (pow(op1, op2)); break;
	default: exit(-1); break; //���ʽ����ֱ�ӷ����쳣
	}

}

//���ȼ��Ƚ�
char orderBetween(char s1, char s2) //�ж�ջ������������ڶ�ȡ������������ȼ�
{
	return pri[convert(s1)][convert(s2)];
}

//����
void readNum(char*& p, stack<float>& stk) {
	stk.push((float)(*p - '0'));
	while (isdigit(*(++p)))
		stk.push(stk.top() * 10 + (*p - '0'));
	if ('.' != *p) return;
	float fraction = 1;
	while (isdigit(*(++p)))
		stk.push(stk.top() + (*p - '0') * (fraction / 10));
}
