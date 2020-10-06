//#include<iostream>
//#include<stack>
//#include<string>
//using namespace std;
//int main()
//{
//	string s;
//	stack<int> mystack;
//	while (cin >> s)
//	{
//		string news = s;
//
//		int len = s.length();
//
//		for (int i = 0; i < len; i++)
//		{
//			//判断输入的字符，进行相应的处理
//			if (s[i] == '(')
//			{
//				mystack.push(i);
//				news[i] = ' ';
//			}
//			else if (s[i] == ')')
//			{
//				if (mystack.empty() == true)
//					news[i] = '?';
//				else
//				{
//					mystack.pop();
//					news[i] = ' ';
//				}
//			}
//			else
//				news[i] = ' ';
//		}
//		//剩下的（ 无法匹配，进行处理
//		while (!mystack.empty())
//		{
//			news[mystack.top()] = '$';
//			mystack.pop();
//		}
//		cout << s << endl << news << endl;
//	}
//
//	return 0;
//}