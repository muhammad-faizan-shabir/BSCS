#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	fstream st;
	st.open("file.txt", ios::ate);
	st << "This is the fourth line.";
	st << endl;
	st << "This is the fifth line.";
	st << endl;
	st << "This is the sixth line.";
	st << endl;
	st.close();
}