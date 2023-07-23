#include <iostream>
#include <string>
using namespace std;
int main()
{
	string NAME;
	int AGE;
	string CITY;
	string COLLEGE;
	string PROFESSION;
	string ANIMAL_TYPE;
	string PET_NAME;
	
	cout << "Enter your first name: " << endl;
	cin >> NAME;

	cout << "Enter your age: " << endl;
	cin >> AGE;

	cout << "Enter name of city: " << endl;
	cin >> CITY;

	cout << "Enter name of college: " << endl;
	cin >> COLLEGE;

	cout << "Enter your profession: " << endl;
	cin >> PROFESSION;

	cout << "Enter the type of animal you have: " << endl;
	cin >> ANIMAL_TYPE;

	cout << "Enter name of your pet: " << endl;
	cin >> PET_NAME;

	cout << "There once was a person named " << NAME << " who lived in " << CITY << "." << endl;
	
	cout << "At the age of " << AGE << ", " << NAME << " went to college at " << COLLEGE << "." << endl;
	
	cout << NAME << " graduated and went to work as a " << PROFESSION << "." << endl;
	
	cout << "Then, " << NAME << " adopted a(n) " << ANIMAL_TYPE << " named " << PET_NAME << "." << endl;

	cout << "They both lived happily ever after!" << endl;



}