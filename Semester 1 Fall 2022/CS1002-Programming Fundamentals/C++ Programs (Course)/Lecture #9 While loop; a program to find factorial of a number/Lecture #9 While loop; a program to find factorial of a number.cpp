// finding factorial of a number
#include <iostream>
using namespace std;
int main()
{
	int n;
	int fact =1 ;
	int i = 1;
	cout << "Enter a positive integer to find iots factorial" << endl;
	cin >> n;
	if(n<0)
	{
		cout << "Error! factorial for negative value not possible" << endl;
	}
	else
	{
		while(i<=n)
		{
			fact *= i;
			i++;
		}
		cout << "Factorioal is: " << fact<<endl;
	}

}