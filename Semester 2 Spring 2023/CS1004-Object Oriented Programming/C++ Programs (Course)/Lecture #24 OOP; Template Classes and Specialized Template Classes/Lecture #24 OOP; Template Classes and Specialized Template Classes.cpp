#include<iostream>
using namespace std;

template<class T,class D>
class Test
{
	T n1;
	D n2;
public:
	Test()
	{
		cout << "Template Class" << endl;
	}
};

template<>
class Test<char,int>
{
	char n1;
	int n2;
public:
	Test()
	{
		cout << "Specialized Template Class" << endl;
	}
};

int main()
{
	Test<double, int>obj1;
	Test<double, double>obj2;
	Test<char, int>obj3;
	
	cout << endl;
	system("pause");
	return 0;
}