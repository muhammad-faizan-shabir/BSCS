#include <iostream> 
using namespace std;

void CheckPalindrome(int num)
{
	int rev = 0;
	int temp;
	temp = num;
	for (; temp > 0; temp = temp / 10)
	{
		rev = (rev * 10) + (temp % 10);
	}

	if (num == rev)
	{
		cout << "The number is palindrome" << endl;
	}
	else
	{
		cout << "The number is not palindrome" << endl;
	}
}

int main()
{
	int number;

	cout << "Enter a number to check whether it is palindrome or not: ";
	cin >> number;
	cout << endl;

	CheckPalindrome(number);
	
}