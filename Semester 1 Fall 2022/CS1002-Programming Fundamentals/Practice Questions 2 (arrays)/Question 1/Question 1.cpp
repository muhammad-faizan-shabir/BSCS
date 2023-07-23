#include <iostream>
using namespace std;
int main()
{
	int arr[5] = { 10,15,90,200,110 }; // array to hold some numbers
	int diff = -99999999999; // variable to hold the difference
	int tempdiff; // variable to temporarily hold the difference
	int pointer = 0; //variable to point a particular index position
	int loop = 5 - 1; // variable to determine how many times the loop will run
	int temp; // variable to tempoorarily hold an index position

	for(;pointer<5-1;pointer++) // this loop will run for the number of elements in the array
	{
		temp = pointer;
		for(int i=1;i<=loop;i++) // this loop will run for the number of differences to be calculated
		{
			temp++;
			tempdiff = arr[temp] - arr[pointer]; // calculating difference
			if(tempdiff<0) // if difference is negative then making it positive
			{
				tempdiff = tempdiff * -1;
			}

			if(tempdiff>diff) // check for the maximum difference calculated so far
			{
				diff = tempdiff;
			}
		}
		loop--; // size of the inner loop will decrease gradually
	}

	cout << "Max Difference is: " << diff; // outputting the maximum difference 
}