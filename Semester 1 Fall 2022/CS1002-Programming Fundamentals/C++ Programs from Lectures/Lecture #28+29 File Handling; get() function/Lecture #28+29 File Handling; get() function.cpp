#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	char ch;
	fstream st;
	st.open("file.txt", ios::in);
	
	st.get(ch);
	while(!st.eof())
	{
		cout << ch;
		st.get(ch);
	}
	st.close();
}