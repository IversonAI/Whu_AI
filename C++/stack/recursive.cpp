#include<iostream>
#include<stack>
using namespace std;


//十进制数n到base进制的转换（递归版）
void convert(stack<char> & S, __int64 n, int base) {
	static char digit[] = //新进制下的数位符号，可视base取值范围适当扩充
	{ '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	if(n>0) {//由低到高，逐一计算新进制下各数位
		S.push(digit[n % base]); //余数（对应的数位）入栈
		convert(S,n/base,base); //n更新为其对base的除商
	}
}
int main() {
	__int64 n = 24;
	int base = 16;
	stack<char> S;
	convert(S, n, base);//用栈记录转换得到的各数位

	while (!S.empty())
	{
		printf("%c", S.top());//逆序输出
		S.pop();
	}
	printf("\n");

	system("pause");
	return 0;
}
