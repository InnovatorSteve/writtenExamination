#include <iostream>
#include<string>
using namespace std;

class A
{
public:
	static A *create();
	int funcA();
	double funcB();
	float functC();
	virtual void print();

private:
	char m_a;
	double m_b;
	float m_c;
	char *m_C;
};

int main()
{
	// int pp = sizeof(A);
	// cout << pp << "  指针大小为：" << sizeof(char*);
	string s = "teststr";
	const char *str = "123";
	s.insert(1, str);
	cout << s;
	return 0;
}