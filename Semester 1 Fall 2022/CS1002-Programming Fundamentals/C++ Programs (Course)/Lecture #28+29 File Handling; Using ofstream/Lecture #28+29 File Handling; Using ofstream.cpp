#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream out_stream;
	out_stream.open("file.txt");
	out_stream << "This is the first line.";
	out_stream << endl;
	out_stream << "This is the second line.";
	out_stream << endl;
	out_stream << "This is the third line.";
	out_stream.close();

}