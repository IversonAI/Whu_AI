//// TXTrw.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
////
////
////#include "pch.h"
//#include <iostream>
//#include <stdlib.h>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//	FILE *fp = fopen("aa.txt", "r+");
//	if (fp == NULL)
//		return -1;
//	int lineCount = 0;
//	char buf[1024];
//	while (fgets(buf, 1024, fp) != NULL)
//	{
//		lineCount++;
//	}
//	rewind(fp);
//	string *str = new string[lineCount + 1];
//	string *pstr = str;
//
//	while (fgets(buf, 1024, fp) != NULL)
//	{
//		*pstr ++= buf;
//	}
//	for (int i = 0; i < lineCount; i++)
//		cout<< str[i];
//	
//	fclose(fp);
//	return 0;
//}
//
//// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
//// ���Գ���: F5 ����� >����ʼ���ԡ��˵�
//
//// ������ʾ: 
////   1. ʹ�ý��������Դ�������������/�����ļ�
////   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
////   3. ʹ��������ڲ鿴���������������Ϣ
////   4. ʹ�ô����б��ڲ鿴����
////   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
////   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
