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
//	start 范围-起始
//	end 范围-终止
//	PrimerNumCounts 素数个数
//@return
//	result[] 素数一维数组
//@explain
//	本函数根据范围[start,end]，获取中间所有的素数，并将所有素数存放在一维数组中
//	*/
//int *getPrimerNumber(int start, int end, int *PrimerNumCounts)
//{
//	int NumCounts = 0;
//	bool IsPrimerNum = true;//判断质数为真
//	int *result = new int[1];//新建数组，包含一个数
//	result[0] = 0;//初始化为0
//	for (int i = start; i <= end; i++)
//	{
//		IsPrimerNum = true;
//		for (int j = 2; j < i; j++)
//			if (i%j == 0)
//			{
//				IsPrimerNum = false;
//				break;
//			}
//		//如果是素数
//		if (IsPrimerNum == true)
//		{
//			NumCounts++;
//			if (NumCounts == 1) result[0] = i;
//			else
//			{
//				//动态数组扩容
//					//1.备份已有的数组
//					//1.1引入中间数组
//				int *arr = new int[NumCounts];
//				//1.2中间数组赋初值
//				for (int i = 0; i < NumCounts; i++)
//					arr[i] = 0;
//				//1.3备份
//				for (int i = 0; i < NumCounts - 1; i++)
//					arr[i] = result[i];
//
//				//2.对目标数组扩容
//				//2.1回收原来的result内存
//				delete[]result;
//				//2.2分配新的内存
//				result = new int[NumCounts];
//				//2.3新的数组赋初值
//				for (int i = 0; i < NumCounts; i++)
//					result[i] = 0;
//
//				//3赋值原来的内容到扩容后的数组
//				//3.1逐一复制
//				for (int i = 0; i < NumCounts - 1; i++)
//					result[i] = arr[i];
//				//3.2回收中间数组内存
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
//		filename 文件名
//		word_counts 单词总数
//	@return
//		result[][] 单词二维数组
//	@explain
//		本函数依次读取文件的每个字符，获取单词，并将所有单词存放在二维数组中，二维数组的行数为单词数,列数为MAXLEN
//		*/
//char **getWordsFromTxt(string filename, int *wordcounts)
//{
//	bool IsNewWord = false;//连续俩字符中若一个不为字符，则认为出现了新的单词
//	char c;//读文件时获取的字符
//	int WordCounts = 1;//所有单词的数量，也是新单词的下标+1
//	int WordLen = 0;//当前单词的长度减一，也是新单词的新字符的下标
//
//	//定义并分配二维数组为一个单词
//	char **result = new char*[1];
//	for (int i = 0; i < 1; i++)
//		result[i] = new char[MAXLEN];
//	//给二维数组赋初值
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
//	inFile.unsetf(ios::skipws);//取消inflie输入跳过空白的默认设置
//	while (!inFile.eof())
//	{
//		if (inFile.good())//判断当前流是否正常
//		{
//			inFile >> c;//读取字符
//			if (((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z')) && IsNewWord == false)
//			{
//				result[WordCounts - 1][WordLen++] = c;
//			}
//			else if (((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z')) && IsNewWord != false)
//			{
//				WordCounts++;//单词数加一
//				WordLen = 0;//长度重新赋值为0
//				//1.备份已有数组
//				//1.1引入中间数组
//				char **cur_arr = new char *[WordCounts];
//				for (int i = 0; i < WordCounts; i++)
//				{
//					cur_arr[i] = new char[MAXLEN];
//				}
//				//1.2中间数组赋初值
//				for (int i = 0; i < WordCounts; i++)
//					for (int j = 0; j < MAXLEN; j++)
//						cur_arr[i][j] = '\0';
//				//1.3备份
//				for (int i = 0; i < WordCounts - 1; i++)
//					for (int j = 0; j < MAXLEN; j++)
//						if (result[i][j] != '\0')
//							cur_arr[i][j] = result[i][j];
//				//2对目标数组扩容
//				//2.1回收原来的result内存
//				for (int i = 0; i < WordCounts - 1; i++)
//					delete[]result[i];
//				delete[]result;
//				//2.2分配显得内存
//				result = new char *[WordCounts];
//				for (int i = 0; i < WordCounts; i++)
//					result[i] = new char[MAXLEN];
//				//2.3新的数组赋初值
//				for (int i = 0; i < WordCounts; i++)
//					for (int j = 0; j < MAXLEN; j++)
//						result[i][j] = '\0';
//				//3.复制原来的内容到扩容后的数组
//				//3.1逐一复制
//				for (int i = 0; i < WordCounts - 1; i++)
//					for (int j = 0; j < MAXLEN; j++)
//						if (cur_arr[i][j] != '\0')
//							result[i][j] = cur_arr[i][j];
//				//3.2回收中间数组的内存
//				for (int i = 0; i < WordCounts; i++)
//					delete[] cur_arr[i];
//				//储存新单词的第一个字符
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
//	//输入起点终点
//	cout << "请输入起点（大于2）：";
//	cin >> start;
//	cout << "请输入终点：";
//	cin >> end;
//
//	//定义二维数组兵赋值，获取单词总数
//	char **allWords = getWordsFromTxt(filename, p);
//	//定义一维数组并赋值，获取素数总数
//	int *PrimerNum = getPrimerNumber(start, end, t);
//	//输出各个素数
//	cout << "各个素数依次为:";
//	for (int i = 0; i < PrimerNumCounts; i++)
//	{
//		cout << PrimerNum[i] << " ";
//	}
//	cout << endl;
//	//输出各个单词
//	cout << "读取文本获取单词依次为:" << endl;
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
