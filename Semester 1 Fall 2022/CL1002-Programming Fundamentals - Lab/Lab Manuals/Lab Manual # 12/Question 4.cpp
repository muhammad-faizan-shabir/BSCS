#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <string.h>
using namespace std;
int main()
{
	string line;
	ifstream in_stream;
	in_stream.open("FileForQ4.txt");
	getline(in_stream, line);
	in_stream.close();
	cout << "The line in the file is: " << endl;
	cout << line;
	cout << endl << endl;
}
