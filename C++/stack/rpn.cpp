
#include <iostream>
#include <cmath>
#include <stack>

using namespace std;



#define N_OPTR 9

bool paren(const char exp[], int lo, int hi);//����ƥ��
double evaluate(char* s);//���ʽ��ֵ
double calcu(char op, double b);//���ż���
double calcu(double op1, char op, double op2);
char orderBetween(char s1, char s2);//���ȼ��ж�
void readNumber(char*& p, stack<double>& stk);//����



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

__int64 facI(int n) { __int64 f = 1; while (n > 1) f *= n--; return f; } //�׳����㣨�����棩

void append(char*& rpn, double opnd) { //������������RPNĩβ
	char buf[64];
	if (0.0 < opnd - (int)opnd) sprintf(buf, "%f \0", opnd); //�����ʽ����
	else                             sprintf(buf, "%d \0", (int)opnd); //������ʽ
	rpn = (char*)realloc(rpn, sizeof(char) * (strlen(rpn) + strlen(buf) + 1)); //��չ�ռ�
	strcat(rpn, buf); //RPN�ӳ�
}

void append(char*& rpn, char optr) { //�����������RPNĩβ
	int n = strlen(rpn); //RPN��ǰ���ȣ���'\0'��β������n + 1��
	rpn = (char*)realloc(rpn, sizeof(char) * (n + 3)); //��չ�ռ�
	sprintf(rpn + n, "%c ", optr); rpn[n + 2] = '\0'; //����ָ���������
}
//���ʽ��ֵ
/*Windows DOS���м������
* C:\Users\DingYandong>set /a ((0+(1+23)/4*5*67-8+9))
* 2011
*/

//�Ա��ʽS��ֵ��ת��Ϊ�沨�����ʽ

double evaluate(char* S, char*& RPN) { //�ԣ����޳��׿ո�ģ����ʽS��ֵ����ת��Ϊ�沨��ʽRPN
	stack<double> opnd; stack<char> optr; //������ջ�������ջ /*DSA*/�κ�ʱ�̣�����ÿ������Ԫ��֮�����Сһ��
	optr.push('\0'); //β�ڱ�'\0'Ҳ��Ϊͷ�ڱ�������ջ
	while (!optr.empty()) { //�������ջ�ǿ�֮ǰ�����������ʽ�и��ַ�
		if (isdigit(*S)) { //����ǰ�ַ�Ϊ����������
			readNumber(S, opnd); append(RPN, opnd.top()); //��������������������RPNĩβ
		}
		else //����ǰ�ַ�Ϊ���������
			switch (orderBetween(optr.top(), *S)) { //������ջ�������֮�����ȼ��ߵͷֱ���
			case '<': //ջ����������ȼ�����ʱ
				optr.push(*S); S++; //�����Ƴ٣���ǰ�������ջ
				break;
			case '=': //���ȼ���ȣ���ǰ�����Ϊ�����Ż���β���ڱ�'\0'��ʱ
				optr.pop(); S++; //�����Ų�������һ���ַ�
				break;
			case '>': { //ջ����������ȼ�����ʱ����ʵʩ��Ӧ�ļ��㣬�������������ջ
				char op = optr.top(); append(RPN, op); //ջ���������ջ��������RPNĩβ
				if ('!' == op) { //������һԪ�����
					double pOpnd = opnd.top(); //ֻ��ȡ��һ������������
					opnd.push(calcu(op, pOpnd)); //ʵʩһԪ���㣬�����ջ
				}
				else { //������������Ԫ�������
					double pOpnd2 = opnd.top(), pOpnd1 = opnd.top(); //ȡ����ǰ������ /*DSA*/���ʣ��ɷ�ʡȥ������ʱ������
					opnd.push(calcu(pOpnd1, op, pOpnd2)); //ʵʩ��Ԫ���㣬�����ջ
				}
				break;
			}
			default: exit(-1); //���﷨���󣬲�������ֱ���˳�
			}//switch

	}//while
	return opnd.top(); //�������������ļ�����
}
double calcu(double a, char op, double b) { //ִ�ж�Ԫ����
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': if (0 == b) exit(-1); return a / b; //ע�⣺����и�����Ϊ����ܲ���ȫ
	case '^': return pow(a, b);
	default: exit(-1);
	}
}

double calcu(char op, double b) { //ִ��һԪ����
	switch (op) {
	case '!': return (double)facI((int)b); //Ŀǰ���н׳ˣ����մ˷�ʽ���
	default: exit(-1);
	}
}

//���ȼ��Ƚ�
char orderBetween(char s1, char s2) //�ж�ջ������������ڶ�ȡ������������ȼ�
{
	return pri[convert(s1)][convert(s2)];
}

//����
void readNumber(char*& p, stack<double>& stk) { //����ʼ��p���Ӵ�����Ϊ��ֵ�������������ջ
	stk.push((double)(*p - '0')); //��ǰ��λ��Ӧ����ֵ��ջ
	while (isdigit(*(++p))) //ֻҪ�������н��ڵ����֣�����λ���������������
		stk.push(stk.top() * 10 + (*p - '0')); //����ԭ��������׷������λ������ֵ������ջ
	if ('.' != *p) return; //�˺��С���㣬����ζ�ŵ�ǰ�������������
	float fraction = 1; //������ζ�Ż���С������
	while (isdigit(*(++p))) //��λ����
		stk.push(stk.top() + (*p - '0') * (fraction /= 10)); //С������
}

int main() {

	//���Ա��ʽ��ֵ
	char s[] = "(1+3)*2";
	char* rpn = (char*)malloc(sizeof(char) * 1);   rpn[0] = '\0'; //�沨�����ʽ
	cout << evaluate(s, rpn);
	system("pause");

}