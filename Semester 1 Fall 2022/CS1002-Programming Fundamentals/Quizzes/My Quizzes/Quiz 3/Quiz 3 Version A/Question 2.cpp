#include <iostream>
using namespace std;
int main()
{
	int num1 = 4, num2 = 2, ans;
	int i = 1;
	while(i<=num1 && i<=num2)
	{
		if(num1%i==0 && num2%i==0)
		{
			ans = i;
		}
		i++;
	}
	cout << "Answer is: " << ans << endl;
}