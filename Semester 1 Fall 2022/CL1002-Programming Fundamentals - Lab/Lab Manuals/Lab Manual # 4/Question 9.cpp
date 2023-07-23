#include <iostream>
using namespace std;
int main()
{
	int i;// to control number of rows
	int x=1;// to control number of rows
	
	int j=1;// to control number of columns
	int y=1;// to control number of columns
	
	cout << "Enter the height and base of the right angled triangle (height and base will be equal)" << endl;
	cin >> i;

	while(x<=i)
	{
		y = 1;
		while(y<=j)
		{
			cout << "*";
			y++;
		}
		j++;
		cout << endl;
		x++;
	}


}