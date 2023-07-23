#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream in_stream;
	ofstream out_stream;
	char ch;
	in_stream.open("old.txt");
	out_stream.open("new.txt");

	in_stream.get(ch);
	while(!in_stream.eof())
	{
		cout << ch;
		out_stream.put(ch);
		in_stream.get(ch);
	}

	in_stream.close();
	out_stream.close();

}