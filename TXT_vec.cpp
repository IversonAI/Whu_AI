// TXTrw.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//
//
//#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
	FILE *fp = fopen("aa.txt", "r+");
	if (fp == NULL)
		return -1;
	
	char buf[1024];
	vector<string> vs;
	while (fgets(buf, 1024, fp) != NULL)
	{
		vs.push_back(buf);
	}
	for (int i = 0; i < vs.size(); i++)
		cout << vs[i]<<endl;

	fclose(fp);
	return 0;
}

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ������ʾ: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�
