// switch or case statements
//breaking is very important
#include <iostream>
using namespace std;
int main()
{
	int i;
	cout << "Enter 1 for Paratha, 2 for egg, 3 for tea: " << endl;
	cin >> i;
	
	switch(i)
	{
	case 1:
		cout << "Paratha ordered" << endl;
		break; //breaking is very important
	case 2:
		cout << "Egg ordered" << endl;
		break; //breaking is very important
	case 3:
		cout << "Tea ordered" << endl;
		break; //breaking is very important
	default:
		cout << "wrong selection" << endl;
		break; //breaking is very important
	}
}