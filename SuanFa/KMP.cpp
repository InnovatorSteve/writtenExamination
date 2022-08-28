// #include<iostream>
// #include<string>
// #include<vector>
// using namespace std;
// 	vector<int> nextval(18);

// void getNext(string& p, vector<int>& next)
// {
// 	next[0] = -1;
// 	int i = 0, j = -1;
// 	while (i < (int)p.size() - 1)  //next[j]  如果j 位字符不匹配 next[j] 指向应该跳转的最近位置
// 	{
// 		if (j == -1 || p[i] == p[j])
// 		{
// 			++i;
// 			++j;
// 			next[i] = j;
// 			nextval[i] = i - j; 
// 		}
// 		else
// 			j = next[j];
// 	}
// }
// int KMP(string& t, string& p, vector<int>& next)
// {
// 	int i = 0;
// 	int j = 0;

// 	while (i < (int)t.size() && j < (int)p.size())
// 	{
// 		if (j == -1 || t[i] == p[j])  //j == -1 时 说明当前t[i]字符不存在 前缀子串中 跳过此字符
// 		{
// 			i++;
// 			j++;
// 		}
// 		else
// 			j = next[j];   //j跳到最近可以匹配的子串末尾 位置  减少对比次数
// 	}

// 	if (j == p.size())
// 		return i - j;
// 	else
// 		return -1;
// }

// int main() {
// 	string t = "ababaabacbcabcadabababbabca";
// 	// string p = "abababca";
// 	string p = "abacbcabcadababab";
// 	vector<int> next(p.size());
// 	getNext(p, next);
// 	cout << KMP(t, p, next) << endl;
// 	cout << endl;
// 	return 0;
// }
#include<iostream>
using namespace std;
//nextval数组
void get_nextval(string T,int* nextval)
{
	int i = -1; //指向前缀
	int j = 0; //指向后缀
	nextval[0] = -1;
	while (j < (T.length())-1)
	{
		if (i == -1 || T[i] == T[j])
		{
			i++;
			j++;
            //如果前缀字符与后缀字符不同
			if (T[i] != T[j])
			{
				//当前nextval[j]的值等于i位置的值
				nextval[j] = i;
			}
			else 
			{
				//如果前缀字符与后缀字符相同，则将前缀字符的nextval值赋值给后缀字符的nextval值
				nextval[j] = nextval[i];
			}

		}
		else 
		{
			i= nextval[i];
		}
	}
}
void test()
{
	//测试nextval数组-----------------
	string T = "ababaabacbcabcadabababbabca";
	int nextval[T.size()] = {};
	get_nextval(T, nextval);
	for (int i = 0; i < T.size(); i++)
	{
		cout << nextval[i] << "  ";
	}
}
int main()
{
	test();
	system("pause");
	return 0;
}