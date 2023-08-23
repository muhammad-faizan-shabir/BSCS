#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	double f = 3.14159;
	cout << "value before set precision: " <<f<< endl<<endl;
	cout << setprecision(2) << "with set precision 5 without using fixed: " << f << endl<<endl;
	cout << setprecision(9) << "with set precision 9 without using fixed: " << f << endl<<endl;
	cout << fixed << setprecision(2) << "using fixed and set precision 5: " << f << endl<<endl;
	cout << fixed << setprecision(9) << "using fixed and set precision 9: " << f << endl;
}