//#include<iostream>
//#include<stack>
//#include <string.h>
//
//using namespace std;
///******************************************************************************************
// * ��ʾ���ʽƬ��exp[lo, hi]����ԭ���ʽ����
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
// * ��ʾ���ʽɨ�����
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
//void trim(const char exp[], int & lo, int&hi)//ɾ��exp[lo,hi]�������ŵ��ǰ׺����׺
//{
//	while ((lo <= hi) && (exp[lo] != '(') && (exp[lo] != ')'))
//		lo++;
//	while ((lo <= hi) && (exp[hi] != '(') && (exp[hi] != ')'))
//		hi--;
//	//���ҵ�һ�������һ������
//}
//
//int divide(const char exp[], int lo, int hi)//�з�exp[lo,hi],ʹexpƥ������ӱ��ʽƥ��
//{
//	int mi = lo;
//	int crc = 1;//crcΪ��lo,mi����Χ������������Ŀ֮��
//	while ((0 < crc) && (++mi < hi))//��������ַ���֪������������Ŀ��Ȼ�Խ��
//	{
//		//�������ŷֱ����
//		if (exp[mi] == ')')
//			crc--;
//		if (exp[mi] == '(')
//			crc++;
//	}
//	return mi;//��mi<=hi,��Ϊ�Ϸ��зֵ㣬������ζ�žֲ�������ƥ��
//}
//
//bool paren(const char exp[], int lo, int hi)//�����ʽexp[lo, hi]�Ƿ�����ƥ�䣨�ݹ�棩
//{
//	displaySubstring(exp, lo, hi);
//	trim(exp, lo, hi);
//	if (lo > hi)
//		return true;//����������ŵ�ǰ׺����׺
//	if (exp[lo] != '(')
//		return false;//���ַ��������ţ���ز�ƥ��
//	if (exp[hi] != ')')//ĩ�ַ��������ţ���ز�ƥ��
//		return false;
//
//	int mi = divide(exp, lo, hi);//ȷ���ʵ����зֵ�
//	if (mi > hi)
//		return false;//�зֵ㲻�Ϸ�����ζ�žֲ��������岻ƥ��
//	return paren(exp, lo + 1, mi - 1) && paren(exp, mi + 1, hi); //�ֱ��������ӱ��ʽ
//}
//
//int main() {
//	const char *s = "(1+2)*3-(9+12/2)/3";
//	printf("\n��飺%s\n", s);
//	paren(s, 0, strlen(s) - 1) ? printf("\n%sƥ��\a\n", s) : printf("\n%s��ƥ��\a\a\n", s);
//	getchar();
//
//	return 0;
//}