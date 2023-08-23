#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	int i;
	fstream st;
	st.open("file.txt", ios::out);
	i = st.tellp();
	cout << i << endl;
	st << "Hello";
	i = st.tellp();
	cout << i << endl;
	st << "world";
	i = st.tellp();
	cout << i << endl;
	st << endl;
	st << endl;
	i = st.tellp();
	cout << i << endl;
	st << "hey";
	i = st.tellp();
	cout << i << endl;

}