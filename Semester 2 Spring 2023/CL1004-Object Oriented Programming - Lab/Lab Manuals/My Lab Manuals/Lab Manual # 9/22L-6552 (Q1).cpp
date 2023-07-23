#include<iostream>
#include<string>
using namespace std;

class person
{
protected:
	string name;
	string id;
	int age;
public:
	
	person(string firstname, string lastname,string ID, int age)
	{
		cout << "In Constructor of class Person" << endl;
		name = firstname.append(" ").append(lastname);
		id = ID;
		this->age = age;
	}
	
	void print()
	{
		cout <<"Name: "<< name << endl;
	}
	
	~person()
	{
		cout << "In Destructor of class Person" << endl;
	}
};

class student : public person
{
protected:
	double cgpa;
	string rollnum;
public:
	
	student(double cgpa, string rollnum,string firstname, string lastname,string ID, int age) :person(firstname,lastname,ID,age)
	{
		cout << "In Constructor of class Student" << endl;
		this->cgpa = cgpa;
		this->rollnum = rollnum;
	}
	
	void print()
	{
		cout << name << " is " << age << " years old, his cgpa is " << cgpa << endl;
	}

	void input()
	{
		cout << "Enter Id: ";
		cin.ignore();
		getline(cin, id);
		cout << "Enter First Name: ";
		string temp;
		string temp2;
		getline(cin, temp);
		temp2 = temp;
		cout << "Enter Last Name: ";
		getline(cin, temp);
		name = temp2.append(" ").append(temp);
		cout << "Enter CGPA: ";
		cin >> cgpa;
		cin.ignore();
		cout << "Enter roll num: ";
		getline(cin, rollnum);
		cout << "Enter age: ";
		cin >> age;
	}
	
	~student()
	{
		cout << "In Destructor of class Student" << endl;
	}
};

class undergraduate : public student
{
	string fyp_name;
public:
	undergraduate(string fyp, double cgpa, string rollnum, string firstname, string lastname,string ID,int age) :student(cgpa, rollnum,firstname, lastname,ID, age)
	{
		cout << "In Constructor of class Undegraduate" << endl;
		fyp_name = fyp;
	}
	
	void print()
	{
		cout << name << " is an undergraduate student, his cgpa is " << cgpa << " and his final year project is titled " << fyp_name << endl;
	}

	void input()
	{
		cout << "Enter final year project : ";
		getline(cin, fyp_name);
	}
	
	~undergraduate()
	{
		cout << "In Destructor of class Undergraduate" << endl;
	}
};

class graduate : public student
{
	string thesis_topic;
	string supervisor_name;
public:
	graduate(string thesis, string supervisor, double cgpa, string rollnum,string firstname, string lastname,string ID, int age) :student(cgpa, rollnum,firstname, lastname,ID, age)
	{
		cout << "In Constructor of class Graduate" << endl;
		thesis_topic = thesis;
		supervisor_name = supervisor;
	}
	
	void print()
	{
		cout << name << " is a graduate student, his cgpa is " << cgpa << " and his thesis topic is " << thesis_topic << " under supervision of " << supervisor_name << endl;
	}
	
	void input()
	{
		cout << "Enter thesis topic: ";
		getline(cin, thesis_topic);
		cout << "Enter Spervisor's name: ";
		getline(cin, supervisor_name);
	}
	
	~graduate()
	{
		cout << "In Destructor of class Graduate" << endl;
	}
};

int main()
{
	{
		undergraduate obj1("The Event Locator", 3.91, "14L-4171", "Ted", "Thompson", "1", 22);
		cout << endl << "Obj1 of class undergraduate created" << endl;
		cout << "Calling Input() function for Obj1" << endl;
		obj1.input();
		cout << "Calling print() function for Obj1" << endl;
		obj1.print();
		
		graduate obj2("Distributed Algorithms", "Dr. Kashif Zafar", 3.01, "17L-6171", "Arnold", "Gates", "2", 25);
		cout <<endl <<"Obj2 of class graduate created" << endl;
		cout << "Calling Input() function for Obj2" << endl;
		obj2.input();
		cout << "Calling print() function for Obj2" << endl;
		obj2.print();

		student*obj3 = new undergraduate("The Event Locator", 3.91, "14L-4171", "Ted", "Thompson", "1", 22);
		cout <<endl <<"Obj3 of class undergraduate created with student pointer" << endl;
		cout << "Calling input() function for Obj3" << endl;
		obj3->input();
		cout << "Calling print() function for Obj3" << endl;
		obj3->print();

		student*obj4 = new graduate("Distributed Algorithms", "Dr. Kashif Zafar", 3.01, "17L-6171", "Arnold", "Gates", "2", 25);
		cout <<endl<< "Obj4 of class graduate created with student pointer" << endl;
		cout << "Calling input() function for Obj4" << endl;
		obj4->input();
		cout << "Calling print() function for Obj4" << endl;
		obj4->print();

		person* obj5 = new undergraduate("The Event Locator", 3.91, "14L-4171", "Ted", "Thompson", "1", 22);
		cout <<endl<< "Obj5 of class undergraduate created with  person pointer" << endl;
		cout << "Calling print() function for Obj5" << endl;
		obj5->print();
		
		person*obj6 = new graduate("Distributed Algorithms", "Dr. Kashif Zafar", 3.01, "17L-6171", "Arnold", "Gates", "2", 25);
		cout <<endl<< "Obj6 of class graduate created with  person pointer" << endl;
		cout << "Calling print() function for Obj6" << endl;
		obj6->print();

		cout << endl;
		delete obj6;
		delete obj5;
		delete obj4;
		delete obj3;
	}
	cout << endl;
	system("pause");
}

