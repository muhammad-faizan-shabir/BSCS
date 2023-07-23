#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	fstream st;
	st.open("file.txt",ios::out);
	char ch;
	int x = 0;
	for(;x<10;x++)
	{
		cin >> ch;
		st.put(ch);
		st << endl;
	}
	st.close();
}
