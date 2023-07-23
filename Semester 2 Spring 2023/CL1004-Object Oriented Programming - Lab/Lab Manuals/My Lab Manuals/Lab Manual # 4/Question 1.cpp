#include <iostream>
#include <string>
using namespace std;
class Student
{
	string rollNum;
	string name;
	string cnic;
	string degree;
	string address;


public:
	void setRollNum(string rollNumber)
	{
		rollNum = rollNumber;
	}

	void setName(string Name)
	{
		name = Name;
	}

	void setCnic(string Cnic)
	{
		cnic = Cnic;
	}

	void setDegree(string Degree)
	{
		degree = Degree;
	}

	void setAddress(string Address)
	{
		address = Address;
	}
	/////////////////////////
	string getRollNum()
	{
		return rollNum;
	}

	string getName()
	{
		return name;
	
	}

	string getCnic()
	{
		return cnic;
	}

	string getDegree()
	{
		return degree;
	}

	string getAddress()
	{
		return address;
	}
	///////

	void print()
	{
		cout << "Roll num: " << rollNum << endl;
		cout << "name: " << name << endl;
		cout << "cnic: " << cnic<<endl;
		cout << "degree: " <<degree<< endl;
		cout << "address: " <<address<< endl;
		
	}

};

int main()
{
	Student student1;

	string temp;
	cout << "Enter roll number: ";
	getline(cin, temp);
	student1.setRollNum(temp);

	cout << "Enter name: ";
	getline(cin, temp);
	student1.setName(temp);

	cout << "Enter cnic: ";
	getline(cin, temp);
	student1.setCnic(temp);

	cout << "Enter degree: ";
	getline(cin, temp);
	student1.setDegree(temp);

	cout << "Enter address: ";
	getline(cin, temp);
	student1.setAddress(temp);

	student1.print();
	cout << endl;
	system("pause");
}