#include <iostream>
using namespace std;
int main()
{
	int n = 6, m = 7;
	cout << "a. "<< (n == 4) << endl;
	cout << "b. " << (n > 3) << endl;
	cout << "c. " << (n < 4) << endl;
	cout << "d. " << (n != 0) << endl;
	cout << "e. " << (n == 0) << endl;
	cout << "f. " << (n > 0) << endl;
	cout << "g. " << (n == m && m == 4 - 1) << endl;
	cout << "h. " << (n == 5 || m != 4) << endl;
	cout << "i. " << !(n >= 10) << endl;
	cout << "j. " << "1st expression is: " << (-1 + 4 * 6) << endl;
	cout << "k. " << "2nd expression is: " << ((35 + 5) % 7) << endl;
	cout << "l. " << "3rd expression is: " << (14 + -4 * 6 / 11) << endl;
	cout << "m. " << "4th expression is: " << (2 + 15 / 6 * 1 - 7 % 2) << endl;

	int x = 8, y = 2, z = 7;
	int result;
	
	result = y++ + z-- + ++x;
	cout << "o. " << result << endl;


}