#include <iostream>
using namespace std;
int main()
{
	int counter =1;
	double annualInterestRate;
	double startingBalance;
	int numOfMonths;
	double amtDeposited;
	double amtWithdrawn;
	double monthlyInterest;
	int amtOfDeposits = 0;
	int amtofWithdrawls = 0;
	double totalInterest = 0;
	
	cout<<"Enter the annual interest rate: "<<endl;
	cin>>annualInterestRate;
	
	cout<<"Enter the starting balance: "<<endl;
	cin>>startingBalance;
	
	cout<<"Enter the number of months since the account was established: "<<endl;
	cin>>numOfMonths;
	
	while(counter<=numOfMonths)
	{
		cout<<"Enter the amount deposited in month "<<counter<<endl;
		cin>>amtDeposited;
		
		while(amtDeposited<0)
		{
			cout<<"Please enter a positive value for amount deposited: "<<endl;
			cin>>amtDeposited;
			
		}
		
		startingBalance = startingBalance +  amtDeposited;
		
		if(amtDeposited>0)
		{
			amtOfDeposits = amtOfDeposits +1;
		}
		
		cout<<"Enter the amount withdrawn in month "<<counter<<endl;
		cin>>amtWithdrawn;
		
		while(amtWithdrawn<0)
		{
			cout<<"Please enter a positive value for amount withdrawn "<<endl;
			cin>>amtWithdrawn;
		}
		
		startingBalance = startingBalance -  amtWithdrawn;
		
		if(amtWithdrawn>0)
		{
			amtofWithdrawls = amtofWithdrawls +1;
		}
		
		monthlyInterest= (annualInterestRate/12.0)*startingBalance;
		
		totalInterest = totalInterest + 	monthlyInterest;
		
		startingBalance = startingBalance + monthlyInterest;
		
		
		counter = counter +1;
		
	}
	
	cout<<"Your ending balance is: "<<startingBalance<<endl;
	
	cout<<"Total amount of deposits are: "<<amtOfDeposits<<endl;
	
	cout<<"Total amount of withdrawls are: "<<amtofWithdrawls<<endl;
	
	cout<<"The total interest earned is: "<<totalInterest<<endl;

		
		
	
}
		
	
