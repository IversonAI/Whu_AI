//#include <iostream>
//#include <fstream>
//#include <cstring>
//#define MAXLEN 30
//
//
//using namespace std;
//
//
///*
//@param
//	start ��Χ-��ʼ
//	end ��Χ-��ֹ
//	PrimerNumCounts ��������
//@return
//	result[] ����һά����
//@explain
//	���������ݷ�Χ[start,end]����ȡ�м����е������������������������һά������
//	*/
//int *getPrimerNumber(int start, int end, int *PrimerNumCounts)
//{
//	int NumCounts = 0;
//	bool IsPrimerNum = true;//�ж�����Ϊ��
//	int *result = new int[1];//�½����飬����һ����
//	result[0] = 0;//��ʼ��Ϊ0
//	for (int i = start; i <= end; i++)
//	{
//		IsPrimerNum = true;
//		for (int j = 2; j < i; j++)
//			if (i%j == 0)
//			{
//				IsPrimerNum = false;
//				break;
//			}
//		//���������
//		if (IsPrimerNum == true)
//		{
//			NumCounts++;
//			if (NumCounts == 1) result[0] = i;
//			else
//			{
//				//��̬��������
//					//1.�������е�����
//					//1.1�����м�����
//				int *arr = new int[NumCounts];
//				//1.2�м����鸳��ֵ
//				for (int i = 0; i < NumCounts; i++)
//					arr[i] = 0;
//				//1.3����
//				for (int i = 0; i < NumCounts - 1; i++)
//					arr[i] = result[i];
//
//				//2.��Ŀ����������
//				//2.1����ԭ����result�ڴ�
//				delete[]result;
//				//2.2�����µ��ڴ�
//				result = new int[NumCounts];
//				//2.3�µ����鸳��ֵ
//				for (int i = 0; i < NumCounts; i++)
//					result[i] = 0;
//
//				//3��ֵԭ�������ݵ����ݺ������
//				//3.1��һ����
//				for (int i = 0; i < NumCounts - 1; i++)
//					result[i] = arr[i];
//				//3.2�����м������ڴ�
//				delete[]arr;
//
//				result[NumCounts - 1] = i;
//			}
//		}
//	}
//	(*PrimerNumCounts) = NumCounts;
//	return result;
//}
//
///*
//	@param
//		filename �ļ���
//		word_counts ��������
//	@return
//		result[][] ���ʶ�ά����
//	@explain
//		���������ζ�ȡ�ļ���ÿ���ַ�����ȡ���ʣ��������е��ʴ���ڶ�ά�����У���ά���������Ϊ������,����ΪMAXLEN
//		*/
//char **getWordsFromTxt(string filename, int *wordcounts)
//{
//	bool IsNewWord = false;//�������ַ�����һ����Ϊ�ַ�������Ϊ�������µĵ���
//	char c;//���ļ�ʱ��ȡ���ַ�
//	int WordCounts = 1;//���е��ʵ�������Ҳ���µ��ʵ��±�+1
//	int WordLen = 0;//��ǰ���ʵĳ��ȼ�һ��Ҳ���µ��ʵ����ַ����±�
//
//	//���岢�����ά����Ϊһ������
//	char **result = new char*[1];
//	for (int i = 0; i < 1; i++)
//		result[i] = new char[MAXLEN];
//	//����ά���鸳��ֵ
//	for (int i = 0; i < 1; i++)
//		for (int j = 0; j < MAXLEN; j++)
//			result[i][j] = '\0';
//
//	fstream inFile;
//	inFile.open(filename);
//	if (!inFile.is_open()) {
//		cout << "Could not find the file\n";
//		cout << "Program terminating\n";
//		exit(EXIT_FAILURE);
//	}
//
//	inFile.unsetf(ios::skipws);//ȡ��inflie���������հ׵�Ĭ������
//	while (!inFile.eof())
//	{
//		if (inFile.good())//�жϵ�ǰ���Ƿ�����
//		{
//			inFile >> c;//��ȡ�ַ�
//			if (((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z')) && IsNewWord == false)
//			{
//				result[WordCounts - 1][WordLen++] = c;
//			}
//			else if (((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z')) && IsNewWord != false)
//			{
//				WordCounts++;//��������һ
//				WordLen = 0;//�������¸�ֵΪ0
//				//1.������������
//				//1.1�����м�����
//				char **cur_arr = new char *[WordCounts];
//				for (int i = 0; i < WordCounts; i++)
//				{
//					cur_arr[i] = new char[MAXLEN];
//				}
//				//1.2�м����鸳��ֵ
//				for (int i = 0; i < WordCounts; i++)
//					for (int j = 0; j < MAXLEN; j++)
//						cur_arr[i][j] = '\0';
//				//1.3����
//				for (int i = 0; i < WordCounts - 1; i++)
//					for (int j = 0; j < MAXLEN; j++)
//						if (result[i][j] != '\0')
//							cur_arr[i][j] = result[i][j];
//				//2��Ŀ����������
//				//2.1����ԭ����result�ڴ�
//				for (int i = 0; i < WordCounts - 1; i++)
//					delete[]result[i];
//				delete[]result;
//				//2.2�����Ե��ڴ�
//				result = new char *[WordCounts];
//				for (int i = 0; i < WordCounts; i++)
//					result[i] = new char[MAXLEN];
//				//2.3�µ����鸳��ֵ
//				for (int i = 0; i < WordCounts; i++)
//					for (int j = 0; j < MAXLEN; j++)
//						result[i][j] = '\0';
//				//3.����ԭ�������ݵ����ݺ������
//				//3.1��һ����
//				for (int i = 0; i < WordCounts - 1; i++)
//					for (int j = 0; j < MAXLEN; j++)
//						if (cur_arr[i][j] != '\0')
//							result[i][j] = cur_arr[i][j];
//				//3.2�����м�������ڴ�
//				for (int i = 0; i < WordCounts; i++)
//					delete[] cur_arr[i];
//				//�����µ��ʵĵ�һ���ַ�
//				result[WordCounts - 1][WordLen++] = c;
//			}
//			if (!((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z')))
//				IsNewWord = true;
//			else
//			{
//				IsNewWord = false;
//			}
//		}
//
//	}
//	(*wordcounts) = WordCounts;
//	return result;
//}
//
//int main()
//{
//	int start, end;
//	int WordCounts = 0;
//	int PrimerNumCounts = 0;
//	int *t = &PrimerNumCounts;
//	int *p = &WordCounts;
//	string filename = "test.txt";
//
//	//��������յ�
//	cout << "��������㣨����2����";
//	cin >> start;
//	cout << "�������յ㣺";
//	cin >> end;
//
//	//�����ά�������ֵ����ȡ��������
//	char **allWords = getWordsFromTxt(filename, p);
//	//����һά���鲢��ֵ����ȡ��������
//	int *PrimerNum = getPrimerNumber(start, end, t);
//	//�����������
//	cout << "������������Ϊ:";
//	for (int i = 0; i < PrimerNumCounts; i++)
//	{
//		cout << PrimerNum[i] << " ";
//	}
//	cout << endl;
//	//�����������
//	cout << "��ȡ�ı���ȡ��������Ϊ:" << endl;
//	for (int i = 0; i < WordCounts; i++)
//	{
//		for (int j = 0; j < MAXLEN; j++)
//			if (allWords[i][j] != '\0')
//			cout << allWords[i][j];
//		cout << " ";
//	}
//	system("pause");
//	return 0;
//}
//
//
