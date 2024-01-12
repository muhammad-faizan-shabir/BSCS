#include<iostream>
using namespace std;

int findSum(int num) 
{
	if(num==0) // base case
	{
		return num;
	}
	else // general case
	{
		return (num % 10) + (findSum(num / 10)); 
	}
}

int main()
{
	cout << "The sum of 12345 is: " << findSum(12345) << endl;
	cout << "The sum of 67891 is: " << findSum(67891) << endl;
	cout << "The sum of 3333 is: " << findSum(3333) << endl;
	
	cout << endl;
	system("pause");
	return 0;
}