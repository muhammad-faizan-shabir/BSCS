#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	fstream st;
	st.open("file.txt", ios::out);
	st.seekp(5, ios::beg);
	st << "kkg";
	st << endl;
	st.seekp(5, ios::cur);
	st << "hello";
	st.seekg(-8, ios::end);
	st << "ok";
}
