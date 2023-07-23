#include<iostream>
using namespace std;

class student
{
	int size;
	int* marks;
public:
	student()
	{
		size = 0;
		marks = nullptr;
	}

	student(int *arr,int SIZE)
	{
		size = SIZE;
		marks = new int[size];

		for(int i=0;i<size;i++)
		{
			marks[i] = arr[i];
		}
	}

	void scale_up()
	{
		for(int i=0;i<size;i++)
		{
			if(!(marks[i]<45))
			{
				if((marks[i]+5)<=100)
				{
					marks[i] = marks[i] + 5;
				}
			}
		}
	}

	void printInfo()
	{
		for(int i=0;i<size;i++)
		{
			cout << marks[i] << " ";
		}
	}

	~student()
	{
		if(marks!=nullptr)
		{
			delete[] marks;
			marks = nullptr;
		}
	}
};

int main()
{
	int arr[5] = {60,75,40,97,80};

	student s1(arr, 5);

	cout << "The original array: ";
	s1.printInfo();
	cout << endl << endl;
	
	s1.scale_up();

	cout << "The array after scaling up: ";
	s1.printInfo();
	cout << endl << endl;
	
	system("pause");
}