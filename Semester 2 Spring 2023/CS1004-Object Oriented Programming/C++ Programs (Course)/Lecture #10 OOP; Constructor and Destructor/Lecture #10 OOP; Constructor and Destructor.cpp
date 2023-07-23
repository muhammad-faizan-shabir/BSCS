#include <iostream>
using namespace std;

class AnotherClass
{
	int* arr;
	int size;
public:
	AnotherClass(int n=5)
	{
		size = n;
		arr = new int[size];
	}

	~AnotherClass()
	{
		delete[]arr;
		arr = 0;
		cout << size << endl;
	}
};

int main()
{
	AnotherClass obj1(10);
	AnotherClass obj2(15);
}