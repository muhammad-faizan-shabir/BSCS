#include <iostream>
using namespace std;
int main()
{
	float InArr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	float ResArr[9] = { 1,2,3,4,5,6,7,8,9 };

	float* const myptr = InArr;

	for(int i=0;i<9;i++)
	{
		ResArr[i] = InArr[i] + InArr[i + 1];
	}

	myptr = ResArr; // value of a constant pointer cannot be changed
	cout << endl << endl;
	system("pause");
}