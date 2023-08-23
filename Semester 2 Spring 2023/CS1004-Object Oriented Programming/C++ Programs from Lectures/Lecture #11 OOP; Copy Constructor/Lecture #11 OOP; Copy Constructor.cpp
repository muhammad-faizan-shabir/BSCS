#include <iostream>
using namespace std;

class AnotherClass
{
	int* arr;
	int size;
public:
	AnotherClass(int n = 5) // constructor 
	{
		size = n;
		arr = new int[size];
	}

	AnotherClass(const AnotherClass& obj); // copy constructor

	~AnotherClass() // destructor
	{
		delete[]arr;
		arr = 0;
		cout << size << endl;
	}
};

AnotherClass::AnotherClass(const AnotherClass& obj)
{
	size = obj.size;
	
	arr = new int[size];
	for(int i=0;i<size;i++)
	{
		arr[i] = obj.arr[i];
	}
}

int main()
{
	AnotherClass obj1(10),obj2;
	
	AnotherClass obj3;

	AnotherClass obj4(obj1); // equivalent to: AnotherClass obj4=obj1;
}