#include <iostream>
using namespace std;

class AnotherClass
{
	int* arr;
	int size;
public:
	AnotherClass(int n = 5) // constructor 
	{
		cout << "Parameterized /Non-Parameterized Constructor" << endl;
		size = n;
		arr = new int[size];
	}

	AnotherClass(const AnotherClass& obj); // copy constructor

	void operator=(const AnotherClass&obj); // overloaded operator '='

	~AnotherClass() // destructor
	{
		delete[]arr;
		arr = 0;
		cout << size << endl;
	}
};

AnotherClass::AnotherClass(const AnotherClass& obj)
{
	cout << "Copy Constructor" << endl;
	
	size = obj.size;
	arr = new int[size];
	
	for (int i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}
}

void AnotherClass::operator=(const AnotherClass&obj)
{
	cout << "Overloaded Operator '='" << endl;
	
	if(arr!=nullptr)
	{
		delete[] arr;
		arr = nullptr;
	}

	size = obj.size;
	arr = new int[size];
	
	for(int i=0;i<size;i++)
	{
		arr[i] = obj.arr[i];
	}
}

int main()
{
	AnotherClass obj1;  // Parameterized /Non-Parameterized Constructor will be called
	
	AnotherClass obj2 = obj1; // Copy Constructor will be called 
	
	AnotherClass obj3(10); // Parameterized /Non-Parameterized Constructor will be called
	
	obj1 = obj3; // Overloaded operator '=' will be called 
	//obj1.operator=(obj3);  this is equivalent to the above line
}