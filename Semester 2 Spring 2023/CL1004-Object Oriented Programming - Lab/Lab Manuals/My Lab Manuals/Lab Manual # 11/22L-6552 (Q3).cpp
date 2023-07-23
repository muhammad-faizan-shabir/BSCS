#include<iostream>
using namespace std;

template<class T>
T increment(T num)
{
	num = num + 1;
	return num;
}

template<>
char* increment<char*>(char* arr)
{
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if ((arr[i] >= 97) && (arr[i] <= 122))
		{
			arr[i] = arr[i] - 32;
		}
	}
	return arr;
}

int main()
{
	cout << "Passing an integer to increment() function" << endl;
	cout << "Integer value before passing: " << 5 << endl;
	cout << "Integer value after  passing: " << increment(5) << endl << endl;

	char arr[6] = { 'a', 'B','c','d','E','\0' };
	cout << "Passing a character array to increment() function" << endl;
	cout << "Character array before passing: " << arr << endl;
	cout << "Character array after  passing: " << increment(arr) << endl;
	cout << endl;
	system("pause");
}