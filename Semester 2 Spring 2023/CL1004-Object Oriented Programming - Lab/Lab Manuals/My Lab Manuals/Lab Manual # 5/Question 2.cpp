#include <iostream>
using namespace std;

class MyBigInt 
{
	int* big_int;
	int int_length;
public:
	MyBigInt()
	{
		big_int = nullptr;
		int_length = 1;
	}

	MyBigInt(int size)
	{
		int temp = size;
		int i;
		for(i=0;temp>0;i++)
		{
			temp = temp / 10;
		}
		
		int_length = i;
		big_int = new int[int_length];
		
		temp = size;
		for(int j=(int_length-1);j>=0;j--)
		{
			big_int[j] = temp % 10;
			temp = temp / 10;
		}
	}
	
	MyBigInt(const MyBigInt&obj)
	{
		cout << "Copy Constructor Called" << endl;
	
		int_length = obj.int_length;
		
		if(obj.big_int==nullptr)
		{
			big_int = nullptr;
		}
		else
		{
			big_int = new int[int_length];
		}
	}

	void assign(const MyBigInt& obj)
	{
		for (int i = 0; i < int_length; i++)
		{
			big_int[i] = obj.big_int[i];
		}
	}

	void display()
	{
		if (big_int == nullptr)
		{
			cout << "No Value Assigned";
		}
		else
		{
			for (int i = 0; i < int_length; i++)
			{
				cout << big_int[i];
			}
		}
	}

	~MyBigInt()
	{
		if(big_int!=nullptr)
		{
			delete[] big_int;
			big_int = nullptr;
		}
	}
};

int main()
{
	cout << "obj1 created" << endl << endl;
	MyBigInt obj1; // this will call default constructor (non-parameterized)
	
	cout << "obj2 created" << endl << endl;
	MyBigInt obj2(875964231); // this will call the overloaded constructor (parameterized)
	
	cout << "obj3 created" << endl;
	MyBigInt obj3 = obj2; // this will call the copy constructor
	cout << endl;

	cout << "Copying integer value of obj2 into obj3" << endl << endl;
	obj3.assign(obj2); // this will call assign function of obj3
	
	cout << "Displaying obj1: " << endl;
	obj1.display(); // this will call display function of obj1
	cout << endl << endl;
	
	cout << "Displaying obj2: " << endl;
	obj2.display(); // this will call display function of obj2
	cout << endl << endl;
	
	cout << "Displaying obj3: " << endl;
	obj3.display(); // this will call display function of obj3
	cout << endl << endl;

	system("pause");
}