#include<iostream>
#include<stack>
using namespace std;


//ʮ������n��base���Ƶ�ת�����ݹ�棩
void convert(stack<char> & S, __int64 n, int base) {
	static char digit[] = //�½����µ���λ���ţ�����baseȡֵ��Χ�ʵ�����
	{ '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
	if(n>0) {//�ɵ͵��ߣ���һ�����½����¸���λ
		S.push(digit[n % base]); //��������Ӧ����λ����ջ
		convert(S,n/base,base); //n����Ϊ���base�ĳ���
	}
}
int main() {
	__int64 n = 24;
	int base = 16;
	stack<char> S;
	convert(S, n, base);//��ջ��¼ת���õ��ĸ���λ

	while (!S.empty())
	{
		printf("%c", S.top());//�������
		S.pop();
	}
	printf("\n");

	system("pause");
	return 0;
}
