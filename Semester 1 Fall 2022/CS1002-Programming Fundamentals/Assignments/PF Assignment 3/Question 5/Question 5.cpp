#include <iostream>
using namespace std;
int main()
{
	int choice; // choice entered by the user

	cout << "Enter 1 for factorial of number" << endl;
	cout << "Enter 2 for nPr (number f permutations)" << endl;
	cout << "Enter 3 for nCr (Number of combination) designed in part 3" << endl;
	cout << "Enter 4 for nCr (Number of combination) designed in part 4" << endl;
	cout << "Enter 5 to exit program" << endl;

	cin >> choice;

	while(choice!=5) // loop will exit when choice entered will be 5
	{
		switch(choice)
		{
		case 1: // for factorial
		{
			long long int fact = 1;
			int num;
			cout << "Enter a positive integer to find its factorial: ";
			cin >> num;
			for (; num < 0;) // making sure that number entered for factorial is positive
			{
				cout << "Please enter a positive number, not negative: ";
				cin >> num;
			}
			for (int i = 1; i <= num; i++) // calculating factorial
			{
				fact = fact * i;
			}
			cout << "Factorial is: " << fact << endl;
			break;
		}
		case 2: // for permutations
		{
			long long int fact1 = 1;
			int n;
			cout << "Enter a positive value for n for permutations: ";
			cin >> n;
			for (; n < 0;) // making sure value of n is positive
			{
				cout << "Please enter a positive value for n for permutations, not negative: ";
				cin >> n;
			}
			for (int i = 1; i <= n; i++) // calculating factorial of n
			{
				fact1 = fact1 * i;
			}

			long long int fact2 = 1;
			int r;
			cout << "Enter a positive value for r for permutations: ";
			cin >> r;
			for (; (r < 0) || (r > n);) // making sure r is positive and not greater than n
			{
				cout << "Please enter a positive value for r which is not greater than 'n' for permutations: ";
				cin >> r;
			}

			int difference;
			difference = n - r; // calculating n-r

			for (int i = 1; i <= difference; i++) // calculating factorial of 'n-r'
			{
				fact2 = fact2 * i;
			}

			int permutations;

			permutations = fact1 / fact2; // calculating permutations

			cout << "Permutations are: " << permutations << endl;
			break; 
		} 
		case 3: // for combinations using PART 3
		{
			long long int fact1 = 1;
			int n;
			cout << "Enter a positive value for n for combinations: ";
			cin >> n;
			for (; n < 0;) // making sure value of n is positive
			{
				cout << "Please enter a positive value for n for combinations, not negative: ";
				cin >> n;
			}
			for (int i = 1; i <= n; i++) // calculating factorial of n
			{
				fact1 = fact1 * i;
			}

			long long int fact2 = 1;
			int r;
			cout << "Enter a positive value for r for combinations: ";
			cin >> r;
			for (; (r < 0) || (r > n);) // making sure r is positive and not greater than n
			{
				cout << "Please enter a positive value for r which is not greater than 'n' for combinations: ";
				cin >> r;
			}

			int difference;
			difference = n - r;

			for (int i = 1; i <= difference; i++) // calculating factorial of 'n-r'
			{
				fact2 = fact2 * i;
			}

			long long int fact3 = 1;
			for (int i = 1; i <= r; i++) // calculating factorial of r
			{
				fact3 = fact3 * i;
			}

			int combinations;
			combinations = fact1 / (fact2 * fact3); // calculating combinations

			cout << "Combinations using design in PART 3 are: " << combinations << endl;
			break;
		}
		case 4: // for combinations using PART 4
		{
			long long int fact1 = 1;
			int n;
			cout << "Enter a positive value for n for combinations: ";
			cin >> n;
			for (; n < 0;) // making sure value of n is positive
			{
				cout << "Please enter a positive value for n for combinations, not negative: ";
				cin >> n;
			}
			for (int i = 1; i <= n; i++) // calculating factorial of n
			{
				fact1 = fact1 * i;
			}

			long long int fact2 = 1;
			int r;
			cout << "Enter a positive value for r for combinations: ";
			cin >> r;
			for (; (r < 0) || (r > n);) // making sure r is positive and not greater than n
			{
				cout << "Please enter a positive value for r which is not greater than 'n' for combinations: ";
				cin >> r;
			}

			int difference;
			difference = n - r;

			for (int i = 1; i <= difference; i++) // calculating factorial of 'n-r'
			{
				fact2 = fact2 * i;
			}

			int permutations;

			permutations = fact1 / fact2; // calculating permutations

			long long int fact3 = 1;
			for (int i = 1; i <= r; i++)
			{
				fact3 = fact3 * i;
			}

			int combinations;
			combinations = permutations / fact3; // calculating combinations

			cout << "Combinations using design in PART 4 are: " << combinations << endl;
			break;
		}
		default:
		{
			cout << "Inavlid choice" << endl;
			break;
		}
        }
		cout << "Enter choice again: ";
		cin >> choice;
	}
	cout << "You EXITED the program" <<endl;

}