 #include <iostream> 
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod,char aux_rod)
{
	if (n == 0) // base case  
	{
		return;
	}
	else // general case
	{
		towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
		cout << "Move disk " << n << " from rod " << from_rod<< " to rod " << to_rod << endl;
		towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
	}
}

int main()
{
	int n = 3;
	cout << "The steps for n = " << n << " are:" << endl;
	// A is source, B is helping rod and C is destination rod 
	towerOfHanoi(n, 'A', 'C', 'B');
	
	cout << endl;
	system("pause");
	return 0;
}

