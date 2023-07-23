#include <iostream>
using namespace std;
int main()
{
	int n;
	float total;
	float avg;
	
	cout << "Enter the number of values 'n' whose average is to be calculated" << endl;
	cin >> n;
	if (n > 0) 
	{
		cout << "Enter total sum of the 'n' numbers" << endl;
		cin >> total;
		avg = total / n;
		cout << "the avgerage is: " << avg << endl;

	}
	else 
	{
		cout << "Error, the value of 'n should be greater than 0'" << endl;
	}
}