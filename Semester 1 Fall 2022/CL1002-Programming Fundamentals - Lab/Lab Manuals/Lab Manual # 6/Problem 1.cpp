#include <iostream>
using namespace std;
int main()
{
	long long int num;
	int temp;
	int zerocount = 0;
	int onecount = 0;
	int twocount = 0;
	int threecount = 0;
	int fourcount = 0;
	int fivecount = 0;
	int sixcount = 0;
	int sevencount = 0;
	int eightcount = 0;
	int ninecount = 0;

	cout << "Enter an integer" << endl;
	cin >> num;

	for(;num>0;num=num/10)
	{
		temp = num % 10;
		
		switch(temp)
		{
		case 0:
			zerocount++;
			break;
		case 1:
			onecount++;
			break;
		case 2:
			twocount++;
			break;
		case 3:
			threecount++;
			break;
		case 4:
			fourcount++;
			break;
		case 5:
			fivecount++;
			break;
		case 6:
			sixcount++;
			break;
		case 7:
			sevencount++;
			break;
		case 8:
			eightcount++;
			break;
		case 9:
			ninecount++;
			break;

		}
	}
	if(zerocount>0)
	{
		cout << "There are " << zerocount << " zero digit(s)" << endl;
	}
	if(onecount>0)
	{
		cout << "There are " << onecount << " one digit(s)" << endl;
	}
	if (twocount > 0)
	{
		cout << "There are " << twocount << " two digit(s)" << endl;
	}
	if (threecount > 0)
	{
		cout << "There are " << threecount << " three digit(s)" << endl;
	}
	if (fourcount > 0)
	{
		cout << "There are " << fourcount << " four digit(s)" << endl;
	}
	if (fivecount > 0)
	{
		cout << "There are " << fivecount << " five digit(s)" << endl;
	}
	if (sixcount > 0)
	{
		cout << "There are " << sixcount << " six digit(s)" << endl;
	}
	if (sevencount > 0)
	{
		cout << "There are " << sevencount << " seven digit(s)" << endl;
	}
	if (eightcount > 0)
	{
		cout << "There are " << eightcount << " eight digit(s)" << endl;
	}
	if (ninecount > 0)
	{
		cout << "There are " << ninecount << " nine digit(s)" << endl;
	}
}