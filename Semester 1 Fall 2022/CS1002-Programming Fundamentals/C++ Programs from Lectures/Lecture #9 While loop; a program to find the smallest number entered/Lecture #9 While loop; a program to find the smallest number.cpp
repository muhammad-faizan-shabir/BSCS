// finding the smallest number input
#include <iostream>
using namespace std;
int main()
{
	int n;
	int x=1;
	int num;
	int smallestSoFar;

	cout << "how many numbers" << endl;
	cin >> n;
	cout << "Enter first number"<<endl;
	cin >> num;
	smallestSoFar = num;
	while(x<=n-1)
	{
		cout << "Enter next number" << endl;
		cin >> num;
		if(smallestSoFar>num)
		{
			smallestSoFar = num;
		}
		x++;
	}
	cout << "Smallest number is:" << smallestSoFar;
}
