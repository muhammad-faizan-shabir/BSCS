#include <iostream>
using namespace std;
int main()
{
	int CardNum; // eight digit card number
	int temp; // to store digits temporarily for summing
	int sum1=0; //to store sum of first step
	int sum2=0; // to store sum of second step
	int remainder; // to store remainder for summing in step two
	int finalSum; // to store sum from the preceding steps
	
	cout << "Enter the eight digit card number: ";
	cin >> CardNum;
	
	while(!((CardNum>9999999)&&(CardNum<=99999999))) // making sure that card number is exactly eight digits long
	{
		cout << "Please enter an eight digit number: ";
		cin >> CardNum;
	}
	
	temp = CardNum;
	for(;temp>0;temp= temp/100) // calculating sum for first step
	{
		sum1 = sum1 + (temp % 10);
	}
	

	temp = CardNum;
	temp = temp / 10;
	for(;temp>0;temp=temp/100) // calculating sum for second step
	{
		remainder = temp % 10;
		remainder = 2 * remainder;
		for(;remainder>0;remainder=remainder/10)
		{
			sum2 = sum2 + (remainder % 10);
		}
	}
	
	finalSum = sum1 + sum2; // calculating sum from preceding steps
	
	
	if((finalSum%10)==0) // checking the the card number is valid or not
	{
		cout << "Card Number is valid" << endl;
	}
	else
	{
		cout << "Card Number is Invalid" << endl;

		temp =CardNum%10; // accessing last digit/invalid check digit from the card number
		

		sum1 = sum1 - temp; // removing last digit/invalid check digit from the first sum


		// checking what could be a possible valid check digit
		if(((sum1+sum2+0)%10)==0)
		{
			cout << "Check digit could be 0 to make the number valid" << endl;
		}
		if (((sum1 + sum2 +1 ) % 10) == 0)
		{
			cout << "Check digit could be 1 to make the number valid" << endl;
		}
		if (((sum1 + sum2 + 2) % 10) == 0)
		{
			cout << "Check digit could be 2 to make the number valid" << endl;
		}
		if (((sum1 + sum2 + 3) % 10) == 0)
		{
			cout << "Check digit could be 3 to make the number valid" << endl;
		}
		if (((sum1 + sum2 +4) % 10) == 0)
		{
			cout << "Check digit could be 4 to make the number valid" << endl;
		}
		if (((sum1 + sum2 + 5) % 10) == 0)
		{
			cout << "Check digit could be 5 to make the number valid" << endl;
		}
		if (((sum1 + sum2 +6) % 10) == 0)
		{
			cout << "Check digit could be 6 to make the number valid" << endl;
		}
		if (((sum1 + sum2 +7) % 10) == 0)
		{
			cout << "Check digit could be 7 to make the number valid" << endl;
		}
		if (((sum1 + sum2 + 8) % 10) == 0)
		{
			cout << "Check digit could be 8 to make the number valid" << endl;
		}
		if (((sum1 + sum2 + 9) % 10) == 0)
		{
			cout << "Check digit could be 9 to make the number valid" << endl;
		}
		
	}
}