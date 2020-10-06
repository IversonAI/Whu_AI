//#include<iostream>
//#include<stack>
//#include <string.h>
//
//using namespace std;
///******************************************************************************************
// * 显示表达式片段exp[lo, hi]，与原表达式对齐
// ******************************************************************************************/
//void displaySubstring(const char exp[], int lo, int hi)
//{
//	for (int i = 0; i < lo; i++)
//		printf("	");
//	for (int i = lo; i <= hi; i++)
//		printf("%c", exp[i]);
//	printf("\n");
//}
//
///******************************************************************************************
// * 显示表达式扫描进度
// ******************************************************************************************/
//void displayProgress(const char exp[], int i, stack<char> S)
//{
//	system("cls");
//	printf("\n%s\n", exp);
//	for (int j = 0; j < i; j++)
//		printf("-");
//	printf("^\n\n\n");
//	//print(S); getchar();
//}
//
//
//
//void trim(const char exp[], int & lo, int&hi)//删除exp[lo,hi]不含括号的最长前缀、后缀
//{
//	while ((lo <= hi) && (exp[lo] != '(') && (exp[lo] != ')'))
//		lo++;
//	while ((lo <= hi) && (exp[hi] != '(') && (exp[hi] != ')'))
//		hi--;
//	//查找第一个和最后一个括号
//}
//
//int divide(const char exp[], int lo, int hi)//切分exp[lo,hi],使exp匹配仅当子表达式匹配
//{
//	int mi = lo;
//	int crc = 1;//crc为【lo,mi】范围内左右括号数目之差
//	while ((0 < crc) && (++mi < hi))//逐个检查各字符，知道左右括号数目相等或越界
//	{
//		//左右括号分别记数
//		if (exp[mi] == ')')
//			crc--;
//		if (exp[mi] == '(')
//			crc++;
//	}
//	return mi;//若mi<=hi,则为合法切分点，否则意味着局部不可能匹配
//}
//
//bool paren(const char exp[], int lo, int hi)//检查表达式exp[lo, hi]是否括号匹配（递归版）
//{
//	displaySubstring(exp, lo, hi);
//	trim(exp, lo, hi);
//	if (lo > hi)
//		return true;//清除不含括号的前缀、后缀
//	if (exp[lo] != '(')
//		return false;//首字符非左括号，则必不匹配
//	if (exp[hi] != ')')//末字符非右括号，则必不匹配
//		return false;
//
//	int mi = divide(exp, lo, hi);//确定适当的切分点
//	if (mi > hi)
//		return false;//切分点不合法，意味着局部以至整体不匹配
//	return paren(exp, lo + 1, mi - 1) && paren(exp, mi + 1, hi); //分别检查左、右子表达式
//}
//
//int main() {
//	const char *s = "(1+2)*3-(9+12/2)/3";
//	printf("\n检查：%s\n", s);
//	paren(s, 0, strlen(s) - 1) ? printf("\n%s匹配\a\n", s) : printf("\n%s不匹配\a\a\n", s);
//	getchar();
//
//	return 0;
//}