#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	string line;
	fstream st;
	st.open("file.txt", ios::in);
	getline(st, line);
	cout << line;
	cout << endl;
	getline(st, line);
	cout << line;
	cout << endl;
	getline(st, line);
	cout << line;
	st.close();
}