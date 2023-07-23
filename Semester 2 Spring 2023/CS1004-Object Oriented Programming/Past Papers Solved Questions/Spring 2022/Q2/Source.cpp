#include<iostream>
#include<string>
using namespace std;

class bankaccount
{
	string name;
	int accountNum;
	string accountType;
	int balanceAmount;
public:

	bankaccount()
	{
		name = "unassigned";
		accountNum = 0;
		accountType = "unassigned";
		balanceAmount = 0;
	}
	bankaccount(string name, int accountNum,string accountType, int balanceAmount)
	{
		this->name = name;
		this->accountNum = accountNum;
		this->accountType = accountType;
		this->balanceAmount = balanceAmount;
	}

	bankaccount(const bankaccount&obj)
	{
		name = obj.name;
		accountNum = obj.accountNum;
		accountType = obj.accountType;
		balanceAmount = obj.balanceAmount;
	}

	void depositAmount(int depositAmount)
	{
		balanceAmount = balanceAmount + depositAmount;
	}

	void withdrawl(int amount)
	{
		if ((balanceAmount - amount) >= 0)
		{
			cout << "Amount withdrawn" << endl;
			balanceAmount = balanceAmount - amount;
		}
		else
		{
			cout << "Amount can't be withdrawn, balance is: " << balanceAmount << endl;
		}
	}

	void display()
	{
		cout << "Name: " << name << endl;
		cout << "Account Number: "<<accountNum << endl;
		cout << "Account Type: " << accountType << endl;
		cout << "Balance Amount: " << balanceAmount << endl;
	}

};

int main()
{
	bankaccount obj1;
	obj1.display();
	cout << endl;

	bankaccount obj2("Faizan",420,"Savings",10000);
	obj2.display();
	cout << endl;

	obj2.depositAmount(10000);
	obj2.display();
	cout << endl;

	obj2.withdrawl(5000);
	obj2.display();
	cout << endl;

	obj2.withdrawl(20000);
	obj2.display();
	cout << endl;

	system("pause");

}