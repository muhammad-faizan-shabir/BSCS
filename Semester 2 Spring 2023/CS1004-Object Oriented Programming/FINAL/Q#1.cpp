#include<iostream>
#include<string>
using namespace std;

class A
{ 
	string myString; 
public: 
	A(string str = "Default")
	{ 
		myString = str; 
	} 
	void Print()
	{ 
		cout << "Print A:\t" << myString << endl; 
	} 
};

class C
{ 
	string myString; 
public: 
	C(string str = "Default")
	{ 
		myString = str; 
	} 
	void Print()
	{ 
		cout << "Print C:\t" << myString << endl; 
	} 
};

class B : public A
{ 
	C* ptr; 
public: 
	B(string str1 = "Default", string str2 = "String 2") :A(str1)
	{ 
		ptr = new C(str2); 
	} 
	void Print()
	{ 
		A::Print(); 
		if (ptr != 0)
		{ 
			ptr->Print(); 
		} 
	} 
};

int main()
{ 
	B abc("This is ABC", "XYZ"); 
	abc.Print();
	cout << endl;
	system("pause");
	return 0;
}