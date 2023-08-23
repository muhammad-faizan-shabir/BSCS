#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	int i;
	string line;
	fstream st;
	st.open("file.txt", ios::in);
	i = st.tellg();
	cout << i << endl;
	getline(st, line);
	cout << line;
	i = st.tellg();
	cout << i << endl;
	cout << endl;
	getline(st, line);
	cout << line;
	i = st.tellg();
	cout << i << endl;
	cout << endl;
	getline(st, line);
	cout << line;
	i = st.tellg();
	cout << i << endl;
	st.close();
}