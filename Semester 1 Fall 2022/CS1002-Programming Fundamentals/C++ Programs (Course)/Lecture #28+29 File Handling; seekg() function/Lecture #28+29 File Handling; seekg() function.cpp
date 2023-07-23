#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	string line;
	fstream st;
	st.open("file.txt", ios::in);
	st.seekg(5, ios::beg);
	getline(st, line);
	cout << line;
	cout << endl;
	st.seekg(10, ios::cur);
	getline(st, line);
	cout << line;
	cout << endl;
	st.seekg(-5, ios::end);
	getline(st, line);
	cout << line;
	st.close();

}