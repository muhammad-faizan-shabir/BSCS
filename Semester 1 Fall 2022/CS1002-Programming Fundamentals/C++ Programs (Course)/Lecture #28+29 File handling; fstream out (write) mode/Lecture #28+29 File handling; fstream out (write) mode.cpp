#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	fstream st;
	st.open("file.txt", ios::out);
	st << "This is the first line.";
	st << endl;
	st << "This is the second line.";
	st << endl;
	st << "This is the third line.";
	st.close();
}