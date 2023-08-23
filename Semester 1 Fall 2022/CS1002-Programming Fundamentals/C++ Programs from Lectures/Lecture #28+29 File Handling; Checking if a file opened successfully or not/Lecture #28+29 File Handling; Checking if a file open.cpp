#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	fstream st;
	st.open("file.txt",ios::out);
	
	if (!st)
	{
		cout << "Error";
	}
	else
	{
		cout << "Open";
		st.close();
	}
}