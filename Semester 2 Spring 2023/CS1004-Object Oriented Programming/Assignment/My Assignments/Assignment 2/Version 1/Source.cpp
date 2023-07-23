#include<iostream> 
using namespace std;

class MyString
{
	//You can add your code here 
private:
	char* str;
	int length; //including the null char here 
	//Add GetStringFromBuffer as private member (helper) 
	//Add Concatenate as private member (helper) 
	//You can add your class members here 
	char* SubString;

public:
	//-------------DO_NOT_CHANGE REGION starts below--------------------- 
	//Do not change the prototypes given below 

	MyString operator+(const MyString& obj)
	{
		MyString temp;
		int j = 0;
		for (int i = 0; i < length - 1; i++)
		{
			temp.str[j] = str[i];
			j++;
		}

		for (int i = 0; i < obj.length; i++)
		{
			temp.str[j] = obj.str[i];
			j++;
		}
		temp.length = strlen(temp.str) + 1;
		return temp;
	}

	MyString& operator=(const MyString& obj)
	{
		if (&str == (&(obj.str)))
		{
			return *this;
		}
		else
		{
			delete[]str;
			length = obj.length;
			str = new char[100];
			for (int i = 0; i < length; i++)
			{
				str[i] = obj.str[i];
			}
			return *this;
		}
	}

	bool operator<(MyString obj) //Comparison on the basis of ascii values 
	{
		int val1 = 0;
		int val2 = 0;

		for (int i = 0; i < length - 1; i++)
		{
			val1 = val1 + str[i];
		}

		for (int i = 0; i < obj.length - 1; i++)
		{
			val2 = val2 + obj.str[i];
		}

		if (val1 < val2)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	//-------------End of DO_NOT_CHANGE REGION---------------------
	//Add your class members here 

	MyString()
	{
		str = new char[100];
		str[0] = '\0';
		length = 1;
		SubString = nullptr;
	}

	MyString(const MyString& obj)
	{
		length = obj.length;
		SubString = nullptr;
		str = new char[100];
		for (int i = 0; i < length; i++)
		{
			str[i] = obj.str[i];
		}
	}

	bool operator!()
	{
		if (str[0] == '\0')
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	friend ostream& operator<<(ostream& strm, const MyString& obj)
	{
		strm << obj.str;
		return strm;
	}

	friend istream& operator>>(istream& strm, MyString& obj)
	{
		strm.getline(obj.str, 100);
		obj.length = strlen(obj.str) + 1;
		return strm;
	}

	char& operator[](int i)
	{
		if (i > (length - 2))
		{
			cout << "Array Out of Bound" << endl;
		}
		return str[i];
	}

	char* operator()(int x, int y)
	{
		SubString = new char[100];
		int j = 0;
		int i;
		if (x + y > length - 1)
		{
			for (i = x; i < length - 1; i++)
			{
				SubString[j] = str[i];
				j++;
			}
			SubString[j] = '\0';
			return SubString;
		}
		else
		{
			for (int i = x; i < x + y; i++)
			{
				SubString[j] = str[i];
				j++;
			}
			SubString[j] = '\0';
			return SubString;
		}
	}

	~MyString()
	{
		delete[] str;
		if (SubString != nullptr)
		{
			delete[] SubString;
		}
	}
};

//--------------------------Add your code here----------------------

//-------------DO_NOT_CHANGE REGION starts below---------------------

void main()
{
	MyString str1, str2, str3, str4; //Default constructor will make a string of lenght 1 having null character only i.e. empty string 

	if (!str1)
	{
		cout << "String 1 is Empty.\n";
		cout << "Str 1 = " << str1 << endl << endl << endl;
	}

	cout << "Enter String 1:\t";
	cin >> str1;

	cout << "Enter String 2:\t";
	cin >> str2;

	cout << "\n\n\nUser Entered:\n";
	cout << "String 1 = " << str1 << endl;
	cout << "String 2 = " << str2 << endl << endl << endl;

	//What is following code testing? 
	cout << "Before str1 = str1; str1 = " << str1 << endl;
	str1 = str1;
	cout << "After str1 = str1, str1 = " << str1 << endl << endl << endl;

	cout << "Before str4 = str3 = str1+str2\n";
	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;

	str4 = str3 = str1 + str2;

	cout << "\n\n\nAfter str4 = str3 = str1+str2\n";
	cout << "str1 = " << str1 << endl;
	cout << "str2 = " << str2 << endl;
	cout << "str3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;

	cout << "\n\n\nEnter String 3:\t";
	cin >> str3;

	cout << "\n\n\nEnter String 4:\t";
	cin >> str4;

	cout << "\n\n\nstr3 = " << str3 << endl;
	cout << "str4 = " << str4 << endl;

	if (str3 < str4)
		cout << "String 3 is Less than String 4.\n";
	else
		cout << "String 3 is NOT Less than String 4.\n";

	MyString str5 = str1 + str2;
	cout << "\n\n\nStr5:\t" << str5 << endl;
	cout << "Str5[7]:\t" << str5[7] << endl; //Function Call: str5.operator[](7). 
	str5[7] = '$';

	cout << "\n\nStr5:\t" << str5 << endl;

	cout << "\n\n\nstr5(5, 10):\t" << str5(5, 10) << endl;// Substring of lenght 10 
	//starting from index 5 . Function Call str5.operator()(5,10) Let the returned MyString or char* leak 

	system("pause");
}
//-------------End of DO_NOT_CHANGE REGION---------------------

