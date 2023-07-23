#include<iostream>
using namespace std;

class Student
{
	char*rollNo;
	int semester;
	char*name;
	float CGPA;
	char arr[10];
	char n[100];
public:

	Student()
	{
		
		rollNo = arr;
		semester = 0;
		
		name = n;
		CGPA = 0.0;
	}
	void input()
	{

		cout << "Enter details of the student" << endl;
		cout << "Enter Roll Number of the Student: ";
		cin.getline(arr, 10);
		cout << "Enter Current Semester of the student: ";
		cin >> semester;
		cout << "Enter Name of the student: ";
		cin.ignore();
		cin.getline(name, 100);
		cout << "Enter CGPA of the student: ";
		cin >> CGPA;
	}

	void output()
	{
		cout << "Roll Number: " << rollNo<< endl;
		cout << "Semester: " << semester << endl;
		cout << "Name: " << name << endl;
		cout << "CGPA: " << CGPA << endl;
	}
};

int main()
{
	Student s1;
	s1.input();
	s1.output();
	Student s2 = s1;

	s2.output();

	system("pause");

}