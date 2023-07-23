/*The following function uses reference variables as parameters. 
Rewrite the function so it uses pointers instead of 
reference variabes, and then domonstrate the funstion in a
complete program (calling function in main()).

int doSomething(int&x , int& y)
{
	int temp = x;
	x = y * 10;
	y = temp * 10;
	return x + y;
}

*/
#include <iostream>
using namespace std;

int doSomething(int* x, int* y)
{
	int temp = *x;
	*x = (* y) * 10;
	*y = temp * 10;
	return *x + *y;
}

int main()
{
	int x=1;
	int y=2;
	cout << doSomething(&x, &y) << endl;
}

