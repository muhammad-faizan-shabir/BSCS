#include <iostream>
using namespace std;
void main()
{
	int num;
	
	int* ptr;
	ptr = new int;
	*ptr = 10;

	delete ptr;
	// now ptr is a dangling pointer
	
	*ptr = 10; // this will cause issues even though some compilers won't give an error 

	//solution to a dangling pointer
	ptr = 0; // not recommend // The memory is occupied by 0
	//or
	ptr = nullptr; // recommened // The memory is not occupied at all, it is empty
	//or
	ptr = NULL; // recommened // The memory is not occupied at all, it is empty

	// NULL or nullptr also represents a 0. But a 0 does not reperesent a NULL or nullptr
}