#include <iostream>
using namespace std;

class Person
{
	int age;
	string name;
public:
	void setAge(int n)
	{
		age = n;
	}
	
	int getAge()
	{
		return age;
	}
};

int main()
{
	Person obj1;
	obj1.setAge(50);
	cout << obj1.getAge();
}