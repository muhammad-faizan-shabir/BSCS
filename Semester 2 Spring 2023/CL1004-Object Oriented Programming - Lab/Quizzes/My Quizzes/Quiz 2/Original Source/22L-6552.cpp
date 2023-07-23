#include<iostream>
using namespace std;

class Account
{
private:
	double AccountNumber;
	double AccountBalance;
public:
	double getAccountNumber()
	{
		return AccountNumber;
	}
	double getAccountBalance()
	{
		return AccountBalance;
	}

	void setAccountNumber(double num)
	{
		AccountNumber = num;
	}

	void setAccountBalance(double num)
	{
		AccountBalance = num;
	}

	virtual void Debit(float) = 0;
	virtual void Credit(float) = 0;

	virtual void print()
	{
		cout << "Account Number is: " << AccountNumber << " and AccountBalance is: " << AccountBalance << endl;
	}

	virtual ~Account()
	{
		cout << "Destructor Account" << endl;
	}
};

class CurrentAccount :public Account
{
private:
	double ServiceCharges;
	double MinimumBalance;
public:
	CurrentAccount(double an = 0, double ab = 0)
	{
		setAccountNumber(an);
		setAccountBalance(ab);
		ServiceCharges = 5;
		MinimumBalance = 5000;
	}
	void print()
	{
		cout << "Account Number is: " << getAccountNumber() << " ,Account Balance is: " << getAccountBalance() << " ,MinimumBalance is: " << MinimumBalance << " ,Service Charges are: " << ServiceCharges << endl;

	}

	void Credit(float ab)
	{
		setAccountBalance(ab + getAccountBalance());
		cout << "Amount credited" << endl;
		if (getAccountBalance()<MinimumBalance)
		{
			setAccountBalance(getAccountBalance()-ServiceCharges);
			cout << "Service Charges will be applied because AccountBalance is less than Minimum Balance" << endl;
		}
	}

	void Debit(float amt)
	{
		int temp= amt;
		while (temp > getAccountBalance())
		{
			cout << "Ammount cannot be debited, enter amount less than " << getAccountBalance() << ": ";
			cin >> temp;
		}
		setAccountBalance(getAccountBalance() - temp);
		cout << "Amount debited" << endl;
		if (getAccountBalance()<MinimumBalance)
		{
			setAccountBalance(getAccountBalance() - ServiceCharges);
			cout << "Service Charges will be applied because AccountBalance is less than Minimum Balance" << endl;
		}
	}
	~CurrentAccount()
	{
		cout << "Destructor CurrentAcount" << endl;
	}
};

class SavingAccount : public Account
{
private:
	double InterestRate;
public:
	SavingAccount(double an = 0, double ab = 0)
	{
		setAccountNumber(an);
		setAccountBalance(ab);
		InterestRate = 5;
	}
	void print()
	{
		cout << "Account Number is: " << getAccountNumber() << " ,Account Balance is: " << getAccountBalance() << " ,Interest Rate is: " << InterestRate << endl;
	}

	void Credit(float ab)
	{
		setAccountBalance(ab + getAccountBalance());
		cout << "Amount credited" << endl;
	}

	void Debit(float amt)
	{
		int temp = amt;
		while (temp > getAccountBalance())
		{
			cout << "Ammount cannot be debited, enter amount less than " << getAccountBalance() << ": ";
			cin >> temp;
		}
		setAccountBalance(getAccountBalance() - temp);
		cout << "Amount debited" << endl;
	}
	~SavingAccount()
	{
		cout << "Destructor SavingAccount" << endl;
	}
};

int main()
{
	{
		/*Account*ptr[3];
		Account obj1;  // object of an abstract class cannot be made
		ptr[0] = &obj1;
		CurrentAccount obj2;
		ptr[1] = &obj2;
		SavingAccount obj3;
		ptr[2] = &obj3;*/
		float credit;
		float debit;
		Account*arr[2];
		
		arr[0] = new CurrentAccount(12345, 0);
		
		arr[1] = new SavingAccount(67893, 0);

		cout << "CURRENT ACCOUNT:" << endl;
		arr[0]->print();
		cout << endl;
		cout << "Enter amount to be ADDED for the CURRENT ACCOUNT: ";
		cin >> credit;
		arr[0]->Credit(credit);
		cout << endl;
		arr[0]->print();
		cout << endl;
		cout << "Enter the amount to be DEBITED from CURRENT ACCOUNT: ";
		cin >> debit;
		arr[0]->Debit(debit);
		cout << endl;
		arr[0]->print();

		cout << endl << endl;
		cout << "SAVING ACCOUNT: " << endl;
		arr[1]->print();
		cout << endl;
		cout << "Enter amount to be ADDED for the SAVING ACCOUNT: ";
		cin >> credit;
		arr[1]->Credit(credit);
		cout << endl;
		arr[1]->print();
		cout << endl;
		cout << "Enter the amount to be DEBITED from SAVING ACCOUNT: ";
		cin >> debit;
		arr[1]->Debit(debit);
		cout << endl;
		arr[1]->print();
		cout << endl;
		delete arr[0];
		delete arr[1];
	}
	cout << endl;
	system("pause");
}

