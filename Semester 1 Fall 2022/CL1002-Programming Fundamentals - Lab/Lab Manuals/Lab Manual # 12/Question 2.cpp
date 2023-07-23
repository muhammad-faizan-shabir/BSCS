#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream out_stream;
	out_stream.open("FileForQ2.txt");
	out_stream<<"hello world";
	out_stream.close();
	cout << "'hello world' has been written in the file named 'file'";
	cout << endl << endl;
}
