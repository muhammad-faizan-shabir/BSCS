#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	string line;
	ifstream in_stream;
	in_stream.open("file.txt");
	getline(in_stream, line);
	cout << line;
	cout << endl;
	getline(in_stream, line);
	cout << line;
	cout << endl;
	getline(in_stream, line);
	cout << line;
	in_stream.close();
}