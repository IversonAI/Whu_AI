#include<iostream>
#include<stack>
#include<cstdlib>
#include <string.h>
using namespace std;

//¿®∫≈∆•≈‰
bool paren(const char exp[], int lo, int hi) {
	stack<char> S;
	for (int i = lo; i < hi; i++) {
		switch (exp[i]) {
		case '{': case '(': case '[': S.push(exp[i]); break;
		case '}': if ((S.empty()) || '{' != S.top()) return false; break;
		case ')': if ((S.empty()) || '(' != S.top())  return false; break;
		case ']': if ((S.empty()) || '[' != S.top())  return false; break;
		default:break;
		}
	}
	return S.empty();
}

int main()
{
	//≤‚ ‘¿®∫≈∆•≈‰
	const char exp[] = "()()(())(";
	cout << paren(exp, 0, 9);
	system("pause");
	return 0;
}
